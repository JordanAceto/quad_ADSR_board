# stm32f405 firmware for Quad ADSR eurorack module

## Brief description:

Four ADSR envelope generators are created in software via Direct Digital Synthesis.

Four encoders allow the user to set the attack, decay, sustain, and release parameters.

By clicking on the encoder that is in line with the jacks associated with a given ADSR, that 
ADSR is selected as the "active ADSR", and the encoders will adjust the parameters for that 
envelope only.

Performing a long button press forces all four ADSRs to lock to the ADSR associated with 
the encoder that was pressed. Now all four ADSRs will have the same attack, decay, sustain, 
and release parameters, and the encoders will update all four ADSRs simultaneously. This is
called "lock-to-master" mode. The primary use of lock-to-master mode is for polyphonic patches, 
you can easily have four ADSRs that share the same settings but can be triggered independently.

By doing a quick press of any encoder button the system will exit lock-to-master and the ADSRs will 
go back to independent mode, and their old settings will be restored.

The four digit seven-segment display shows the setting of the paramter that was most recently adjusted. 
Attack, decay, and release times are shown in seconds and milliseconds, and the sustain parameter is shown
as a percent from 0.0 to 100.

The settings for the ADSRs are remembered in EEPROM memory. The system automatically stores the settings in
the EEPROM every few minutes if they have changed.

---

## This is a CMSIS/Makefile type project.
- The bare minimum stm supplied CMSIS and startup files are included in appropriate directories.
- The rest of the code is hand written `C` which uses the CMSIS headers to manipulate registers and peripherals.
- A Makefile is included to build/clean/flash the project.
- An st-link device is used to flash the f405.

---
## Prerequisites:
- [arm-none-eabi toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)
- [GNU make](https://www.gnu.org/software/make/)
- [st-link utility](https://www.st.com/en/development-tools/stsw-link004.html)
- A physical st-link device. I use an old Nucleo board.
- If you have a different preferred method of flashing STM32 chips then feel free to go wild.

---

### To build the project:
- `$ make`

### To flash an STM32f405 chip connected to an st-link programmer via the SWD header:
- `$ make write`

---

### The attack and decay curves are stored in lookup tables which are generated via a python script.

You can tweak the curves via the command line (requires python/numpy/matplotlib).

To view a plot of the attack and decay curves:
- `$ make plot_lut`

To tweak the curves and then view the results:
- `make plot_lut ATTACK_TARGET=<number between 1 and 5> NUM_TIME_CONSTANTS=<number between 3 and 10>`

To overwrite the C header and source files with tweaked curves:
- `$ make write_lut ATTACK_TARGET=<number between 1 and 5> NUM_TIME_CONSTANTS=<number between 3 and 10>`

To overwrite the C header and source files with default curves:
- `$ make write_lut`
