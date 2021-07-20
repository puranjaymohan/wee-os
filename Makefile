# Name of the final elf output file
PROJECT:=main

#device for building the project
DEVICE:=TM4C123GH6PM

#Scheduling algorithm to be used by the OS
SCHD_ALG = round_robin

# Funtion to find all files inside a directory recursively
rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

# Directory to generate the output elf
BUILD:=build

# Find all C files and Assembly files in src and it's subdirectories
C_SRCS:= $(call rwildcard,src,*.c)
S_SRCS:= $(call rwildcard,src,*.s)

C_SRCS+= $(call rwildcard,device/$(DEVICE),*.c)
S_SRCS+= $(call rwildcard,device/$(DEVICE),*.s)

# Find all header files and add -I before them.
HEADERS:= $(dir $(call rwildcard,src,*.h))
HEADERS+= $(dir $(call rwildcard,device/$(DEVICE),*.h))
H:= $(patsubst %,-I%,$(HEADERS))

# Change extention of C and Assembly files to .o and add to OBJECTS variable.
OBJECTS:= $(patsubst %.c,%.o,$(C_SRCS))
OBJECTS += $(patsubst %.s,%.o,$(S_SRCS))

# Linker file to be used by the linker
LINKER_FILE:= device/$(DEVICE)/linker.ld

# toolchain settings
CROSS:=arm-none-eabi-
CC:=$(CROSS)gcc
OBJDUMP:=$(CROSS)objdump
OBJCOPY:=$(CROSS)objcopy

# gcc & ld compiler flags
OPT:=-Og
FLAGS:=-mcpu=cortex-m4 -mthumb
CFLAGS:=$(FLAGS) $(OPT) $(H) -fno-common -g3 -Wall -Werror -Wextra -D$(DEVICE) -D$(SCHD_ALG)
LDFLAGS:=$(FLAGS) -T$(LINKER_FILE) -nostartfiles -nostdlib -lnosys

.PHONY: all
all: $(BUILD) $(BUILD)/$(PROJECT).elf $(LINKER_FILE)

$(BUILD)/$(PROJECT).elf: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

%.o: %.s
	$(CC) $(CFLAGS) -o $@ -c $<

$(BUILD):
	mkdir $(BUILD)

.PHONY: clean
clean:
	rm -r $(BUILD)/$(PROJECT).elf $(BUILD) $(OBJECTS)
