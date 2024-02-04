FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y nano python3 && \
    apt-get install -y tmux && \
    apt-get install -y net-tools

RUN useradd -m -s /bin/bash -N -u 1000 distribuidos && \
    echo "distribuidos ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers && \
    chmod 0440 /etc/sudoers && \
    chmod g+w /etc/passwd 

USER distribuidos

WORKDIR /home/distribuidos/scripts

