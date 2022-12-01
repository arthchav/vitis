# Comment configurer le service:

D'après: https://azurplus.fr/comment-executer-un-programme-linux-au-demarrage-avec-systemd/

```shell
sudo chmod +x dump-database.sh

./dump-database.sh

sudo nano /lib/systemd/system/dump-database.service

sudo systemctl daemon-reload

sudo systemctl enable dump-database.service

sudo systemctl start dump-database.service

sudo systemctl status dump-database.service

```



