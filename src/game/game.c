#include "game.h"

// Обработчик сигналов, нужен также для клавиш
static sig_atomic_t is_exit = 0;
static void sighandler(int32_t sig)
{
    is_exit = 1;
}

int16_t game_create(Game* game)
{
    // Если у нас почему-то уже была создана игра
    if (game->worldMap.cMap)
        map_destruct(&game->worldMap);

    memset(&game->camera, 0, sizeof(Camera));
    
    game->worldMap.iMapWidth = SCREEN_WIDTH * NUMBER_OF_ALLOCATING_FRAMES;
    game->worldMap.iMapHeight = SCREEN_HEIGHT;
    game->worldMap.iBiomQuantity = 1;
    return map_create(&game->worldMap);
}

void game_start(Game* game)
{
    if (!game_create(game))
        return;
    map_show_frame(&game->worldMap, &game->camera.position);
    
    term_setup(sighandler);
    while(!is_exit)
    {
        if (kbhit())
        {
            if (keydown(KEY_ESC))
                is_exit = 1;
            else if (keydown(KEY_RIGHT) || keydown(KEY_D))
            {
                // game_show_info(game);
                camera_move(&game->camera, &game->worldMap, MOVE_RIGHT);
                map_show_frame(&game->worldMap, &game->camera.position);
                game_show_general_info(game);
            }
            else if (keydown(KEY_LEFT) || keydown(KEY_A))
            {
                game_show_info(game);
                camera_move(&game->camera, &game->worldMap, MOVE_LEFT);
                map_show_frame(&game->worldMap, &game->camera.position);
                game_show_general_info(game);
            }
        }

        usleep(15000);
    }
    term_restore();
    game_exit(game);
}

void game_exit(Game* game)
{
    if (game->worldMap.cMap)
        map_destruct(&game->worldMap);
   
    // Отчистка экрана 
    //printf("\x1b[%dJ", 2);
    printf("\nGame closed.\n");
}

void game_show_info(Game* game)
{
    // Сохраняем позицию курсора
    // printf("\x1b%d", 7);
    printf("\nCurrent Biom: [%s]", biom_get_biom_name(&game->worldMap, game->camera.iCurrentBiom));
}

void game_show_general_info(Game* game)
{
    static uint32_t click = 0;

    printf("\nCurrent size of map: [%lu] | Current camera row|col: [%u|%u] | Current frame/total [%u/%u] | Clicks [%u]\n",
            game->worldMap.iMapSize, game->camera.position.y, game->camera.position.x, game->camera.iCurrentFrame, 
            game->worldMap.iMapWidth / SCREEN_WIDTH, click += 1);
}
