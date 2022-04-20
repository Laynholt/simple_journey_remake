#ifndef _MAP_H_
#define _MAP_H_

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "../config.h"
#include "../types.h"

#include "terraria/terraria.h"

#define MAP_FULL_FILL 0
#define MAP_FULL_FILL_WITH_HORIZ 1
#define MAP_FILL_ROW 2


typedef struct Map
{
    uint32_t iMapWidth;      // Ширина карты
    uint16_t iMapHeight;     // Высота карты
    uint32_t iMapWidthOld;   // Старое значение ширины карты
    uint16_t iMapHeightOld;  // Старое значение высоты карты

    uint64_t iMapSize;       // Размер карты
    uint16_t iBiomQuantity;  // Размер карты биомов

    uchar** cMap;            // Карта
    uint16_t* iBiomMap;      // Карта биомов
}Map;


// Функции для карты
extern uint64_t map_get_map_fullsize(const Map* map);
extern uchar** map_allocate_memory(uint64_t allocate_size);

extern int16_t map_create(Map* map);
extern void map_destruct(Map* map);

extern void map_fill(Map* map, uchar** background, int16_t fill_type, int16_t fill_row, uchar symbol);
extern void map_show_frame(Map* map, Point* pCameraPosition);


// TODO:
// memory allocate for map
// generate map

#endif
