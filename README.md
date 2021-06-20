# Quad digital ADSR module

# *** Work in progress ***

![](./pics/front.jpg?raw=true "front panel")

![](./pics/rear.jpg?raw=true "pcb rear")


## ADSRs are generated by an STM32 microcontroller and controlled by four encoders. A seven-segment display shows the most recently modified parameter. 

One ADSR at a time is set as the "active" ADSR, which will be controlled by the encoders. 

To select an ADSR as "active", the encoder push-button above a given ADSR is pressed.

The four-digit seven-segment display shows the parameter of the encoder that was most recently turned. For instance, if you just turned the decay time to 500 milliseconds, the display will show `0.500`. If you then adjust the sustain level to 68%, the display will now show `  68`. Time based parameters are shown in units of seconds, and sustain parameters are shown as 0% to 100%.

Additionally, the ADSRs can all be forced to lock to a "master" ADSR, so that that their attack, decay, sustain, and release parameters are all set the same. The four ADSRs can still be triggered independently in this mode, which makes this useful for polyphonic patches. This saves you from manually setting identical paramters four times. Lock-to-master mode is selected by performing a long push-switch press of the encoder above the desired ADSR. For instance, to force all the ADSRs to lock to the ADSR 3 settings, depress and hold the sustain encoder push-button for a few seconds. To leave lock-to-master mode, do a short click of any of the encoder push-buttons to select a new active ADSR.

A bank of four bi-color LEDs shows the active ADSR, and whether it is in independent, or lock-to-master mode.

# First rev build evaluation:
- Most of the systems work.
- __Done__ (but there is an I2C bug lurking, see the issues)~~The EEPROM has not been physically installed and EEPROM code has not been written yet.~~
- __DONE__ ~~In the code, when switching from lock-to-master mode back to independent mode: the ADSRs should go back to the settings they held before entering lock-to-master mode. Write a function called `release_ADSRs_from_master_mode` or something that accomplishes this, and call that function when leaving lock-to-master mode~~.
- __Done__ ~~The encoders should be no-detent types. I used encoders with detents and I don't like it.~~
- I tried and failed to setup encoder trigger filtering, please investigate using the timer register filters when the timers are in encoder mode. I'd like to be able to apply filtering to the encoders. They work fine and don't misfire now, but it would be nice to easily tailor how "fast" they update by addign in some filtering.
- __This really isn't that bad__ ~~The heights of the panel mount components is an issue: the 3.5mm jacks are taller than the encoders and the seven-segment display. I got everything to work by lifting the encoders and 7-seg up off the pcb before soldering, but this is lame. I think the solution is split the pcb into a main pcb and a jack pcb, and connect the two pcbs with wires. Another solution could be to create a "lifter" pcb that acts as a spacer between the main pcb and the encoders/7-seg, but this seems kind of yucky too. Think about this for a while before doing a new pcb rev.~~
- I'm having issues with getting the PLL to work for arbitrary frequencies: with some settings of M, N, and P the output frequency is not as expected. Please investigate this and figure out what I'm doing wrong.
- I used two MCP4822 DACs, but I probably could have used the 2 internal DAC channels for 2 of the ADSRs and only installed one MCP4822. Investigate if using the internal DAC for 2 channels creates any pinout conflicts, or any other kind of conflicts, for the next board revision, to try and save a DAC.
- The ADSR outputs are low: I want 10v peak ADSRs and I calculated the opamp gain resistors assuming the DACs output 3.3v peaks, but they don't. Please recalculate the gain resistors for the actual MCP4822 output with a gain of 1x. Take into account the internal DACs if you apply the suggestion above.
- __DONE__ (enabled FPU and changed signals to floats) ~~Many parts of the codebase could be optimized and improved. In particular, the ADSR code does some costly 64-bit divisions in a couple of spots. See if you can't improve this. View the `main.list` output file occasionally~~.
- __DONE__ (works ok but be on the lookout) ~~Compiler optimization is turned off right now. Turn this up to `-Os` or `-O2` and make sure that nothing breaks. There might be some volatile issues, or necessary code that gets optimized away, be careful and thorough!~~
- Otherwise the project is in pretty good shape! The prototype I built could definitely go in a rack and work with other modules.
