FROM debian:bullseye

RUN apt-get update && \
	apt-get upgrade -y && \
	apt-get -y install \
	wget \
	curl \
	bash \
	php7.3 \
	php-cgi \
	php-mysql \
	mariadb-client \
	php-fpm \
	php-pdo \
	php-gd php-cli \
	php-mbstring \
	&& rm -rf /var/lib/apt/lists/*

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
  && chmod +x wp-cli.phar \
  && mv wp-cli.phar /usr/local/bin/wp

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/

RUN mkdir /run/php

COPY ./tools/create_wordpress.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/create_wordpress.sh
ENTRYPOINT ["/usr/local/bin/create_wordpress.sh"]

EXPOSE 9000

CMD ["php-fpm7.4", "-F"]
