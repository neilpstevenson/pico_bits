/**
 * Copyright (c) 2021 Neil Stevenson
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "PimoroniPicoRenderer.h"

using namespace pimoroni;

// Implementation of the renderer for the Pimoroni pico display
//
PimoroniPicoRenderer::PimoroniPicoRenderer(PicoDisplay &display) :
        RGBMatrixRenderer(PicoDisplay::WIDTH/RESOLUTION_SCALE, PicoDisplay::HEIGHT/RESOLUTION_SCALE, 255),
        pico_display(display)
{
    clear();
    pico_display.set_backlight(200);
}

void PimoroniPicoRenderer::setPixel(uint16_t x, uint16_t y, RGB_colour col) 
{
    //printf("setPixel(%d,%d = %d,%d,%d)\n", x, y, col.r, col.g, col.b);
    pico_display.set_pen(col.r, col.g, col.b);
    pico_display.rectangle(Rect{x*RESOLUTION_SCALE, y*RESOLUTION_SCALE, RESOLUTION_SCALE, RESOLUTION_SCALE});
    //pico_display.circle(Point(x*RESOLUTION_SCALE, y*RESOLUTION_SCALE), RESOLUTION_SCALE/2);
    //pico_display.pixel(Point(x*RESOLUTION_SCALE, y*RESOLUTION_SCALE));
}

void PimoroniPicoRenderer::clear() 
{
    pico_display.set_pen(0, 0, 0);
    pico_display.clear();
}

void PimoroniPicoRenderer::showPixels() 
{
    pico_display.update();
}

void PimoroniPicoRenderer::msSleep(int ms) 
{
    sleep_ms(ms);
}

void PimoroniPicoRenderer::outputMessage(char msg[]) 
{
    printf("%s\n", msg);

}

int16_t PimoroniPicoRenderer::random_int16(int16_t a, int16_t b)
{
    return a + rand()%(b-a);
}
