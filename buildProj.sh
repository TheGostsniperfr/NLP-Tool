#!/bin/bash

usage() {
    echo "Usage:"
    echo "./buildProj.sh -> build project."
    echo "./buildProj.sh clean -> clean project"
    exit 1
}

if [ $# -eq 0 ]; then
    qmake6
    make -j10
    make -j10 -C lapos-0.1.2/
elif [ "$1" = "clean" ]; then
    make clean
    make clean -C lapos-0.1.2/
    #rm -rf build
    rm -rf .qmake.stash
    rm -rf Makefile
else
    usage
fi
