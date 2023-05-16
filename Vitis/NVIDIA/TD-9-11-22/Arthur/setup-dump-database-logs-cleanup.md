### Clean les logs 

On veut que notre fichier ne fasse pas plus que 10 Ko. Nos logs sont stockés dans ici : 

```shell 
LOG="/var/log/dump-mysql.log" 
```
Pour contrôler la taille du fichier on utilise ``du`` (disk usage) avec ``-B K`` pour avoir un résultat en Ko : 
```shell
VOLUME=$(du -B K $LOG)
```

Enfin au moment de quitter, si le fichier est plein on remplace la dernière ligne : 
```shell
echo "Fin des logs, fichier log plein - $DATE" > $LOG
```
Sinon on écrit à la suite la fin du fichier log : 
```shell
echo "Fin des logs - $DATE" >> $LOG
```