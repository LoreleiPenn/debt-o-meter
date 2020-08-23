#!/bin/zsh

if [[ ! -d "build" ]]; then
    mkdir build
fi
cd build
export CC=/usr/bin/clang
export CXX=/usr/bin/clang++
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
cd ..

