FROM	debian:buster

RUN apt-get -y update
RUN apt-get -y install wget

# nginx
RUN apt-get -y install nginx
RUN mkdir /var/www/server
COPY ./conf/server.com.conf /etc/nginx/sites-available/.
COPY ./conf/nginx.conf /etc/nginx/.
RUN ln -s /etc/nginx/sites-available/server.com.conf  /etc/nginx/sites-enabled/
RUN chmod -R u=rw,g=r,o=r,a+X /var/www/server
RUN chown -R www-data:www-data /var/www/server

# ssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048\
    -keyout /etc/ssl/private/nginx-selfsigned.key\
    -out /etc/ssl/certs/nginx-selfsigned.crt\
    -subj "/C=RU/ST=Tatarstan/L=Kazan/O=school21/OU=Seliverstov/CN=localhost"

# END
# EXPOSE 80
EXPOSE 443

# Start
COPY ./tools/start.sh /.
# CMD bash ./start.sh
# CMD ["nginx", "-g", "daemon off;"]
ENTRYPOINT sh ./start.sh