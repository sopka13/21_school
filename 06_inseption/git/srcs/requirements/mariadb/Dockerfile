FROM	debian:buster

RUN apt-get -y update
RUN apt-get -y install wget mariadb-server mariadb-test && \
    service mysql start && \
    echo "[mysqld]" >> /etc/mysql/my.cnf && \
    # echo "bind-address=127.0.0.1" >> /etc/mysql/my.cnf && \
    echo "bind-address=0.0.0.0" >> /etc/mysql/my.cnf && \
    echo "skip-networking=0" >> /etc/mysql/my.cnf && \
    # echo "socket=/var/lib/mysql.sock" >> /etc/mysql/my.cnf && \
    echo "port=3306" >> /etc/mysql/my.cnf
    # echo "datadir=/var/lib/mysql" >> /etc/mysql/my.cnf && \
    # echo "risks" >> /etc/mysql/my.cnf && \
    # echo "symbolic-links=0" >> /etc/mysql/my.cnf && \
    # echo "[mysqld_safe]" >> /etc/mysql/my.cnf && \
    # echo "log-error=/var/log/mariadb/mariadb.log" >> /etc/mysql/my.cnf && \
    # echo "pid-file=/var/run/mariadb/mariadb.pid" >> /etc/mysql/my.cnf && \
    # echo "!includedir /etc/my.cnf.d" >> /etc/mysql/my.cnf && \
    # mkdir /etc/my.cnf.d && \
# RUN service mysql start && \
#     mysql -e "CREATE DATABASE IF NOT EXISTS ${DB_NAME};" && \
#     mysql -e "GRANT ALL ON ${DB_NAME}.* TO ${DB_USER}@localhost IDENTIFIED BY '${DB_PASSWORD}';" && \
#     mysql -e "FLUSH PRIVILEGES;" && \
#     mysql -e "ALTER USER root@localhost IDENTIFIED BY '${DB_ROOT_PASSWORD}';"
# RUN service mysql stop
# RUN mkdir /var/tmp/test
COPY ./data/test.sql .
COPY ./tools/start.sh .
# RUN sh ./start.sh

EXPOSE 3306

ENTRYPOINT sh ./start.sh

# Mariadb
# RUN apt-get -y install software-properties-common dirmngr
# RUN apt-key adv --fetch-keys 'https://mariadb.org/mariadb_release_signing_key.asc'
# RUN add-apt-repository 'deb [arch=amd64,arm64,ppc64el] https://mirror.docker.ru/mariadb/repo/10.5/debian buster main'
# RUN apt-get -y update
# RUN apt-get -y install mariadb-server
# # COPY ./conf/my.cnf /etc/mysql/my.cnf
# RUN rm /etc/mysql/mariadb.conf.d/50-server.cnf 
# COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d 
# RUN chmod +rw /etc/mysql/mariadb.conf.d/50-server.cnf
# RUN apt-get -y upgrade
# # COPY ./data/test_db.sql ./.
# # RUN service mariadb start && mysql < test_db.sql

# # END
# EXPOSE 3306

# # Start
# RUN cd /
# COPY ./tools/start.sh .
# ENTRYPOINT sh ./start.sh