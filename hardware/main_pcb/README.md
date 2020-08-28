# Main pcb

## This subdirectory contains the documents needed to build and/or modify the main pcb.

---
### The general outline of the hardware:
- An stm32f405 generates four ADSRs digitally using DDS/look up tables.
- Four encoders control the Attack, Decay, Sustain, and Release parameters.
- The ADSR signals are sent to two MCP4822 SPI DACs.
- The MCP4822 DACs feed four opamp lowpass filters which smooth, scale, and buffer the output signals.
- A seven segment LED display and four bicolor LEDs are driven by shift registers connected to the SPI bus.
- An EEPROM is driven by the I2C bus.
- NPN transistors buffer the microcontroller inputs from the outside world.
- A standard Eurorack style power input header is used for the +/- 12vdc power input.
- The opamps are powered directly by the +/- 12vdc input.
- A 3.3v regulator provides power to the low voltage parts of the system.

---
### `kicad_docs` contains all the files needed to open the project in kicad.
- If you want to modify the project, go in here.
---
### `construction_docs` contains the files needed to build the project:
- A pdf copy of the schematic.
- An interactive BOM that can be opened in a web browser.
- Complete gerbers for the pcb, and a zipped copy of all the gerbers.
- Files for using the cheap smt assembly service from jlcpcb. Most of the small parts are included. The DACs and EEPROM were left out because they were extended parts at jlc at the time I ordered.
- If you use the jlcpcb assembly service, you'll still need to hand install the DACs, EEPROM, and all the through hole parts.

---
### `pics` contains a few rendered pics of the pcb

![](./pics/pcb_rear.png?raw=true "pcb rear")

![](./pics/pcb_front.png?raw=true "pcb front")