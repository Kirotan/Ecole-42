FROM debian:bullseye

RUN apt update
RUN apt upgrade
RUN apt install nginx -y
RUN apt install vim -y
RUN apt install curl -y
RUN mkdir -p /etc/nginx/ssl
RUN apt install openssl -y
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=ALS/L=Mulhouse/O=42/OU=42/CN=gdoumer"
RUN mkdir -p /run/nginx

COPY conf/nginx.conf /etc/nginx/conf.d

RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

EXPOSE 4430

# CMD ["nginx", "-g", "daemon off;"]
