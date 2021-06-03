
DEFAULT_TARGET = main
TARGET = $(DEFAULT_TARGET)

LD_SCRIPT = STM32F405RGTx_FLASH.ld

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
CMSIS_DEV_DIR = ./CMSIS/Device/
CMSIS_INC_DIR = ./CMSIS/Include/
BIN_DIR       = ./bin/

OPTIONS += $(MCU)
OPTIONS += -O0
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

ASM_OBJECT_FILES := $(patsubst $(SRC_DIR)%.s,$(BIN_DIR)%.o,$(wildcard $(SRC_DIR)*.s))

C_OBJECT_FILES := $(patsubst $(SRC_DIR)%.c,$(BIN_DIR)%.o,$(wildcard $(SRC_DIR)*.c))

.PHONY: all
all: $(C_OBJECT_FILES) $(BIN_DIR)
	$(C_COMPILER) $(C_FLAGS) $(SRC_DIR)$(TARGET).c -o $(BIN_DIR)$(TARGET).o
	make $(BIN_DIR)$(TARGET).bin

# compile the user provided application assembly source files
$(BIN_DIR)%.o: $(SRC_DIR)%.s
	$(C_COMPILER) $(ASM_FLAGS) $< -o $@

# compile the user provided application c source files
$(BIN_DIR)%.o: $(SRC_DIR)%.c
	$(C_COMPILER) $(C_FLAGS) $< -o $@

$(BIN_DIR)$(TARGET).elf: $(C_OBJECT_FILES) $(ASM_OBJECT_FILES) $(BIN_DIR)$(TARGET).o
	$(C_COMPILER) $(L_FLAGS) -o $(BIN_DIR)$(TARGET).elf $(ASM_OBJECT_FILES) $(C_OBJECT_FILES) $(CPP_OBJECT_FILES)

$(BIN_DIR)$(TARGET).bin: $(BIN_DIR)$(TARGET).elf
	$(OBJECT_COPY) $(OBJ_COPY_FLAGS) $< $@
	$(OBJECT_DUMP) -D $(BIN_DIR)$(TARGET).elf > $(BIN_DIR)$(TARGET).list
	$(OBJECT_SIZE) $<
	@./utils/get_fw_size.sh $< 0xfa000 0x1f400

write: $(BIN_DIR)$(TARGET).bin
	st-flash --reset write $(BIN_DIR)$(TARGET).bin 0x08000000

# if ./bin/ does not exist, create the directory
$(BIN_DIR):
	mkdir $@

clean:
	rm -f $(BIN_DIR)*.o
	rm -f $(BIN_DIR)*.out
	rm -f $(BIN_DIR)*.elf
	rm -f $(BIN_DIR)*.bin
	rm -f $(BIN_DIR)*.list
