FROM gcc

# user tools
ENV SHELL /bin/bash

RUN apt update && apt install -y \
    screen \
    vim
