add_executable(fallingsand_gravity)

target_sources(fallingsand_gravity PRIVATE
        main.cpp
        ../fallingsand_pimoroni/fallingsand.cpp
        ../fallingsand_pimoroni/RGBMatrixRenderer.cpp
        ../fallingsand_pimoroni/PimoroniPicoRenderer.cpp
        mpu6050_i2c.c
        ${PICO_PIMORONI_PATH}/libraries/pico_display/pico_display.cpp
        )

include_directories("../fallingsand_pimoroni")

# Pull in our pico_stdlib which aggregates commonly used features
target_link_libraries(fallingsand_gravity pico_stdlib hardware_spi hardware_pwm hardware_dma hardware_i2c pico_graphics st7789 )

# enable usb output, disable uart output
pico_enable_stdio_usb(fallingsand_gravity 1)
pico_enable_stdio_uart(fallingsand_gravity 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(fallingsand_gravity)

# add url via pico_set_program_url
#example_auto_set_url(fallingsand_gravity)
