#ifndef VEHICLE_DATA_H
#define VEHICLE_DATA_H

#include <time.h>

typedef struct {
    int speed;
    int distance;
    int steering;
    int action;

    time_t sensor_hb;
    time_t control_hb;
    time_t brake_hb;
    time_t steering_hb;
    time_t logger_hb;

} VehicleData;

#endif
