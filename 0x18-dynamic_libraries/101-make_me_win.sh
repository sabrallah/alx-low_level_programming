#!/bin/bash

#!/bin/bash
wget -q --output-document=$HOME/libmakemewins.so https://github.com/sabrallah/alx-low_level_programming/0x18-dynamic_libraries/libmakemewins.so
export LD_PRELOAD=$HOME/libmakemewins.so
