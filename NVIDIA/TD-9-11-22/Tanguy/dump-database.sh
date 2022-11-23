#!/bin/bash

LISTEDB=$( echo 'show databases' | mysql -u tanguy --password=TaNg2001@#! )   #Liste de la base de donnée
CHEMIN=/home/tanguy/TdBDD     #Emplacement de la base de donnée
DATE="$(date +%Y-%m-%d-%H-%M-%S)"

for DB in $LISTEDB do       #On sélectionne la base de données classicmodels
        if [ DB -e "classimodels" ]; then
                mysqldump -u tanguy --single-transaction --password= $DB > "$CHEMIN$DATE.sql"       #Sauvegarde
        echo "|Sauvegarde de la base de donnes $DB.sql dans le fichier sauvegarde_DB ";
        echo "Backup finished" >> /var/log/dump-mysql.log
        fi
done

n=1
for file in $(ls -t $CHEMIN); do
        if [ $n -gt 5]; then
                rm $file
        fi
        ((n = n + 1))

tar -cjvf archive.tar.bz2 ~$CHEMIN/
done