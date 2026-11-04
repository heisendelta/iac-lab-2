#!/bin/sh

# cleanup
rm -rf obj_dir
rm -f top.vcd

# run verilator to translate verilog to c++
# includingn c++ test bench
verilator -Wall --cc --trace top.sv counter.sv rom.sv --exe sinegen_tb.cpp

# build C++ project via make generator by verilator
make -j -C obj_dir/ -f Vtop.mk Vtop

# run executable sim file
obj_dir/Vtop
