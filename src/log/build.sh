#!/bin/bash

# 获取脚本路径
build_dir=$(
    cd "$(dirname "$0")"
    pwd
)
cd ${build_dir}
mkdir -p build
cd build
cmake ..
make
make install
