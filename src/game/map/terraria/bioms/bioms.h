#ifndef _BIOMS_H_
#define _BIOMS_H_

#define BIOM_QUANTITY 3
enum BiomTypes
{
    BIOM_MOUNTAINS = 0,
    BIOM_SIMPLE_FOREST = 1,
    BIOM_PLAIN = 2,   
};

#include "../terraria.h"
#include "../../map.h"

//#include "tree.h"
//#include "cloud.h"
#include "landscape.h"

// TODO:
// генерация разных биомов (множество функций, которые будет вызывать террария)
extern void biom_generate_mountains(Map* map, uint32_t leftBorder, u_int32_t rightBorder, uint8_t typeGround);

extern char* biom_get_biom_name(Map* map, uint16_t currentBiom);

#endif
