
DEFAULT_TARGET = main
TARGET = $(DEFAULT_TARGET)

LD_SCRIPT = $(THIRD_PARTY)STM32F405RGTx_FLASH.ld

CPU = -mcpu=cortex-m4
FPU = -mfpu=fpv4-sp-d16
FLOAT-ABI = -mfloat-abi=hard
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

TOOLCHAIN    = arm-none-eabi
C_COMPILER   = $(TOOLCHAIN)-gcc
OBJECT_COPY  = $(TOOLCHAIN)-objcopy
OBJECT_DUMP  = $(TOOLCHAIN)-objdump
OBJECT_SIZE  = $(TOOLCHAIN)-size

SRC_DIR       = ./src/
INC_DIR       = ./inc/
THIRD_PARTY   = ./third_party/
CMSIS_DEV_DIR = $(THIRD_PARTY)CMSIS/Device/
CMSIS_INC_DIR = $(THIRD_PARTY)CMSIS/Include/
BIN_DIR       = ./bin/

OPTIONS += $(MCU)
OPTIONS += -Os
OPTIONS += --specs=nosys.specs
OPTIONS += -nostdlib
OPTIONS += -fno-exceptions
OPTIONS += -fdata-sections
OPTIONS += -ffunction-sections
OPTIONS += -Wall

ASM_FLAGS += -c
ASM_FLAGS += -x 
ASM_FLAGS += assembler-with-cpp
ASM_FLAGS += $(OPTIONS)

C_FLAGS += -c
C_FLAGS += $(OPTIONS)
C_FLAGS += -I$(INC_DIR)
C_FLAGS += -I$(CMSIS_DEV_DIR)
C_FLAGS += -I$(CMSIS_INC_DIR)

L_FLAGS += $(MCU)
L_FLAGS += -specs=nano.specs
L_FLAGS += -nostartfiles
L_FLAGS += -lc -lm -lnosys 
L_FLAGS += -Xlinker
L_FLAGS += --gc-sections 
L_FLAGS += -T./$(LD_SCRIPT)

OBJ_COPY_FLAGS += -S
OBJ_COPY_FLAGS += -O 
OBJ_COPY_FLAGS += binary

ASM_STARTUP_FILE := $(patsubst $(THIRD_PARTY)%.s,$(BIN_DIR)%.o,$(wildcard $(THIRD_PARTY)*.s))

C_OBJECT_FILES := $(patsubst $(SRC_DIR)%.c,$(BIN_DIR)%.o,$(wildcard $(SRC_DIR)*.c))

.PHONY: all
all: $(C_OBJECT_FILES)
	$(C_COMPILER) $(C_FLAGS) $(SRC_DIR)$(TARGET).c -o $(BIN_DIR)$(TARGET).o
	make $(BIN_DIR)$(TARGET).bin

$(C_OBJECT_FILES): | $(BIN_DIR)

# if ./bin/ does not exist, create the directory
$(BIN_DIR):
	mkdir $@

# compile the third party assembly startup source files
$(BIN_DIR)%.o: $(THIRD_PARTY)%.s
	$(C_COMPILER) $(ASM_FLAGS) $< -o $@

# compile the user provided application c source files
$(BIN_DIR)%.o: $(SRC_DIR)%.c
	$(C_COMPILER) $(C_FLAGS) $< -o $@

$(BIN_DIR)$(TARGET).elf: $(C_OBJECT_FILES) $(ASM_STARTUP_FILE) $(BIN_DIR)$(TARGET).o
	$(C_COMPILER) $(L_FLAGS) -o $(BIN_DIR)$(TARGET).elf $(ASM_STARTUP_FILE) $(C_OBJECT_FILES) $(CPP_OBJECT_FILES)

$(BIN_DIR)$(TARGET).bin: $(BIN_DIR)$(TARGET).elf
	$(OBJECT_COPY) $(OBJ_COPY_FLAGS) $< $@
	$(OBJECT_DUMP) -D $(BIN_DIR)$(TARGET).elf > $(BIN_DIR)$(TARGET).list
	$(OBJECT_SIZE) $<
	@./utils/get_fw_size.sh $< 0xfa000 0x1f400

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
