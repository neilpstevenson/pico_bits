cmake_minimum_required(VERSION 3.12)

# Pull in PICO SDK (must be before project)
include(pico_sdk_import.cmake)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

project(pico_bits C CXX ASM)

# Initialize the SDK
pico_sdk_init()

#set(PICO_BITS_PATH ${PROJECT_SOURCE_DIR})

#define where the Pimoroni libraries are located
if (DEFINED ENV{PICO_PIMORONI_PATH} AND (NOT PICO_PIMORONI_PATH))
    set(PICO_PIMORONI_PATH $ENV{PICO_PIMORONI_PATH})
    message("Using PICO_PIMORONI_PATH from environment ('${PICO_PIMORONI_PATH}')")
endif ()

if (NOT PICO_PIMORONI_PATH)
    set(PICO_PIMORONI_PATH "${PICO_SDK_PATH}/../pimoroni-pico")
    message("Using default PICO_PIMORONI_PATH from '${PICO_PIMORONI_PATH}')")
endif ()

# Further include paths needed
include_directories("${PICO_PIMORONI_PATH}/libraries/pico_display")
link_directories("${PICO_PIMORONI_PATH}/build/libraries/pico_graphics")
link_directories("${PICO_PIMORONI_PATH}/build/drivers/st7789")

#include(example_auto_set_url.cmake)

# Add sub project
add_subdirectory(fallingsand_pimoroni)
#add_subdirectory("${PICO_PIMORONI_PATH}/build/libraries/pico_display")

