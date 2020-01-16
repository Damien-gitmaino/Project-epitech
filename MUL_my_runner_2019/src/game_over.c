/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** game_over
*/

#include "runner.h"

void clock_over(sfClock* clock_game_over, struct tab *tab)
{
    sfTime time = sfClock_getElapsedTime(clock_game_over);
    float sec = (float) time.microseconds / 10000000.0;

    if (sec > 0.629667) {
        sfRenderWindow_close(tab->disp.window);
        destroy(tab);
        exit (0);
    }
}

void cod_i_over(struct tab *tab, sfSprite *sprite)
{
    sfRenderWindow_drawSprite(tab->disp.window, tab->map.water, NULL);
    sfRenderWindow_drawSprite(tab->disp.window,
                tab->map.sprite_map_after, NULL);
    sfRenderWindow_drawSprite(tab->disp.window, sprite, NULL);
    sfRenderWindow_drawText(tab->disp.window, tab->text, NULL);
    sfRenderWindow_drawText(tab->disp.window, tab->t_score, NULL);
}

void render_over(struct tab *tab, sfSprite *sprite, sfClock* clock_game_over,
                sfVector2f vec)
{
    sfRenderWindow_clear(tab->disp.window, sfBlack);
    clock_over(clock_game_over, tab);
    clock_map_back(tab);
    clock_map_after(tab);
    clock_map_water(tab);
    clock_boat(tab);
    sfSprite_setTextureRect(tab->map.sprite_map_back,
                            tab->map.rect_map_back);
    sfSprite_setTextureRect(tab->map.sprite_map_after,
                        tab->map.rect_map_after);
    sfSprite_setTextureRect(tab->map.water, tab->map.rect_water);
    sfSprite_setTextureRect(tab->map.stret, tab->map.rect_street);
    sfSprite_setPosition(tab->map.boat, vec);
    sfRenderWindow_drawSprite(tab->disp.window,
                    tab->map.sprite_map_back, NULL);
    cod_i_over(tab, sprite);
    sfRenderWindow_display(tab->disp.window);
}

void game_over(struct tab *tab)
{
    sfClock* clock_game_over = sfClock_create();
    sfTexture* texture;
    sfSprite* sprite;
    sfVector2f vec = {tab->map.x_boat, 570};

    texture = sfTexture_createFromFile("./image.png/game_over.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (tab->loop) {
        while (sfRenderWindow_pollEvent(tab->disp.window, &tab->evt.event)) {
            if (tab->evt.event.key.code == sfKeyEscape ||
                tab->evt.event.type == sfEvtClosed) {
                sfRenderWindow_close(tab->disp.window);
                destroy(tab);
                exit (0);
            }
        }
        render_over(tab, sprite, clock_game_over, vec);
    }
}
