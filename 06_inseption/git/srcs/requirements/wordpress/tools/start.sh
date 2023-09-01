#!/bin/sh

# cp var/tmp/wp-config.php /var/www/wordpress && echo "OK" || echo "FAIL"
# echo >> var/www/wordpress/wp-config.php && echo "OK" || echo "FAIL"
S1=$(cat /var/ip/mysql_ip)
sed -i -e "s/xxxxx/$S1/g" var/www/wordpress/wp-config.php
# (echo -n "define( 'DB_HOST', '" ; echo -n $(cat /var/ip/mysql_ip) ; echo -n "' );" ) >> var/www/wordpress/wp-config.php && echo "OK" || echo "FAIL"
php-fpm7.3 -F && echo "OK" || echo "FAIL"
