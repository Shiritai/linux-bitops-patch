#!/bin/sh
./linux ubd0=/dev/null umid=uml0 \
        root=/dev/root rootfstype=hostfs hostfs=./rootfs \
        rw mem=64M init=/init.sh quiet

