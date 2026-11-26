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
    -s ALLOW_MEMORY_GROWTH=1 \
    --preload-file images/shift.png \
    --preload-file sound/dragon.mp3 \
    --preload-file sound/wordChew.mp3 \
    --preload-file sound/soul.mp3 \
    --preload-file sound/dance.mp3 \
    --preload-file sound/NASA.mp3 \
    --preload-file sound/beats.mp3 \
    --preload-file sound/pop.mp3 \
    --preload-file sound/vista.mp3 \
    --preload-file sound/Vampire.mp3
   
   