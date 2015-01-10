# vim /etc/selinux/config
#       #SELINUX=enforcing # ×¢ÊÍµô
#        #SELINUXTYPE=targeted # ×¢ÊÍµô
#        SELINUX=disabled # add
# shutdonw -r now



yum -y install gcc gcc-c++ autoconf automake zlib zlib-devel openssl openssl¨Cdevel pcre pcre-devel
ntpdate time.nist.gov
# auto start ntpd
#chkconfig ntpd on



yum -y install mariadb*
systemctl start mariadb.service
systemctl enable mariadb.service  
mysql

# sets password
mysql_secure_installation

# service mysqld start

# chkconfig --list | grep mysql*



yum -y install php php-devel php-mysql php-gd libjpeg* php-imap php-ldap php-odbc php-pear php-xml php-xmlrpc php-mbstring php-bcmath php-mhash libmcrypt libmcrypt-devel php-fpm

/etc/rc.d/init.d/php-fpm start
# auto start php-fpm
chkconfig php-fpm on

cp /etc/nginx/nginx.conf /etc/nginx/nginx.conf_20141113
user nginx nginx