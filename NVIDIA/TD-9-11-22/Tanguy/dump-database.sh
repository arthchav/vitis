#!/bin/bash

LISTEDB=$( echo 'show databases' | mysql -u tanguy --password=TaNg2001@#! )   #Liste de la base de donnée
CHEMIN="/home/tanguy/TdBDD/mysqlsampledatabase"     #Emplacement de la base de donnée
DATE="$(date +%Y-%m-%d-%H-%M-%S)"
Fichier="${CHEMIN}${DATE}}.sql"

for DB in $LISTEDB do;       #On sélectionne la base de données classicmodels
        if [ DB = "classicmodels" ]; then
                mysqldump -u tanguy --single-transaction --password= $DB > "$CHEMIN$DATE.sql"       #Sauvegarde
        echo "Sauvegarde de la base de données $DB effectuée"
        fi
done

echo "Sauvegarde" >> /var/log/dump-mysql.log

bzip2 ${Fichier}     #Compression du fichier

n=1
for file in $(ls -t $CHEMIN); do
        if [ $n -gt 5]; then
                rm $file
        fi
        ((n = n + 1))
done