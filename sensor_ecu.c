#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "vehicle_data.h"

int main()
{
    int fd = shm_open("/vehicle_shm", O_CREAT | O_RDWR, 0666);
    ftruncate(fd, sizeof(VehicleData));

    VehicleData *data = mmap(0, sizeof(VehicleData),
                              PROT_READ | PROT_WRITE,
                              MAP_SHARED, fd, 0);

    srand(time(NULL));

    while(1)
    {
    	data->sensor_hb = time(NULL);
        data->speed = rand() % 120;
        data->distance = rand() % 100;
        data->steering = rand() % 30;

        printf("Sensor ECU -> Speed:%d Distance:%d Steering:%d\n",
                data->speed, data->distance, data->steering);

        sleep(2);
    }

    return 0;
}
