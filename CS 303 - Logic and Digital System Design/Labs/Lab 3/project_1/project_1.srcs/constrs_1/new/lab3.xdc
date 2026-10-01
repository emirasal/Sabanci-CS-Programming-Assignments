# inputs from switches
set_property -dict { PACKAGE_PIN J15  IOSTANDARD LVCMOS33 } [get_ports { C }]
set_property -dict { PACKAGE_PIN L16  IOSTANDARD LVCMOS33 } [get_ports { B }]
set_property -dict { PACKAGE_PIN M13  IOSTANDARD LVCMOS33 } [get_ports { A }]

# outputs to LED
set_property -dict { PACKAGE_PIN H17  IOSTANDARD LVCMOS33 } [get_ports { F }]