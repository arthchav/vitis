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
