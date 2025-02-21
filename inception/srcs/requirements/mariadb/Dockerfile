FROM debian:bullseye

RUN apt update -y && \
	apt upgrade -y && \
	apt-get install -y --no-install-recommends vim mariadb-server mariadb-client && \
	rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/run/mysqld && \
	chown -R mysql:mysql /var/run/mysqld /var/lib/mysql && \
	chmod 750 /var/run/mysqld /var/lib/mysql

EXPOSE 3306

VOLUME /var/lib/mysql
RUN mkdir -p /docker-entrypoint-initdb.d/
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY conf/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]

CMD ["mysqld", "--init-file=/docker-entrypoint.sh"]
