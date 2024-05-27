#!/bin/bash

usage() {
    echo "Usage:"
    echo "./buildProj.sh [clean] [-j N]"
    echo "Options:"
    echo "  clean         Clean project."
    echo "  -j N          Specify number of threads for make (optional)."
    exit 1
}

THREADS=""

while [[ $# -gt 0 ]]; do
    case $1 in
        clean)
            CLEAN=true
            shift
            ;;
        -j)
            if [[ -n $2 && $2 =~ ^[0-9]+$ ]]; then
                THREADS="-j$2"
                shift 2
            else
                usage
            fi
            ;;
        *)
            usage
            ;;
    esac
done

if [ "$CLEAN" = true ]; then
    make clean
    make clean -C lapos-0.1.2/
    #rm -rf build
    rm -rf .qmake.stash
    rm -rf Makefile
else
    qmake6
    make $THREADS
    make $THREADS -C lapos-0.1.2/
fi
