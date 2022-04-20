#include "landscape.h"

void landscape_generate(Map* map, uint32_t left, uint16_t top, uint32_t right, uint16_t bottom, uint8_t biom_type)
{
    float roughness = 0.0f;
    uint16_t y_start = bottom - (rand() % (top) + rand() % 3) - 1;
    uint16_t y_end = bottom - (rand() % (top) + rand() % 5) - 1;

    if (biom_type == BIOM_MOUNTAINS)
    {
        roughness = 0.3f;
    }
    else if (biom_type == BIOM_PLAIN)
    {
        roughness = 0.9f;
    }
    
    landscape_fill_ground(map, left, y_start);
    landscape_fill_ground(map, right - 1, y_end);

    landscape_midpoint_displacement(map, left, y_start, right - 1, y_end, roughness);
}

void landscape_midpoint_displacement(Map* map, uint32_t leftX, uint16_t leftY, uint32_t rightX, uint16_t rightY, float roughness)
{
    uint32_t length = rightX - leftX;
    if (length == 1) return;

    uint16_t randomValue = (rand() % (int32_t)(roughness * length * 2) - length * roughness);
    uint16_t height = (leftY + rightY) / 2 * randomValue;

    while(height >= map->iMapHeight || height < 0)
    {
        randomValue = (rand() % (int32_t)(roughness * length * 2) - length * roughness);
        height = (leftY + rightY) / 2 * randomValue;
    }

    landscape_fill_ground(map, leftX + length / 2, height);

    // Вызываем для левого и правого подотрезка по рекурсии
    landscape_midpoint_displacement(map, leftX, leftY, leftX + length / 2, height, roughness);
    landscape_midpoint_displacement(map, leftX + length / 2, height, rightX, rightY, roughness);
}

void landscape_fill_ground(Map* map, uint32_t x, uint16_t y_start)
{
    // Плавно зарисовываем грунт ландшафта
    for(uint16_t y = y_start; y < map->iMapHeight; ++y)
    {
        uint16_t deltaY = map->iMapHeight - y_start;
        uint8_t color;

        if (y == y_start)                                                   color = LANDSCALE_FILL_DEFAULT[4];
        else if (y > y_start && y <= y_start + deltaY / 4)                  color = LANDSCALE_FILL_DEFAULT[3];
        else if (y > y_start + deltaY / 4 && y <= y_start + deltaY / 2)     color = LANDSCALE_FILL_DEFAULT[2];
        else if (y > y_start + deltaY / 2 && y <= y_start + 3 * deltaY / 2) color = LANDSCALE_FILL_DEFAULT[1];
        else                                                                color = LANDSCALE_FILL_DEFAULT[0];

        map->cMap[y][x] = color;
    }
}
