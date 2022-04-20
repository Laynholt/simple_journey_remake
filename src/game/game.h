#ifndef _GAME_H_
#define _GAME_H_

#include <string.h>
#include <signal.h>
#include <stdlib.h>

#include "config.h"
#include "types.h"
#include "control/kbhit.h"

#include "map/map.h"
#include "camera/camera.h"

typedef struct Game
{
    Map worldMap;
    Camera camera;

}Game;

extern int16_t game_create(Game* game);
extern void game_start(Game* game);
extern void game_exit(Game* game);

extern void game_show_info(Game* game);
extern void game_show_general_info(Game* game);

#endif
