#include <stdio.h>
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

    time_t now;
    struct tm *t;

    while(1)
    {
    	data->logger_hb = time(NULL);
        now = time(NULL);
        t = localtime(&now);

        printf("[%02d:%02d:%02d] Logger -> Speed:%d Distance:%d Action:%d\n",
               t->tm_hour,
               t->tm_min,
               t->tm_sec,
               data->speed,
               data->distance,
               data->action);

        sleep(2);
    }

    return 0;
}
