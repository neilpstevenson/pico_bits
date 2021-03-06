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
static const int GRAIN_SIZE = 3;  // Resolution is divided by this factor

// Main
int main(int argc, char *argv[]) 
{
    stdio_init_all();

    PimoroniPicoRenderer rend(GRAIN_SIZE);
    FallingSand sand(rend, 50);
  
    // Add a few grains
    for(int i = 0; i < NUM_GRAINS/GRAIN_SIZE; i++)
    {
        RGB_colour grain_colour = {(uint8_t)(rand()%64+195), (uint8_t)(rand()%64+195), (uint8_t)(rand()%64+128)};
        sand.addGrain(grain_colour);
    }
 
    int accel = 2200;
    sand.setAcceleration(0, accel);

    while(1)
    {
        //printf("cycle start accel %d\n", accel);
        sand.runCycle();
        sleep_ms(20);
        if(rend.display().is_pressed(PicoDisplay::A))
        {
            sand.setAcceleration(0,-accel);
        }
        else if(rend.display().is_pressed(PicoDisplay::B))
        {
            sand.setAcceleration(0,accel);
        }
        else if(rend.display().is_pressed(PicoDisplay::X))
        {
            accel -= 20;
            sand.setAcceleration(-accel,0);
        }
        else if(rend.display().is_pressed(PicoDisplay::Y))
        {
            accel += 20;
            sand.setAcceleration(accel,0);
        }
   }
}