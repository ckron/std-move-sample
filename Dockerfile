FROM ubuntu:22.04

# user tools
ENV SHELL /bin/bash

RUN apt update && apt install -y \
    screen \
    vim \
    g++

COPY ./main.cpp /root/main.cpp

RUN cd && \
    g++ ~/main.cpp -o sample

CMD ~/sample