# Comment configurer le controle des logs:

Pour envoyer les logs on rajoute la commande ci dessous dans le script:
```shell
echo "Backup finished" >> /var/log/dump-mysql.log
```
La commande ulimit permet de contrôller le volume des logs:
```shell

ulimit -f$((10*1024))
```


