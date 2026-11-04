module counter #(
    parameter int WIDTH = 9
) (
    // interference signals
    input logic clk, // count
    input logic rst, // reset
    input logic en, // counter enable

    output logic [WIDTH-1:0] addr // counter output
);

always_ff @ (posedge clk)
    if (rst)
        addr <= WIDTH'(0);
    else if (en)
        addr <= addr +  WIDTH'(1);

endmodule
