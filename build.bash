#!/bin/bash

mkdir -p build

g++ -std=c++17 -Iinclude \
    src/main.cpp \
    src/player.cpp \
    src/platform.cpp \
    src/enemy.cpp \
    src/theCamera.cpp \
    -o build/Game1 \
    -lraylib -lGL -lm -lpthread -ldl -lrt -lX11