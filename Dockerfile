FROM ubuntu:focal

ENV TZ=Europe/Warsaw

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN DEBIAN_FRONTEND=noninteractive apt -qq update && \
       apt -qq install -y \
       sudo \
       wget \
       git \
       curl \
       gcc-10 \
       g++-10 \
       make \
       cmake \
       gdb \
       pkg-config

RUN apt -qq install -y libopencv-dev

RUN apt -qq install -y python3 python3-pip python3-setuptools python3-wheel ninja-build

RUN pip3 install meson

RUN useradd -m dev --uid=1000 && echo "dev:dev" | chpasswd
RUN chsh -s /bin/bash dev
RUN sudo usermod -aG sudo dev
WORKDIR /home/dev

COPY . .

RUN sudo chmod -R 777 /home/dev/*

USER dev


