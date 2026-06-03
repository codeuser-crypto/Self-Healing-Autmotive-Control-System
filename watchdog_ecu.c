/*
 * watchdog_ecu.c
 *
 *  Created on: 26-Mar-2026
 *      Author: vijay
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include "vehicle_data.h"

#define TIMEOUT 5

int main()
{
    int fd = shm_open("/vehicle_shm", O_RDWR, 0666);

    VehicleData *data = mmap(0, sizeof(VehicleData),
                              PROT_READ | PROT_WRITE,
                              MAP_SHARED, fd, 0);

    while(1)
    {
        time_t now = time(NULL);

        // SENSOR ECU
        if(now - data->sensor_hb > TIMEOUT)
        {
            printf("Watchdog -> Sensor ECU FAILED! Restarting...\n");
            system("/tmp/sensor_ecu &");
            data->sensor_hb = now;
        }

        // CONTROL ECU
        if(now - data->control_hb > TIMEOUT)
        {
            printf("Watchdog -> Control ECU FAILED! Restarting...\n");
            system("/tmp/control_ecu &");
            data->control_hb = now;
        }

        // BRAKE ECU
        if(now - data->brake_hb > TIMEOUT)
        {
            printf("Watchdog -> Brake ECU FAILED! Restarting...\n");
            system("/tmp/brake_ecu &");
            data->brake_hb = now;
        }

        // STEERING ECU
        if(now - data->steering_hb > TIMEOUT)
        {
            printf("Watchdog -> Steering ECU FAILED! Restarting...\n");
            system("/tmp/steering_ecu &");
            data->steering_hb = now;
        }

        // LOGGER ECU
        if(now - data->logger_hb > TIMEOUT)
        {
            printf("Watchdog -> Logger ECU FAILED! Restarting...\n");
            system("/tmp/logger_ecu &");
            data->logger_hb = now;
        }

        sleep(2);
    }

    return 0;
}
