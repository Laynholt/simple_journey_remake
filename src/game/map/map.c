#include "map.h"

// Возвращает полный размер карты (размер карты, карты облаков, деревьев...) 
uint64_t map_get_map_fullsize(const Map* map)
{
    return (map->iMapHeight * sizeof(uchar*)) + (map->iMapSize * sizeof(uchar));
}

// Выделение памяти под карту
uchar** map_allocate_memory(uint64_t allocate_size)
{
    return (uchar**)malloc(allocate_size);
}

// Создание карты (0 - ошибка / 1 - создание успешно)
int16_t map_create(Map* map)
{
    map->iMapSize = map->iMapWidth * map->iMapHeight;

    uchar** raw_memory = map_allocate_memory(map_get_map_fullsize(map));

    if (raw_memory != NULL)
    {
        // Разбивка под новый массив map
        uchar* start = (uchar*)raw_memory + (map->iMapHeight * sizeof(uchar*));
        for(int16_t i = 0; i < map->iMapHeight; ++i)
        {
            raw_memory[i] = start + i * map->iMapWidth;
        }

        // Заполняем фон карты
        map_fill(map, raw_memory, MAP_FULL_FILL_WITH_HORIZ, 0, '.');

        // Копируем старую карту в новую
        if (map->cMap != NULL)
        {
            // Копируем построчно для каждой высоты
            for(int16_t i = 0; i < map->iMapHeight; ++i)
            {
                memcpy(raw_memory[i], map->cMap[i], map->iMapWidthOld);
            }

            map_destruct(map);
        }

        map->cMap = raw_memory;

        // Генерация территории
        //map_generate()
        
        map->iMapWidthOld = map->iMapWidth;
        map->iMapHeightOld = map->iMapHeight;
        return 1;
    }
    return 0;
}

// Удаление карты
void map_destruct(Map* map)
{
    if (map->cMap)
        free(map->cMap);
}

// Заполение фона карты
void map_fill(Map* map, uchar** background, int16_t fill_type, int16_t fill_row, uchar symbol)
{
    if (MAP_FULL_FILL)
    {
        memset(*background, symbol, map->iMapSize);
    }
    else if (MAP_FULL_FILL_WITH_HORIZ)
    {
        memset(*background, symbol, map->iMapSize);
        memset(background[map->iMapHeight / 2], '=', map->iMapWidth);
    }
    else if (MAP_FILL_ROW)
    {
        memset(background[fill_row], symbol, map->iMapWidth);
    }
}

// Отображение карты
void map_show_frame(Map* map, Point* pCameraPosition)
{
    uchar row[SCREEN_WIDTH + 1];
    
    uint16_t y = pCameraPosition->y + map->iMapHeight;
    for(uint16_t i = pCameraPosition->y; i < y; ++i)
    {
        uint32_t k = 0;
        uint32_t x = pCameraPosition->x + map->iMapWidth;
        for(uint32_t j = pCameraPosition->x; j < x; ++j)
        {
            row[k++] = map->cMap[i][j];
        }
        row[k] = '\0';
        puts(row);
    }

    // printf("\n");
    // for(uint16_t i = 0; i < SCREEN_HEIGHT; ++i)
    // {
        // uint32_t k = 0;
        // for(uint32_t j = 0; j < SCREEN_WIDTH; ++j)
        // {
            // row[k++] = map->cMap[i][j];
        // }
        // row[k] = '\0';
        // puts(row);
    // }
}
