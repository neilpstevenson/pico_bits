cmake_minimum_required(VERSION 3.12)

# Pull in PICO SDK (must be before project)
include(pico_sdk_import.cmake)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_NEIL_PATH ${PROJECT_SOURCE_DIR})

include_directories("/home/pi/pico/pimoroni-pico/libraries/pico_display")
link_directories("/home/pi/pico/pimoroni-pico/build/libraries/pico_graphics")
link_directories("/home/pi/pico/pimoroni-pico/build/drivers/st7789")

project(pico_bits C CXX ASM)

# Initialize the SDK
pico_sdk_init()

#include(example_auto_set_url.cmake)

# Add sub project
add_subdirectory(fallingsand_pimoroni)
#add_subdirectory("/home/pi/pico/pimoroni-pico/build/libraries/pico_display")

