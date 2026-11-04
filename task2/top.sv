module top #(
    parameter int ADDRESS_WIDTH = 8,
    parameter int DATA_WIDTH = 8
)(
    input logic [ADDRESS_WIDTH-1:0] incr,
    input logic [ADDRESS_WIDTH-1:0] offset,

    input logic rst,
    input logic en,
    input logic clk,

    output logic [DATA_WIDTH-1:0] dout1,
    output logic [DATA_WIDTH-1:0] dout2
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
    .clk (clk),
    .addr1 (addr), // inputs below
    .addr2 (addr + offset), // inputs below
    .dout1 (dout1),
    .dout2 (dout2)
  );

endmodule
