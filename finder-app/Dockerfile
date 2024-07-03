from ubuntu:20.04 AS assignment1

MAINTAINER Dan Walkes (walkes@colorado.edu)

SHELL ["/bin/bash", "-c"]
# Assignment 3 kernel build - add kernel build dependencies and qemu-system-arm
# Use recommends with qemu-system-arm since it needs rom files we don't obtain with no-install-recommends
RUN apt-get update && apt-get install -y --no-install-recommends \
        bc u-boot-tools kmod cpio flex bison libssl-dev psmisc && \
    apt-get install -y qemu-system-arm

#FROM assignment3-kernel AS assignment3
WORKDIR /usr/local/arm-cross-compiler/
ARG GCC_ARM_VERSION=10.3-2021.07
# Assignment 3 - ARM cross compiler
RUN wget -O gcc-arm.tar.xz https://developer.arm.com/-/media/Files/downloads/gnu-a/10.3-2021.07/binrel/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu.tar.xz && \
    mkdir install && \
    tar x -C install -f gcc-arm.tar.xz && \
    rm -r gcc-arm.tar.xz

ENV PATH="${PATH}:/usr/local/arm-cross-compiler/install/gcc-arm-$GCC_ARM_VERSION-x86_64-aarch64-none-linux-gnu/bin"

RUN  sed -i "/^# If not running interactively, don't do anything.*/i export PATH=\$PATH:$(find /usr/local/arm-cross-compiler/install -maxdepth 2 -type d -name bin)" \
            /root/.bashrc
RUN  sed -i "/^# If not running interactively, don't do anything.*/i export PATH=\$PATH:$(find /usr/local/arm-cross-compiler/install -maxdepth 2 -type d -name bin)" \
            /home/autotest-admin/.bashrc

