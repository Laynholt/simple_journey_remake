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
    
    game->worldMap.iMapWidth = SCREEN_WIDTH;
    game->worldMap.iMapHeight = SCREEN_HEIGHT;
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
            else if (keydown(KEY_RIGHT))
            {    
                camera_move(&game->camera, &game->worldMap, MOVE_RIGHT);
                map_show_frame(&game->worldMap, &game->camera.position);
            }
            else if (keydown(KEY_LEFT))
            {
                camera_move(&game->camera, &game->worldMap, MOVE_LEFT);
                map_show_frame(&game->worldMap, &game->camera.position);
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

