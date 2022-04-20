#include "bioms.h"

void biom_generate_mountains(Map* map, uint32_t leftBorder, u_int32_t rightBorder, uint8_t typeGround)
{
    if (typeGround == TERRARIA_FOREGROUND_GENERATE)
        landscape_generate(map, leftBorder, LANDSCAPE_FOREGROUND_HEIGHT_TOP_MOUNTAINS, rightBorder, LANDSCAPE_FOREGROUND_HEIGHT_BOT, BIOM_MOUNTAINS); 
    else if (typeGround == TERRARIA_BACKGROUND_GENERATE) 
        landscape_generate(map, leftBorder, LANDSCAPE_BACKGROUND_HEIGHT_TOP_MOUNTAINS, rightBorder, LANDSCAPE_BACKGROUND_HEIGHT_BOT, BIOM_MOUNTAINS);
}

char* biom_get_biom_name(Map* map, uint16_t currentBiom)
{
    char* bioms_names[] = {"Mountians", "Plain", "Forest"};
    return bioms_names[map->iBiomMap[currentBiom]];
}
