module sigdelay #(
    parameter int ADDRESS_WIDTH = 9,
    parameter int DATA_WIDTH = 8
)(
    input logic clk,
    input logic rst,
    input logic wr,
    input logic rd,

    input logic [ADDRESS_WIDTH-1:0] offset,
    input logic [DATA_WIDTH-1:0] mic_signal,

    output logic [DATA_WIDTH-1:0] delayed_signal
);

    logic [ADDRESS_WIDTH-1:0] addr;

    counter #(
        .WIDTH(ADDRESS_WIDTH)
    ) Counter(
        .clk(clk),
        .rst(rst),
        .en(1'(1)),
        .addr(addr)
    );

    ram2port #(
        .ADDRESS_WIDTH(ADDRESS_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) RAM(
        .clk(clk),

        .wr_en(1'(wr)),
        .wr_addr(addr),

        .rd_en(1'(rd)),
        .rd_addr(addr - offset),

        .din(mic_signal),
        .dout(delayed_signal)
    );

endmodule
