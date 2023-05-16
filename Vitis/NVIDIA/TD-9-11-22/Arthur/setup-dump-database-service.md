Le service est l'outil qui va nous permettre de lancer notre script de sauvegarde : 

 ```shell 
 [Service]
ExecStart=/home/arthur/dump-database.sh
```
On désactive la sauvegarde si aucun utilisateur n'est connecté : 
 ```shell 
[Install]
WantedBy=multi-user.target
```

Puis on lance ce servir toutes les 10 mins, pour cela on nomme un ``.timer`` avec le même nom que notre service : 

```shell
[Timer]
OnUnitActiveSec=10min
```

Le problème est que le service requiert des droits pour manipuler la base de donnée que l'utilisateur n'a pas. Nous allons donc donner les droits à l'utilisateur pour que le service puisse se lancer. 

On commence par reconfigurer MySQL pour ajouter un mot de passe fort d'accès : 

```shell 
sudo mysql_secure_installation
```

Une fois avoir suivi les instructions à l'écran, nous pouvons créer notre super utilisateur qui pourra lancer le service : 
```shell
mysql> CREATE USER 'arthur'@'localhost' IDENTIFIED BY 'Superazerty123?';
```
Puis lui donner les droits : 
```shell 
mysql> GRANT PROCESS ON *.* TO 'arthur'@'localhost';
```

Et voilà le service se met en route et les sauvegardes toutes les 10 minutes ! 

