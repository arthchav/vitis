# Prise en main de la carte jetson nano:

<p align="center">
  <img width="50%" src="https://france.scc.com/wp-content/uploads/2021/02/nvidia-logo-horiz-rgb-1c-wht-for-screen-002-png-800x276.png" />
</p>

<p align="center">
  <img width="20%" src="https://www.nvidia.com/content/dam/en-zz/Solutions/intelligent-machines/jetson-store/nvidia-jetson-nano-dev-kit-2c50-P@2x.png" />
</p>

Connexion à la carte jetson nano:
```shell
 ssh vitis@192.168.55.1
 ```

 # Déplacer le stockage de la mémoire nvidia vers la carte SD:

On check les partitions pour voir le nom de la carte avec la commande:

```shell
lsblk
```
La carte SD ce nomme "mmcblk1p1".

On veut maintenant la formater au format ext4 en tapant la commande:

```shell
sudo mkfs.ext4 /dev/mmcblk1p1
```
On crée ensuite un point de montage:

```shell
sudo mkdir -p /usr/Documents
```

Puis on monte la partition:

```shell
sudo mount -t auto /dev/mmclk1p1 /usr/Documents
```

On vérifie que la partition est bien montée avec:
```shell
lsblk -f
```

On copie /home vers le nouvel emplacement:

```shell
sudo rsync -avx /home/ /usr/Documents
```
On monte la nouvelle partition:
```shell
sudo mount /dev/mmcblk1p1
```

On récupère le UUID de la nouvelle partition et on modifie le fstab:

```shell
sudo blkid
sudo vim /etc/fstab
UUID=03d60d39-967e-473e-b710-2687941e1d0a /home ext4 defaults 0 2
```

Finalement on redémarre la carte et /home est désormais sur la carte SD
```shell
sudo shutdown -r now
```

# Utiliser les images docker fournies par Nvidia:

Installer le package nvidia-container, attention à bien être connecté en wifi avec la carte(voir annexe):
```shell
sudo apt install nvidia-container
```
On modifie le fichier /etc/docker/daemon.json en ajoutant:
```shell
"data-root":"/mnt/sd_card"
```


