#!/bin/bash

source ~/emsdk/emsdk_env.sh

mkdir -p build-web

em++ \
    src/main.cpp \
    src/player.cpp \
    src/platform.cpp \
    src/enemy.cpp \
    src/theCamera.cpp \
    -o build-web/Game1.html \
    -I include \
    -I ~/raylib/src \
    ~/raylib/src/libraylib.web.a \
    -s USE_GLFW=3 \
    -s ASYNCIFY \
    --preload-file images
   