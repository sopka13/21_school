FROM debian:buster

RUN apt-get -y update
RUN apt-get -y install wget php php-fpm php-mysql
RUN mkdir var/www
RUN cd var/www && wget https://wordpress.org/latest.tar.gz && \
    tar -xzvf latest.tar.gz && rm latest.tar.gz
RUN rm /var/www/wordpress/wp-config-sample.php
COPY ./conf/wp-config-sample.php /var/www/wordpress/wp-config.php
# COPY ./conf/wp-config-sample.php /var/tmp/wp-config.php
RUN chown -R www-data:www-data /var/www/wordpress
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d
RUN mkdir run/php && cd /run/php && touch php7.3-fpm.pid

EXPOSE 9000

COPY ./tools/start.sh .
ENTRYPOINT bash ./start.sh

# ENTRYPOINT  export $(echo -n "MYSQL_IP=" ; cat /var/ip/mysql_ip) &&\
#             php-fpm7.3 -F

# # PHP
# RUN apt-get -y install php php-fpm php-mysql

# # phpMyAdmin
# # RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz
# # RUN tar -xzvf phpMyAdmin-5.0.4-all-languages.tar.gz
# RUN mkdir /var/www
# # RUN mv phpMyAdmin-5.0.4-all-languages /var/www/phpmyadmin
# # COPY ./conf/config.inc.php var/www/phpmyadmin/.

# # wordpress
# WORKDIR /var/www
# RUN wget https://wordpress.org/latest.tar.gz
# RUN tar -xzvf latest.tar.gz
# RUN rm latest.tar.gz
# # WORKDIR /var/www/wordpress
# # RUN mv * ../.
# # WORKDIR /
# # RUN rm -rf /var/www/wordpress
# # COPY ./conf/wp-config.php var/www/server/.
# RUN rm -rf /var/www/wordpress/wp-config-sample.php
# COPY ./conf/wp-config.php /var/www/wordpress/.
# RUN chown -R www-data:www-data /var/www/wordpress
# COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d
# # COPY ./conf/php-fpm.conf /etc/php/7.3/fpm/
# WORKDIR /
# RUN mkdir /run/php
# # RUN touch /run/php/php7.3-fpm.pid

# # END
# EXPOSE 9000
# # EXPOSE 3306

# # Start
# CMD ./usr/sbin/php-fpm7.3 -F
# # WORKDIR /
# # COPY ./tools/start.sh .
# # # RUN chmod 755 start.sh
# # ENTRYPOINT sh ./start.sh