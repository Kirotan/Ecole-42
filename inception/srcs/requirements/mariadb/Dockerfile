FROM debian:bullseye

RUN apt update -y && \
	apt upgrade -y && \
	apt-get install -y --no-install-recommends vim mariadb-server mariadb-client && \
	rm -rf /var/lib/app/lists/*
RUN mkdir -p /var/run/mysqld && \
	chown -R mysql:mysql /var/run/mysqld /var/lib/mysql && \
	chmod 750 /var/run/mysqld /var/lib/mysql

EXPOSE 3306

RUN mkdir -p /docker-entrypoint-initdb.d/
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY conf/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

COPY conf/init.sql /docker-entrypoint-initdb.d/init.sql
RUN chmod 644 /docker-entrypoint-initdb.d/init.sql

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]

CMD ["mysqld", "--init-file=/docker-entrypoint.sh"]
