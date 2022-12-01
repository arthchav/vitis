#!/bin/bash

# Le fichier doit être horodaté (année-mois-jour-heure-minutes-secondes) :
DATE="$(date +%Y-%m-%d-%H-%M-%S)"


# La sauvegarde de la base de données doit être contenue dans un seul fichier :
SAVE="/home/arthur/save_$DATE.sql"
mysqldump -u arthur classicmodels > $SAVE


# Ce fichier doit être compressé au format .bz2 :
bzip2 $SAVE


# Si la sauvegarde réussit, le script conserve uniquement les 5 fichiers de sauvegarde les plus récents :

    # Compter le nombre de sauvgardes : 
    COMBIEN=$(find -name *save_*)

    # Supprimer les fichiers plus vieux que 5 : 

    if [[ $COMBIEN -gt 5 ]] #(-gt = "greater than" = >)
    then
        ZERO=$( $COMBIEN-5 )
        
        # On boucle jusqu'à qu'il reste ZERO : 

        for OLD in $( $COMBIEN | sort | head -n $ZERO)
        do 
            rm $OLD
        done
    fi

# Les logs doivent être envoyés dans /var/log/dump-mysql.log :

LOG="/var/log/dump-mysql.log"
exec &>>$LOG

# Trouvez un outil permettant de controller le volume du fichier de log /var/log/dump-mysql.log. 

    # Taille sur le disque : 
    VOLUME=$(du $LOG) 

    # On écrit ou réécrit en fonction de la taille : 

    if [[ $VOLUME -gt 10 ]]  # Un fichier log de 10 Ko ici
    then
        echo "Fin des logs, fichier log plein - $DATE" > $LOG # Remplace 
    else
        echo "Fin des logs - $DATE" >> $LOG # Ecrit après 

    fi

exit 0
