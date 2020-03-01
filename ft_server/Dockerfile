FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get -y install nginx
RUN apt-get -y install mariadb-server
RUN apt-get -y install php7.3 php-mysql php-fpm php-cli php-mbstring
RUN apt-get -y install wget

COPY ./srcs/start.sh /var/
COPY ./srcs/mysql_setup.sql /var/
COPY ./srcs/wordpress.sql /var/
COPY ./srcs/wordpress.tgz /var/www/html/
COPY ./srcs/nginx.conf /etc/nginx/sites-available/localhost
COPY ./srcs/themes/*.tgz /var/www/html/

RUN ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/localhost

WORKDIR /var/www/html/

RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.1/phpMyAdmin-4.9.1-english.tar.gz
RUN tar xf phpMyAdmin-4.9.1-english.tar.gz && rm -rf phpMyAdmin-4.9.1-english.tar.gz
RUN mv phpMyAdmin-4.9.1-english phpmyadmin

COPY ./srcs/config.inc.php phpmyadmin

RUN tar xf ./wordpress.tgz && rm -rf wordpress.tgz
RUN chmod 755 -R wordpress

RUN mkdir ./untarthemes
RUN tar xf ./*.tgz -C ./untarthemes && rm -rf *.tgz
RUN mv ./untarthemes/* ./wordpress/wp-content/themes

RUN service mysql start && mysql -u root mysql < /var/mysql_setup.sql && mysql wordpress -u root --password=1234 < /var/wordpress.sql
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj '/C=SP/ST=MAD/L=42M/O=42/CN=royserver' -keyout /etc/ssl/certs/localhost.key -out /etc/ssl/certs/localhost.crt
RUN chown -R www-data:www-data *
RUN chmod 755 -R *

CMD bash /var/start.sh

EXPOSE 80 443

CMD service php7.3-fpm start && \
	service nginx start && \
	service mysql start && \
	sleep infinity
