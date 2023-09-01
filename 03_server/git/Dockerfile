FROM	debian:buster

RUN apt-get -y update
RUN apt-get -y install wget

# nginx
RUN apt-get -y install nginx
RUN mkdir /var/www/server
COPY ./srcs/server.com.conf /etc/nginx/sites-available/.
RUN ln -s /etc/nginx/sites-available/server.com.conf  /etc/nginx/sites-enabled/
RUN chmod -R u=rw,g=r,o=r,a+X /var/www/server
RUN chown -R www-data:www-data /var/www/server

# ssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048\
    -keyout /etc/ssl/private/nginx-selfsigned.key\
    -out /etc/ssl/certs/nginx-selfsigned.crt\
    -subj "/C=RU/ST=Tatarstan/L=Kazan/O=school21/OU=Seliverstov/CN=localhost"

# PHP
RUN apt-get -y install php php-fpm php-mysql

# Mariadb
RUN apt-get -y install software-properties-common dirmngr
RUN apt-key adv --fetch-keys 'https://mariadb.org/mariadb_release_signing_key.asc'
RUN add-apt-repository 'deb [arch=amd64,arm64,ppc64el] https://mirror.docker.ru/mariadb/repo/10.5/debian buster main'
RUN apt-get -y update
RUN apt-get -y install mariadb-server
COPY ./srcs/test_db.sql ./.
RUN service mariadb start && mysql < test_db.sql

# phpMyAdmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz
RUN tar -xzvf phpMyAdmin-5.0.4-all-languages.tar.gz
RUN mv phpMyAdmin-5.0.4-all-languages var/www/server/phpmyadmin
COPY ./srcs/config.inc.php var/www/server/phpmyadmin/.

# wordpress
WORKDIR /var/www/server
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz
RUN rm latest.tar.gz
RUN chown -R www-data:www-data /var/www/server/wordpress
WORKDIR /var/www/server/wordpress
RUN mv * ../.
WORKDIR /
RUN rm -rf /var/www/server/wordpress
COPY ./srcs/wp-config.php var/www/server/.

# END
EXPOSE 80
EXPOSE 443

# Start
COPY ./srcs/start.sh /.
CMD bash ./start.sh