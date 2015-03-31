# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Samuel\Documents\GitHub\BYU-MarsRover\Arm\arm_controller_v2\arm_controller_v2.1.cydsn\arm_controller_v2.1.cyprj
# Date: Tue, 31 Mar 2015 14:41:00 GMT
#set_units -time ns
create_clock -name {UART_TEST_SCBCLK(FFB)} -period 708.33333333333326 -waveform {0 354.166666666667} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {UART_1_SCBCLK(FFB)} -period 708.33333333333326 -waveform {0 354.166666666667} [list [get_pins {ClockBlock/ff_div_3}]]
create_clock -name {Clock_pwm(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_8}] [get_pins {ClockBlock/ff_div_9}] [get_pins {ClockBlock/ff_div_10}]]
create_clock -name {ADC_intClock(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_7}]]
create_clock -name {Clock_counter(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_11}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_generated_clock -name {UART_TEST_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 17 35} -nominal_period 708.33333333333326 [list]
create_generated_clock -name {UART_1_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 17 35} -nominal_period 708.33333333333326 [list]
create_generated_clock -name {Clock_pwm} -source [get_pins {ClockBlock/hfclk}] -edges {1 25 49} [list [get_pins {ClockBlock/udb_div_3}]]
create_generated_clock -name {ADC_intClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 25 49} [list]
create_generated_clock -name {Clock_counter} -source [get_pins {ClockBlock/hfclk}] -edges {1 25 49} [list]
create_generated_clock -name {SPIM_1_IntClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 13 25} [list [get_pins {ClockBlock/udb_div_1}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]


# Component constraints for C:\Users\Samuel\Documents\GitHub\BYU-MarsRover\Arm\arm_controller_v2\arm_controller_v2.1.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Samuel\Documents\GitHub\BYU-MarsRover\Arm\arm_controller_v2\arm_controller_v2.1.cydsn\arm_controller_v2.1.cyprj
# Date: Tue, 31 Mar 2015 14:40:41 GMT
