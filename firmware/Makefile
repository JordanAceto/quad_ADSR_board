
DEFAULT_TARGET = main
TARGET = $(DEFAULT_TARGET)

CPU = -mcpu=cortex-m4
FPU = -mfpu=fpv4-sp-d16
FLOAT-ABI = -mfloat-abi=hard
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

TOOLCHAIN   = arm-none-eabi
C_COMPILER  = $(TOOLCHAIN)-gcc
OBJECT_COPY = $(TOOLCHAIN)-objcopy
OBJECT_DUMP = $(TOOLCHAIN)-objdump
OBJECT_SIZE = $(TOOLCHAIN)-size

BSP_DIR         = ./BSP/
LIB_DIR         = ./lib/
SRC_DIR         = ./src/
THIRD_PARTY_DIR = ./third_party/
CMSIS_DEV_DIR   = $(THIRD_PARTY_DIR)CMSIS/Device/
CMSIS_INC_DIR   = $(THIRD_PARTY_DIR)CMSIS/Include/
BIN_DIR         = ./bin/

OPTIONS += $(MCU)
OPTIONS += -Os
OPTIONS += -Wall
OPTIONS += -fdata-sections
OPTIONS += -ffunction-sections

ASM_FLAGS += -c
ASM_FLAGS += -x
ASM_FLAGS += assembler-with-cpp
ASM_FLAGS += $(OPTIONS)

C_FLAGS += -c
C_FLAGS += $(OPTIONS)
C_FLAGS += -I$(BSP_DIR)
C_FLAGS += -I$(LIB_DIR)
C_FLAGS += -I$(SRC_DIR)
C_FLAGS += -I$(CMSIS_DEV_DIR)
C_FLAGS += -I$(CMSIS_INC_DIR)

LD_SCRIPT = $(THIRD_PARTY_DIR)STM32F405RGTx_FLASH.ld

L_FLAGS += $(MCU)
L_FLAGS += -specs=nano.specs
L_FLAGS += -T./$(LD_SCRIPT)
L_FLAGS += -lc -lm -lnosys
L_FLAGS += -nostartfiles
L_FLAGS += -Wl,--gc-sections
L_FLAGS += -Wl,--print-memory-usage


OBJ_COPY_FLAGS += -S
OBJ_COPY_FLAGS += -O
OBJ_COPY_FLAGS += binary

C_OBJECT_FILES  = $(patsubst $(SRC_DIR)%.c,$(BIN_DIR)%.o,$(wildcard $(SRC_DIR)*.c))
C_OBJECT_FILES += $(patsubst $(BSP_DIR)%.c,$(BIN_DIR)%.o,$(wildcard $(BSP_DIR)*.c))
C_OBJECT_FILES += $(patsubst $(LIB_DIR)%.c,$(BIN_DIR)%.o,$(wildcard $(LIB_DIR)*.c))

ASM_OBJECT_FILES := $(patsubst $(THIRD_PARTY_DIR)%.s,$(BIN_DIR)%.o,$(wildcard $(THIRD_PARTY_DIR)*.s))

.PHONY: all
all: $(C_OBJECT_FILES) $(BIN_DIR)
	$(C_COMPILER) $(C_FLAGS) $(SRC_DIR)$(TARGET).c -o $(BIN_DIR)$(TARGET).o
	make $(BIN_DIR)$(TARGET).bin

$(C_OBJECT_FILES): | $(BIN_DIR)

# if ./bin/ does not exist, create the directory
$(BIN_DIR):
	mkdir $@

# compile the user provided application c source files
$(BIN_DIR)%.o: $(BSP_DIR)%.c
	$(C_COMPILER) $(C_FLAGS) $< -o $@

$(BIN_DIR)%.o: $(LIB_DIR)%.c
	$(C_COMPILER) $(C_FLAGS) $< -o $@

$(BIN_DIR)%.o: $(SRC_DIR)%.c
	$(C_COMPILER) $(C_FLAGS) $< -o $@

# compile the third party assembly startup source files
$(BIN_DIR)%.o: $(THIRD_PARTY_DIR)%.s
	$(C_COMPILER) $(ASM_FLAGS) $< -o $@

$(BIN_DIR)$(TARGET).elf: $(C_OBJECT_FILES) $(ASM_OBJECT_FILES) $(BIN_DIR)$(TARGET).o
	$(C_COMPILER) $(L_FLAGS) -o $(BIN_DIR)$(TARGET).elf $(ASM_OBJECT_FILES) $(C_OBJECT_FILES) $(CPP_OBJECT_FILES)

$(BIN_DIR)$(TARGET).bin: $(BIN_DIR)$(TARGET).elf
	$(OBJECT_COPY) $(OBJ_COPY_FLAGS) $< $@
	$(OBJECT_DUMP) -D $(BIN_DIR)$(TARGET).elf > $(BIN_DIR)$(TARGET).list

write: $(BIN_DIR)$(TARGET).bin
	st-flash --reset write $(BIN_DIR)$(TARGET).bin 0x08000000

# a python script handles lookup table generation
# ATTACK_TARGET is used to truncated the attack rc curve, useful range [1..5]
# NUM_TIME_CONSTANTS sets the number of time constants that the LUT contains, useful range [3..10]

# generate the attack and decay lookup tables as c files
write_lut:
	@cd utils; python3 lookup_table_gen.py write $(ATTACK_TARGET) $(NUM_TIME_CONSTANTS);

# show a plot of the attack and decay lookup tables
plot_lut:
	@cd utils; python3 lookup_table_gen.py plot $(ATTACK_TARGET) $(NUM_TIME_CONSTANTS);

clean:
	rm -f $(BIN_DIR)*.o
	rm -f $(BIN_DIR)*.out
	rm -f $(BIN_DIR)*.elf
	rm -f $(BIN_DIR)*.bin
	rm -f $(BIN_DIR)*.list
