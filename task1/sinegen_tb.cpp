#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env) {
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);

    // init top verilog instance
    Vtop* top = new Vtop;

    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("top.vcd");

    // init vbuddy
    if (vbdOpen() != 1) // Open Vbuddy device, port path specified in vbuddy.cfg
        return -1;
    vbdHeader("Lab 2: Sine Wave ROM"); // Write header at top of TFT, center justified

    // init sim inputs
    top->clk = 1;
    top->rst = 1;
    top->en = 0;

    int frequency = 3;
    assert(frequency >= 1); // make sure frequncy is positive;

    top->incr = frequency;

    // run sim for many clock cycles
    for (int i = 0; i < 300000; i++) {

            // dump vars into VCD file and toggle clock
            for (clk = 0; clk < 2; clk++) {
                tfp->dump(2 * i + clk); // unit is in ps
                top->clk = !top->clk;
                top->eval();
            }

            // override freq with potentiometer value
            top->incr = vbdValue();

            vbdPlot(int(top->dout), 0, 255);

            vbdCycle(i + 1); // Report the cycle count on bottom right of TFT screen
            // end of vbuddy output

            top->rst = (i < 2);
            top->en = vbdFlag(); // Return current Flag value

            if (Verilated::gotFinish() || vbdGetkey() == 'q')
                exit(0);

    }

    vbdClose(); // Close an opened Vbuddy device
    tfp->close();
    exit(0);
}
