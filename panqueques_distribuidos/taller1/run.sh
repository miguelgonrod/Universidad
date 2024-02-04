#!/bin/bash

docker build -f build/taller1.Dockerfile -t distribuidosimage .
docker run -it \
	--env="DISPLAY" \
    	--env="QT_X11_NO_MITSHM=1" \
    	--volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
	--network host \
	--mount src="./scripts",target="/home/distribuidos/scripts",type=bind \
	distribuidosimage:latest
