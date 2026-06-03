PLATFORM ?= x86_64
BUILD_PROFILE ?= debug
CONFIG_NAME ?= $(PLATFORM)-$(BUILD_PROFILE)

OUTPUT_DIR = build/$(CONFIG_NAME)

CC = qcc -Vgcc_nto$(PLATFORM)

CFLAGS = -Wall -g -O0 -fno-builtin

all: prep logger_ecu sensor_ecu control_ecu brake_ecu steering_ecu watchdog_ecu

prep:
	mkdir -p $(OUTPUT_DIR)

logger_ecu:
	$(CC) $(CFLAGS) src/logger_ecu.c -o $(OUTPUT_DIR)/logger_ecu
	
sensor_ecu:
	$(CC) $(CFLAGS) src/sensor_ecu.c -o $(OUTPUT_DIR)/sensor_ecu

control_ecu:
	$(CC) $(CFLAGS) src/control_ecu.c -o $(OUTPUT_DIR)/control_ecu

brake_ecu:
	$(CC) $(CFLAGS) src/brake_ecu.c -o $(OUTPUT_DIR)/brake_ecu

steering_ecu:
	$(CC) $(CFLAGS) src/steering_ecu.c -o $(OUTPUT_DIR)/steering_ecu

watchdog_ecu:
	$(CC) $(CFLAGS) src/watchdog_ecu.c -o $(OUTPUT_DIR)/watchdog_ecu

clean:
	rm -rf build
