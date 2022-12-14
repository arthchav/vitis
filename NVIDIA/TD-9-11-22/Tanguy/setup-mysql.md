# Comment installer mysql:

```shell

sudo apt update

sudo apt install mysql-server

sudo systemctl start mysql.service

sudo mysql

mysql>SELECT user,authentication_string,plugin,host FROM mysql.user;

mysql>ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'TaNg2001@#!';
```

Pour le premier mot de passe j'ai eu une erreur: MySQL ERROR 1819 (HY000): Your password does not satisfy the current policy requirements

```shell
mysql> SHOW VARIABLES LIKE 'validate_password%';

mysql>exit

sudo mysql_secure_installation
```

![image](/NVIDIA/TD-9-11-22/Tanguy/Images/mysql%20secure%20installation.png)

```shell

sudo mysql

mysql> CREATE USER 'tanguy'@'localhost' IDENTIFIED BY 'TaNg2001@#!';

mysql>GRANT SHOW DATABASES, SELECT, LOCK TABLES ON *.* TO 'tanguy'@'localhost';

mysql> FLUSH PRIVILEGES;

mysql> show databases;

mysql> exit

sudo systemctl status mysql.service

```

# Comment importer la base de données:

```shell

mkdir TdBDD

cd TdBDD

wget https://www.mysqltutorial.org/wp-content/uploads/2018/03/mysqlsampledatabase.zip

unzip mysqlsampledatabase.zip

sudo apt install bzip2

bzip2 mysqlsampledatabase.sql

unzip mysqlsampledatabase.zip

mysql -u tanguy -p < /home/TdBDD/mysqlsampledatabase.sql

mysql -u tanguy -p

Enter password:

```

```shell
mysql>show databases;
```

![image](/NVIDIA/TD-9-11-22/Tanguy/Images/databases.png)

```shell
mysql>use classicmodels;

mysql>show tables;

mysql> exit
```

![image](/NVIDIA/TD-9-11-22/Tanguy/Images/tables.png)

# Créer le script:

```shell
vim dump-database.sh
```

