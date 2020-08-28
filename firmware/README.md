# stm32f405 firmware for Quad ADSR eurorack module

## This is a CMSIS/Makefile type project.
- The bare minimum stm supplied CMSIS and startup files are included in appropriate directories.
- The rest of the code is hand written `C` which uses the CMSIS headers to manipulate registers and peripherals.
- A Makefile is included to build/clean/flash the project.
- An st-link device is used to flash the f405.

---
## Prerequisites:
- arm-none-eabi toolchain
- make
- st-link drivers
- A physical st-link device. I use an old Nucleo board.

---
### This is a work in progress, the general idea I'm working towards:
- The four encoders use the hardware timers in encoder mode so that no code is needed to read the encoders.
- A fast timer interrupt will read the gate/trigger inputs, tick the four ADSRs, and update the DACs at some sample rate > 1kHz.
- A different slower timer interrupt will process the encoder readings, update the ADSR inputs, and update the LED displays.
- Every once in a while the EEPROM will be updated if a parameter has changed. 
- The EEPROM should be read at startup to load the saved parameters.
