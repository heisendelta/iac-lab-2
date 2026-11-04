module counter #(
    parameter int WIDTH = 8
) (
    // interference signals
    input logic clk, // count
    input logic rst, // reset
    input logic en, // counter enable
    input logic [WIDTH-1:0] incr,

    output logic [WIDTH-1:0] addr // counter output
);

always_ff @ (posedge clk)
    if (rst)
        addr <= WIDTH'(0);
    else if (en)
        addr <= addr + incr;

endmodule
