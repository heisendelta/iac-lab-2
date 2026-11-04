#!/bin/sh

# cleanup
rm -rf obj_dir
rm -f sigdelay.vcd

# run verilator to translate verilog to c++
# includingn c++ test bench
verilator -Wall --cc --trace sigdelay.sv ram2port.sv counter.sv --exe sigdelay_tb.cpp

# build C++ project via make generator by verilator
make -j -C obj_dir/ -f Vsigdelay.mk Vsigdelay

# run executable sim file
obj_dir/Vsigdelay
