/**
 * Copyright (c) 2021 Neil Stevenson
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "fallingsand.h"
#include "PimoroniPicoRenderer.h"
using namespace pimoroni;

static const int NUM_GRAINS = 1600; //pixels

// Main
int main(int argc, char *argv[]) 
{
    int accel = 2200;

    stdio_init_all();
    uint16_t buffer[PicoDisplay::WIDTH * PicoDisplay::HEIGHT];
    PicoDisplay pico_display(buffer);
    pico_display.init();

    PimoroniPicoRenderer rend(pico_display);
    FallingSand sand(rend, 50);
    sand.setAcceleration(0, accel);
 
    // Add a few grains
    for(int i = 0; i < NUM_GRAINS/RESOLUTION_SCALE; i++)
    {
        RGB_colour grain_colour = {(uint8_t)(rand()%64+195), (uint8_t)(rand()%64+195), (uint8_t)(rand()%64+128)};
        sand.addGrain(grain_colour);
    }
 
    while(1)
    {
        //printf("cycle start accel %d\n", accel);
        sand.runCycle();
        sleep_ms(20);
        if(pico_display.is_pressed(pico_display.A))
        {
            sand.setAcceleration(0,-accel);
        }
        else if(pico_display.is_pressed(pico_display.B))
        {
            sand.setAcceleration(0,accel);
        }
        else if(pico_display.is_pressed(pico_display.X))
        {
            accel -= 20;
            sand.setAcceleration(-accel,0);
        }
        else if(pico_display.is_pressed(pico_display.Y))
        {
            accel += 20;
            sand.setAcceleration(accel,0);
        }
   }
}