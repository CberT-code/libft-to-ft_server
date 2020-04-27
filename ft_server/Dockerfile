# Installation Debian:BUSTER
FROM debian:buster
MAINTAINER Cbertola <mifernan@student.42.fr>

#Download all packet needed
RUN apt-get update && apt-get upgrade &&  apt-get install wget nginx mariadb-server mariadb-client php7.3-fpm php7.3-mysql -y

COPY srcs/ var/www/html/
RUN rm var/www/html/index.nginx-debian.html

#Nginx
RUN mv var/www/html/default /etc/nginx/sites-available/

#SSL
RUN mkdir /etc/nginx/ssl
RUN mkdir /etc/nginx/ssl/localhost/
RUN mv var/www/html/*.key /etc/nginx/ssl/localhost/
RUN mv var/www/html/*.crt /etc/nginx/ssl/localhost/

#ouverture des ports
EXPOSE 80 443

#BASH Service Runing + Mysql
RUN mv var/www/html/start.sh /home/
RUN chmod +x /home/start.sh

# && tail -F /dev/null
CMD bash /home/start.sh && bash
