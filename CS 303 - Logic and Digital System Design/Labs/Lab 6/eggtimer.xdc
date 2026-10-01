## Board Clock: 100 MHz
set_property -dict {PACKAGE_PIN E3 IOSTANDARD LVCMOS33} [get_ports {CLK100MHZ}];
create_clock -name clk -period 10.00 [get_ports {CLK100MHZ}];

# Board RESET PIN
set_property -dict { PACKAGE_PIN C12  IOSTANDARD LVCMOS33 } [get_ports { rst }]

# Timer BEGIN and RESET pins
set_property -dict { PACKAGE_PIN P17  IOSTANDARD LVCMOS33 } [get_ports { reset }]
set_property -dict { PACKAGE_PIN M17  IOSTANDARD LVCMOS33 } [get_ports { beginn }]

# Timer preset from switches
set_property -dict { PACKAGE_PIN V10 IOSTANDARD LVCMOS33 } [get_ports { PM10[3] }]
set_property -dict { PACKAGE_PIN U11 IOSTANDARD LVCMOS33 } [get_ports { PM10[2] }]
set_property -dict { PACKAGE_PIN U12 IOSTANDARD LVCMOS33 } [get_ports { PM10[1] }]
set_property -dict { PACKAGE_PIN H6  IOSTANDARD LVCMOS33 } [get_ports { PM10[0] }]
#
set_property -dict { PACKAGE_PIN T13 IOSTANDARD LVCMOS33 } [get_ports { PM1[3] }]
set_property -dict { PACKAGE_PIN R16 IOSTANDARD LVCMOS33 } [get_ports { PM1[2] }]
set_property -dict { PACKAGE_PIN U8  IOSTANDARD LVCMOS33 } [get_ports { PM1[1] }]
set_property -dict { PACKAGE_PIN T8  IOSTANDARD LVCMOS33 } [get_ports { PM1[0] }]
#
set_property -dict { PACKAGE_PIN R13 IOSTANDARD LVCMOS33 } [get_ports { PS10[3] }]
set_property -dict { PACKAGE_PIN U18 IOSTANDARD LVCMOS33 } [get_ports { PS10[2] }]
set_property -dict { PACKAGE_PIN T18 IOSTANDARD LVCMOS33 } [get_ports { PS10[1] }]
set_property -dict { PACKAGE_PIN R17 IOSTANDARD LVCMOS33 } [get_ports { PS10[0] }]
#
set_property -dict { PACKAGE_PIN R15 IOSTANDARD LVCMOS33 } [get_ports { PS1[3] }]
set_property -dict { PACKAGE_PIN M13 IOSTANDARD LVCMOS33 } [get_ports { PS1[2] }]
set_property -dict { PACKAGE_PIN L16 IOSTANDARD LVCMOS33 } [get_ports { PS1[1] }]
set_property -dict { PACKAGE_PIN J15 IOSTANDARD LVCMOS33 } [get_ports { PS1[0] }]

# outputs to seven-segment display
set_property -dict { PACKAGE_PIN H15  IOSTANDARD LVCMOS33 } [get_ports { DP }]
set_property -dict { PACKAGE_PIN L18  IOSTANDARD LVCMOS33 } [get_ports { SEVEN[6] }]
set_property -dict { PACKAGE_PIN T11  IOSTANDARD LVCMOS33 } [get_ports { SEVEN[5] }]
set_property -dict { PACKAGE_PIN P15  IOSTANDARD LVCMOS33 } [get_ports { SEVEN[4] }]
set_property -dict { PACKAGE_PIN K13  IOSTANDARD LVCMOS33 } [get_ports { SEVEN[3] }]
set_property -dict { PACKAGE_PIN K16  IOSTANDARD LVCMOS33 } [get_ports { SEVEN[2] }]
set_property -dict { PACKAGE_PIN R10  IOSTANDARD LVCMOS33 } [get_ports { SEVEN[1] }]
set_property -dict { PACKAGE_PIN T10  IOSTANDARD LVCMOS33 } [get_ports { SEVEN[0] }]

# outputs to seven-segment display segment select
set_property -dict { PACKAGE_PIN U13  IOSTANDARD LVCMOS33 } [get_ports { AN[7] }]
set_property -dict { PACKAGE_PIN K2   IOSTANDARD LVCMOS33 } [get_ports { AN[6] }]
set_property -dict { PACKAGE_PIN T14  IOSTANDARD LVCMOS33 } [get_ports { AN[5] }]
set_property -dict { PACKAGE_PIN P14  IOSTANDARD LVCMOS33 } [get_ports { AN[4] }]
set_property -dict { PACKAGE_PIN J14  IOSTANDARD LVCMOS33 } [get_ports { AN[3] }]
set_property -dict { PACKAGE_PIN T9   IOSTANDARD LVCMOS33 } [get_ports { AN[2] }]
set_property -dict { PACKAGE_PIN J18  IOSTANDARD LVCMOS33 } [get_ports { AN[1] }]
set_property -dict { PACKAGE_PIN J17  IOSTANDARD LVCMOS33 } [get_ports { AN[0] }]
