#include "camera.h"

// Движение камеры
void camera_move(Camera* camera, Map* map, uint8_t iDirection)
{
    // Сохраняем позицию курсора
    printf("\x1b%d", 7);

    if (iDirection == MOVE_RIGHT)
    {
        int16_t ret_val = 1;
        if (camera->position.x + SCREEN_WIDTH + CAMERA_SPEED > map->iMapWidth)
        {
           map->iMapWidth += (SCREEN_WIDTH * NUMBER_OF_ALLOCATING_FRAMES);
           ++map->iBiomQuantity;
           ret_val = map_create(map);
           
           camera->iCurrentFrame = camera->position.x / SCREEN_WIDTH;
        }
           
        // if (ret_val)
        {
            camera->position.x += CAMERA_SPEED;
        }
    }
    else if (iDirection == MOVE_LEFT)
    {
        if (camera->position.x >= CAMERA_SPEED)
            camera->position.x -= CAMERA_SPEED;
        else if (camera->position.x > 0)
            --camera->position.x;
    }

    camera->iCurrentBiom = camera->position.x / BIOM_LENGTH;

    // Получаем сохраненную позицию курсора
    printf("\x1b%d", 8);
}
