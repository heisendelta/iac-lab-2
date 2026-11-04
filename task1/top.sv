module top #(
    parameter int ADDRESS_WIDTH = 8,
    parameter int DATA_WIDTH = 8
)(
    input logic [ADDRESS_WIDTH-1:0] incr,
    input logic rst,
    input logic en,
    input logic clk,

    output logic [DATA_WIDTH-1:0] dout
);

  logic [ADDRESS_WIDTH-1:0] addr;

  counter Counter (
    .incr (incr), // inputs below
    .rst (rst),
    .en (en),
    .clk (clk),
    .addr (addr) // output
  );

  rom ROM (
    .addr (addr), // inputs below
    .clk (clk),
    .dout (dout)
  );

endmodule
