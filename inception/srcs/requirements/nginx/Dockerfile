FROM debian:bullseye

RUN apt update && \
	apt upgrade -y && \
	apt install -y vim nginx openssl curl && \
	mkdir -p /etc/nginx/ssl/ /var/run/nginx && \
	openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt \
	-keyout /etc/nginx/ssl/inception.key \
	-subj "/C=FR/ST=ALS/L=Mulhouse/O=42/OU=42/CN=gdoumer.42.fr/UID=gdoumer" && \
	chmod 755 /var/www/html && \
	chown -R www-data:www-data /var/www/html

	COPY conf/nginx.conf /etc/nginx/nginx.conf.d

EXPOSE 2020

CMD ["nginx", "-g", "daemon off;"]
