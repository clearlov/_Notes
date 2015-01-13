PREFIX_="/usr/local/nginx"
LOGS_"/var/log/nginx"

yum install gcc-c++ pcre-devel zlib-devel make openssl-devel

# groupadd nginx
# useradd -g nginx -s /sbin/nologin -M nginx
# mkdir -p /var/nginx
# mkdir -p /var/log/nginx16
# chmod +w /var/nginx/
# chmod +w /var/log/nginx16/
# chown -R nginx:nginx /var/nginx/
# chown -R nginx:nginx /var/log/nginx16/

./configure 
	--user=nginx 
	--group=nginx 
	--prefix=$PREFIX_
	# multiple config files inside
	--conf-path=/etc/nginx/nginx.conf
	--error-log-path=$LOGS_/error.log
	--http-log-path=$LOGS_/access.log
	# executable files' path 
	--sbin-path=$PREFIX_/sbin
	--pid-path=$LOGS_/nginx.pid
	--lock-path=$_LOGS_/lock
make
make install


vim /etc/init.d/nginx

#!/bin/bash  
#  
#chkconfig: - 85 15  
#description: Nginx
#processname: nginx  
 
nginx=/usr/local/nginx/sbin/nginx  
conf=/etc/nginx/nginx.conf 
 
case $1 in  
       start)  
              echo -n "Starting Nginx"  
              $nginx -c $conf  
              echo " done"  
       ;;  
 
       stop)  
              echo -n "Stopping Nginx"  
              killall -9 nginx  
              echo " done"  
       ;;  
 
       test)  
              $nginx -t -c $conf  
       ;;  
 
        reload)  
              echo -n "Reloading Nginx"  
              ps auxww | grep nginx | grep master | awk '{print $2}' | xargs kill -HUP  
              echo " done"  
       ;;  
 
        restart)  
                $0 stop  
                $0 start  
       ;;  
 
       show)  
              ps -aux|grep nginx  
       ;;  
 
       *)  
              echo -n "Usage: $0 {start|restart|reload|stop|test|show}"  
       ;;  
 
esac






chmod +x /etc/init.d/nginx
chkconfig --add nginx  
chkconfig nginx on

