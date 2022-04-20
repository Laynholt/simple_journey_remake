#ifndef _TERRARIA_H_
#define _TERRARIA_H_

#include "../map.h"
#include "bioms/bioms.h"

#define TERRARIA_BACKGROUND_GENERATE 0
#define TERRARIA_FOREGROUND_GENERATE 1

// TODO: with rand biom
extern void terraria_generate(Map* map);

#endif
