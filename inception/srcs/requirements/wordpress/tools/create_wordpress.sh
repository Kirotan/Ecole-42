#!/bin/sh

if [ -f /var/www/html/wp-config.php ] && wp core is-installed --path=/var/www/html --allow-root; then
	echo "WordPress déjà installé."
else
	echo "Installation de WordPress..."

	if [ ! -f /var/www/html/wp-config.php ]; then
		echo "Téléchargement de WordPress..."
		wget http://wordpress.org/latest.tar.gz
		tar -xzf latest.tar.gz
		mv wordpress/* /var/www/html/
		rm -rf wordpress latest.tar.gz

		cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php

		sed -i "s/database_name_here/${SQL_DATABASE}/g" /var/www/html/wp-config.php
		sed -i "s/username_here/${SQL_USER}/g" /var/www/html/wp-config.php
		sed -i "s/password_here/${SQL_PASSWORD}/g" /var/www/html/wp-config.php
		sed -i "s/localhost/${SQL_HOSTNAME}/g" /var/www/html/wp-config.php
	fi

	echo "Vérification que la DB est accessible..."
	for i in {1..20}; do
		if mysqladmin -h "${SQL_HOSTNAME}" -u"${SQL_USER}" -p"${SQL_PASSWORD}" ping &>/dev/null; then
			echo "Base de données disponible."
			break
		fi
		echo "En attente de la base de données..."
		sleep 3
	done

	echo "Installation de WordPress via WP-CLI..."
	cd /var/www/html || exit 1

	wp core install \
	--url="${WP_URL}" \
	--title="${WP_TITLE}" \
	--admin_user="${WP_ADMIN_USER}" \
	--admin_password="${WP_ADMIN_PASSWORD}" \
	--admin_email="${WP_ADMIN_EMAIL}" \
	--skip-email \
	--allow-root

	echo "Installation terminée !"
fi

exec "$@"
