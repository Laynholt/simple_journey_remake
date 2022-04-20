#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <stdio.h>
#include <unistd.h>

#include "../config.h"
#include "../types.h"

#include "../map/map.h"

#define CAMERA_SPEED 5

enum eMoveDirection
{
    STAND = 0,
    MOVE_LEFT = 1,
    MOVE_RIGHT = 2
};

typedef struct Camera
{
    Point position;
    uint16_t iCurrentFrame;
    uint16_t iCurrentBiom;

}Camera;

extern void camera_move(Camera* camera, Map* map, uint8_t iDirection);


// TODO:
// move camera

#endif
