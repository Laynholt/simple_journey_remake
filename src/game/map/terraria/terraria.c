#include "terraria.h"

void terraria_generate(Map* map)
{
    uint8_t fgBiomType, bgBiomType;

    fgBiomType = rand() % BIOM_QUANTITY;
    bgBiomType = rand() % BIOM_QUANTITY;

    map->iBiomMap[map->iBiomQuantity - 1] = fgBiomType;

    if (fgBiomType == BIOM_MOUNTAINS)
    {
        biom_generate_mountains(map, map->iMapWidthOld, map->iMapWidth, TERRARIA_FOREGROUND_GENERATE);
    }

    if (bgBiomType == BIOM_MOUNTAINS)
    {
        biom_generate_mountains(map, map->iMapWidthOld, map->iMapWidth, TERRARIA_BACKGROUND_GENERATE);
    }
}
