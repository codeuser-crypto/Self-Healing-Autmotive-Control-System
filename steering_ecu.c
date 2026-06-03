#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "vehicle_data.h"

int main()
{
    int fd = shm_open("/vehicle_shm", O_RDWR, 0666);

    VehicleData *data = mmap(0, sizeof(VehicleData),
                              PROT_READ | PROT_WRITE,
                              MAP_SHARED, fd, 0);

    while(1)
    {
    	data->steering_hb = time(NULL);
        if(data->action == 1)
        {
            printf("Steering ECU -> Adjusting steering to avoid obstacle\n");
        }

        sleep(2);
    }

    return 0;
}
