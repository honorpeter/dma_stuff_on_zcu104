
module top (
    input logic         clk_300mhz_clk_n,
    input logic         clk_300mhz_clk_p,
    output logic        ddr4_sdram_act_n,
    output logic[16:0]  ddr4_sdram_adr,
    output logic[1:0]   ddr4_sdram_ba,
    output logic[1:0]   ddr4_sdram_bg,
    output logic        ddr4_sdram_ck_c,
    output logic        ddr4_sdram_ck_t,
    output logic        ddr4_sdram_cke,
    output logic        ddr4_sdram_cs_n,
    inout logic[7:0]    ddr4_sdram_dm_n,
    inout logic[63:0]   ddr4_sdram_dq,
    inout logic[7:0]    ddr4_sdram_dqs_c,
    inout logic[7:0]    ddr4_sdram_dqs_t,
    output logic        ddr4_sdram_odt,
    output logic        ddr4_sdram_reset_n,
    input logic         reset
);

    system system_i (
        .clk_300mhz_clk_n   (clk_300mhz_clk_n),
        .clk_300mhz_clk_p   (clk_300mhz_clk_p),
        .ddr4_sdram_act_n   (ddr4_sdram_act_n),
        .ddr4_sdram_adr     (ddr4_sdram_adr),
        .ddr4_sdram_ba      (ddr4_sdram_ba),
        .ddr4_sdram_bg      (ddr4_sdram_bg),
        .ddr4_sdram_ck_c    (ddr4_sdram_ck_c),
        .ddr4_sdram_ck_t    (ddr4_sdram_ck_t),
        .ddr4_sdram_cke     (ddr4_sdram_cke),
        .ddr4_sdram_cs_n    (ddr4_sdram_cs_n),
        .ddr4_sdram_dm_n    (ddr4_sdram_dm_n),
        .ddr4_sdram_dq      (ddr4_sdram_dq),
        .ddr4_sdram_dqs_c   (ddr4_sdram_dqs_c),
        .ddr4_sdram_dqs_t   (ddr4_sdram_dqs_t),
        .ddr4_sdram_odt     (ddr4_sdram_odt),
        .ddr4_sdram_reset_n (ddr4_sdram_reset_n),
        .reset              (reset)
    );
    
endmodule
