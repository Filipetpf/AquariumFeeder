FROM ubuntu

RUN apt-get update && apt-get install python-pip -y
RUN pip install platformio
RUN platformio platform install atmelavr espressif8266
RUN mkdir -p /usr/src/app

WORKDIR /usr/src/app
