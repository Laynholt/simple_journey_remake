#ifndef _LANDSCAPE_H_
#define _LANDSCAPE_H_

#include <stdlib.h>

#include "../../../config.h"
#include "../../../types.h"
#include "../../map.h"

#include "bioms.h"

// Типы заполнения ландшафта
#define LANDSCALE_FILL_DEFAULT " .:oO"


// Высоты ландшафта
// Фон
    // Высоты
#define LANDSCAPE_BACKGROUND_HEIGHT_TOP_MOUNTAINS SCREEN_HEIGHT / 8
#define LANDSCAPE_BACKGROUND_HEIGHT_TOP_PLAIN SCREEN_HEIGHT / 3
    // Низменности
#define LANDSCAPE_BACKGROUND_HEIGHT_BOT SCREEN_HEIGHT / 2
// Пердний план
    // Высоты
#define LANDSCAPE_FOREGROUND_HEIGHT_TOP_MOUNTAINS SCREEN_HEIGHT / 4
#define LANDSCAPE_FOREGROUND_HEIGHT_TOP_PLAIN / SCREEN_HEIGHT / 2
    // Низменности
#define LANDSCAPE_FOREGROUND_HEIGHT_BOT SCREEN_HEIGHT


extern void landscape_generate(Map* map, uint32_t left, uint16_t top, uint32_t right, uint16_t bottom, uint8_t biom_type);

extern void landscape_midpoint_displacement(Map* map, uint32_t leftX, uint16_t leftY, uint32_t rightX, uint16_t rightY, float roughness);
extern void landscape_fill_ground(Map* map, uint32_t x, uint16_t y_start);

// TODO: 
// функции генерации ландшафта

#endif
