#!/bin/sh


if [ ! -d /var/lib/mysql/$DB_NAME ]
then

service mysql start

# mysql --user=root <<EOF

mysql -e "CREATE DATABASE IF NOT EXISTS ${DB_NAME};" && echo "OK" || echo "FAIL"
mysql -e "CREATE USER $DB_USER@'%' IDENTIFIED BY '$DB_PASSWORD';" && echo "OK" || echo "FAIL"
mysql -e "GRANT ALL PRIVILEGES ON *.* TO $DB_USER@'%';" && echo "OK" || echo "FAIL"
mysql -u root test < /test.sql && echo "OK" || echo "FAIL"
# mysql -e "CREATE USER $DB_USER@'localhost' IDENTIFIED BY '$DB_PASSWORD';" && echo "OK" || echo "FAIL"
# mysql -e "GRANT ALL PRIVILEGES ON *.* TO $DB_USER@'localhost';" && echo "OK" || echo "FAIL"
mysql -e "FLUSH PRIVILEGES;" && echo "OK" || echo "FAIL"
mysql -e "ALTER USER root@localhost IDENTIFIED BY '${DB_ROOT_PASSWORD}';" && echo "OK" || echo "FAIL"
# EOF
# cp -r /var/tmp/test /var/lib/mysql && echo "OK" || echo "FAIL"
# service mysql stop
else

mysqld

fi

(echo -n $(hostname -i) ; echo ":3306") > var/ip/mysql_ip