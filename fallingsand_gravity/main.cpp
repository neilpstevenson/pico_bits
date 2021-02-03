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

static const int NUM_GRAINS = 9000; //pixels
static const int GRAIN_SIZE = 3;  // Resolution is divided by this factor

extern "C" void init_6050();
extern "C" void mpu6050_read_raw(int16_t accel[3], int16_t gyro[3], int16_t *temp);

// Main
int main(int argc, char *argv[]) 
{
    stdio_init_all();
    init_6050();

    PimoroniPicoRenderer rend(GRAIN_SIZE);
    FallingSand sand(rend, 50);

    // Add a few grains
    for(int i = 0; i < NUM_GRAINS/(GRAIN_SIZE*GRAIN_SIZE); i++)
    {
        RGB_colour grain_colour = {(uint8_t)(rand()%64+195), (uint8_t)(rand()%64+195), (uint8_t)(rand()%64+128)};
        sand.addGrain(grain_colour);
    }
 
    int i = 0;
    while(1)
    {
        //printf("cycle start accel %d\n", accel);
        sand.runCycle();
        sleep_ms(20);

        // Update accels
        if(i++ % 10 == 0)
        {
            int16_t acceleration[3], gyro[3], temp;
            mpu6050_read_raw(acceleration, gyro, &temp);
            //printf("Acc. X = %d, Y = %d, Z = %d\n", acceleration[0], acceleration[1], acceleration[2]);
            //printf("Setting: X = %d, Y = %d\n", acceleration[0]/8, acceleration[1]/8);
            sand.setAcceleration(acceleration[1]/4, -acceleration[0]/4);
      }
    }
}