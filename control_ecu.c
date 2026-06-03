#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <time.h>
#include "vehicle_data.h"

int main()
{
    int fd = shm_open("/vehicle_shm", O_RDWR, 0666);

    VehicleData *data = mmap(0, sizeof(VehicleData),
                              PROT_READ | PROT_WRITE,
                              MAP_SHARED, fd, 0);
    srand(time(NULL));

    while(1)
    {
        int d = data->distance;
        data->control_hb = time(NULL);

        if(d > 40)
        {
            data->action = 0;
            printf("Control ECU -> SAFE (%d m)\n", d);
        }
        else if(d > 20)
        {
            data->action = 1;
            printf("Control ECU -> WARNING (%d m)\n", d);
        }
        else
        {
            data->action = 2;
            printf("Control ECU -> EMERGENCY BRAKE (%d m)\n", d);
        }

        sleep(2);
    }

    return 0;
}
