# Stream la vidéo de la caméra sur l'ordinateur(MacOs)

Problème rencontré:
-impossibilité d'ouvrir une fenêtre vidéo sur le terminal de la carte.

Solution proposé:
-Envoyé le flux vidéo de la caméra connecté à la carte vers un ordinateur connecté au même réseau internet.

## Enregistrer une vidéo de la caméra et l'enregistrer sur mon ordinateur:

```
video-viewer /dev/video0 test-webcam.mp4
```

Sur le terminal de l'ordinateur:

```
scp vitis@192.168.55.1:/home/vitis/test-webcam.mp4 Documents
```

Puis vérifier dans le finder que le fichier est bien présent et qu'on a bien une vidéo de la caméra.

## Stream le flux vidéo de la caméra avec VLC

Connecter la carte et l'ordinateur au même réseau. 
Ici, l'adresse IP du wifi est 172.20.10.2. (voir tuto de Prise en Main)

Création du fichier sdp:

```
vim stream_jetson.sdp
```

Contenue du fichier:

```
c=IN IP4 127.0.0.1
m=video 9306 RTP/AVP 96
a=rtpmap:96 H264/90000
```

Lancer la diffusion vidéo de la caméra:

```
video-viewer --bitrate=1000000 --output-codec=h264 /dev/video0 rtp://172.20.10.2:9306
```

Lancer la vidéo sur son prdinateur avec VLC:

```
/Applications/VLC.app/Contents/MacOS/VLC stream_jetson.sdp
```







