add_executable(fallingsand_pimoroni)

target_sources(fallingsand_pimoroni PRIVATE
        main.cpp
        fallingsand.cpp
        RGBMatrixRenderer.cpp
        PimoroniPicoRenderer.cpp
        ../../pimoroni-pico/libraries/pico_display/pico_display.cpp
        )

# Pull in our pico_stdlib which aggregates commonly used features
target_link_libraries(fallingsand_pimoroni pico_stdlib hardware_spi hardware_pwm hardware_dma pico_graphics st7789)

# enable usb output, disable uart output
pico_enable_stdio_usb(fallingsand_pimoroni 1)
pico_enable_stdio_uart(fallingsand_pimoroni 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(fallingsand_pimoroni)

# add url via pico_set_program_url
#example_auto_set_url(fallingsand_pimoroni)
