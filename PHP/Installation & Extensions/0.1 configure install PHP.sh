# for 64bit
ln -s /usr/lib64/libltdl.so /usr/lib/libltdl.so
cp -frp /usr/lib64/libXpm.so* /usr/lib/

yum -y remove php
rpm -qa|grep php
rm -rf /usr/local/php
rm -rf /etc/php.ini


#no blanks near "=", and variable can only be named with [a-zA-Z_]
PHP_VERSION_="php-5.6.1"
MYSQL_CONF_="/etc/my.cnf"

# find / -name "my-default.cnf"
MYSQL_BASEDIR_="/usr/share/mysql"

# find / -name "performance_schema"
MYSQL_DATADIR="/var/lib/mysql"



tar zxvf $PHP_VERSION_.tar.gz
cd $PHP_VERSION_

#Linux environment variable. the file of shared lib(dll)
#export LD_LIBRARY_PATH=/usr/local/libgd/lib

# --prefix=    where to install
# --with-config-file-path=     where php.ini placed
# --with-mysqli   
# --with-pear

./configure --prefix=/usr/local/php --with-bz2 --with-curl --with-gd --with-mcrypt --with-mhash --with-mysqli --with-openssl --with-pcre-regex --with-pear --with-zlib --enable-bcmath --enable-fastcgi --enable-fpm --enable-freetype --enable-gd-native-ttf --enable-mbstring --enable-pdo --enable-sockets --enable-inline-optimization --enable-xml --enable-zip

make
make install
cp php.ini-production /etc/php.ini