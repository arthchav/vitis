# Running the Docker Container:

```
$ git clone --recursive https://github.com/dusty-nv/jetson-inference
$ cd jetson-inference
$ docker/run.sh
```
# Building the project from the Source:

### Cloning the Repository

```
$ sudo apt-get update
$ sudo apt-get install git cmake
```

```
$ git clone https://github.com/dusty-nv/jetson-inference
$ cd jetson-inference
$ git submodule update --init
```
### Python Packages

```
$ sudo apt-get install libpython3-dev python3-numpy
```

### Configuring with CMake

```
$ cd jetson-inference    # omit if working directory is already jetson-inference/ from above
$ mkdir build
$ cd build
$ cmake ../
```

### Installing PyTorch

```
$ cd jetson-inference/build
$ ./install-pytorch.sh
```

### Compiling the Project

```
$ cd jetson-inference/build          # omit if working directory is already build/ from above
$ make
$ sudo make install
$ sudo ldconfig
```

# Classifying Images with ImageNet

### Using the ImageNet Program on Jetson

```
$ cd jetson-inference/build/aarch64/bin
```

### Example

```
$ ./imagenet.py images/orange_0.jpg images/test/output_0.jpg  # (default network is googlenet)

$ ./imagenet.py images/strawberry_0.jpg images/test/output_1.jpg
```

Pour une vidéo:

```
$ wget https://nvidia.box.com/shared/static/tlswont1jnyu3ix2tbf7utaekpzcx4rc.mkv -O jellyfish.mkv

$ ./imagenet.py --network=resnet-18 jellyfish.mkv images/test/jellyfish_resnet18.mkv
```

# Coding Your Own Image Recognition Program (Python)

### Setting up the Project

```
# run these commands outside of container
$ cd ~/
$ mkdir my-recognition-python
$ cd my-recognition-python
$ touch my-recognition.py
$ chmod +x my-recognition.py
$ wget https://github.com/dusty-nv/jetson-inference/raw/master/data/images/black_bear.jpg 
$ wget https://github.com/dusty-nv/jetson-inference/raw/master/data/images/brown_bear.jpg
$ wget https://github.com/dusty-nv/jetson-inference/raw/master/data/images/polar_bear.jpg 
```
```
$ jetson-inference/docker/run.sh --volume ~/my-recognition-python:/my-recognition-python   # mounted inside the container to /my-recognition-python 
```

### Source Code

```
vim my-recognition.py
```
```
#!/usr/bin/python3

import jetson.inference
import jetson.utils

import argparse

# parse the command line
parser = argparse.ArgumentParser()
parser.add_argument("filename", type=str, help="filename of the image to process")
parser.add_argument("--network", type=str, default="googlenet", help="model to use, can be:  googlenet, resnet-18, ect.")
args = parser.parse_args()

# load an image (into shared CPU/GPU memory)
img = jetson.utils.loadImage(args.filename)

# load the recognition network
net = jetson.inference.imageNet(args.network)

# classify the image
class_idx, confidence = net.Classify(img)

# find the object description
class_desc = net.GetClassDesc(class_idx)

# print out the result
print("image is recognized as '{:s}' (class #{:d}) with {:f}% confidence".format(class_desc, class_idx, confidence * 100))
```

### Running Example

```
$ ./my-recognition.py polar_bear.jpg
image is recognized as 'ice bear, polar bear, Ursus Maritimus, Thalarctos maritimus' (class #296) with 99.999878% confidence
```
