FROM debian:buster
RUN apt-get update
RUN apt-get upgrade
RUN apt-get install wget nginx mariadb-server mariadb-client php7.3-fpm php7.3-mysql -y

COPY srcs/ var/www/html/
RUN mkdir /etc/nginx/ssl
RUN mkdir /etc/nginx/ssl/localhost/
RUN mv var/www/html/*.pem /etc/nginx/ssl/localhost/
RUN mv var/www/html/start.sh /home/
RUN mv var/www/html/default /etc/nginx/sites-available/
RUN chmod +x /home/start.sh
CMD bash /home/start.sh 
# && tail -F /dev/null
EXPOSE 80 443
