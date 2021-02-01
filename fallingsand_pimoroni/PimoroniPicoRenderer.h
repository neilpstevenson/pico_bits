/**
 * Copyright (c) 2021 Neil Stevenson
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "RGBMatrixRenderer.h"
#include "pico_display.hpp"

// Definition of the renderer for the Pimoroni pico display
class PimoroniPicoRenderer : public RGBMatrixRenderer
{
    pimoroni::PicoDisplay pico_display;
    int grain_size;
    uint16_t display_buffer[pimoroni::PicoDisplay::WIDTH * pimoroni::PicoDisplay::HEIGHT];

public:

    PimoroniPicoRenderer(int grain_size);
    
    void clear();
    virtual void setPixel(uint16_t x, uint16_t y, RGB_colour col);
    virtual void showPixels(); 
    virtual void msSleep(int ms);
    virtual void outputMessage(char msg[]);
    virtual int16_t random_int16(int16_t a, int16_t b);

    pimoroni::PicoDisplay& display();

};

