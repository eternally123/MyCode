#!/bin/bash

# 获取脚本路径
EXEC_PATH=$(
    cd "$(dirname "$0")"
    pwd
)
cd ${EXEC_PATH}
mkdir -p build
cd build
cmake ..
make
make install
