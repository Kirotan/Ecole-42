#!/bin/bash
set -e

if [ ! -d "/var/lib/mysql/mysql" ]; then
	mariadb-install-db --user=mysql --datadir=/var/lib/mysql
fi

mysqld --skip-networking --socket=/var/run/mysqld/mysqld.sock &
pid="$!"

until mariadb --user=root --execute="SELECT 1;" &>/dev/null; do
	sleep 2
done

mariadb -u root <<EOSQL
CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO '${SQL_USER}'@'%';
FLUSH PRIVILEGES;
EOSQL

mysqladmin --user=root shutdown

wait "$pid"

exec mysqld
