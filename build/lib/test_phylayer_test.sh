#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/zhou/src/gr-phylayer/lib
export PATH=/home/zhou/src/gr-phylayer/build/lib:$PATH
export LD_LIBRARY_PATH=/home/zhou/src/gr-phylayer/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-phylayer 
