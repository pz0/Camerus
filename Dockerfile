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
       gdb \
       pkg-config

RUN apt -qq install -y libopencv-dev

RUN useradd -m dev --uid=1000 && echo "dev:dev" | chpasswd
RUN chsh -s /bin/bash dev
RUN sudo usermod -aG sudo dev
WORKDIR /home/dev

COPY . .

RUN sudo chmod -R 777 /home/dev/*

USER dev


