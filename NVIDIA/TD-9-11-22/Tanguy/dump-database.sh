#!/bin/bash

LISTEDB=$( echo 'show databases' | mysql -u tanguy --password=TaNg2001@#! )   #Liste de la base de donnée
echo $LISTEDB
CHEMIN="/home/tanguy/TdBDD"     #Emplacement de la base de donnée
DATE="$(date +%Y-%m-%d-%H-%M-%S)"

ls -R $CHEMIN
echo;

for DB in $LISTEDB do;       #On sélectionne la base de données classicmodels
        if [ $DB = "classicmodels" ]; then
                echo
                mysqldump -u tanguy --single-transaction --password=TaNg2001@#! "$DB" > "$CHEMIN/${DB}_${DATE}.sql"    #Sauvegarde
        echo "Sauvegarde de la base de données $DB effectuée"
        bzip2 "$CHEMIN/${DB}_${DATE}.sql"    #Compression du fichier
        fi
done

n=1
for file in $(ls -t $CHEMIN); do
        if [ $n -gt 5]; then
                rm $file
        fi
        ((n = n + 1))
done