/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** pause
*/

#include "runner.h"

void draw_display_pause(struct tab *tab)
{
    sfRenderWindow_clear(tab->disp.window, sfBlack);
    sfSprite_setTextureRect(tab->map.sprite_map_back,
                            tab->map.rect_map_back);
    sfSprite_setTextureRect(tab->map.sprite_map_after,
                        tab->map.rect_map_after);
    sfSprite_setTextureRect(tab->map.water, tab->map.rect_water);
    sfSprite_setTextureRect(tab->map.stret, tab->map.rect_street);
    sfRenderWindow_drawSprite(tab->disp.window,
                    tab->map.sprite_map_back, NULL);
    sfRenderWindow_drawSprite(tab->disp.window, tab->map.water, NULL);
    sfRenderWindow_drawSprite(tab->disp.window,
                tab->map.sprite_map_after, NULL);
    if (tab->map.rand_boat == 0)
        sfRenderWindow_drawSprite(tab->disp.window, tab->map.boat, NULL);
    if (tab->run.space_activ == 1)
        sfRenderWindow_drawSprite(tab->disp.window,
                            tab->run.runner_space, NULL);
    else
        sfRenderWindow_drawSprite(tab->disp.window, tab->run.runner, NULL);
}

int display_pause(struct tab *tab, int loop, sfSprite* sprite)
{
    draw_display_pause(tab);
    sfRenderWindow_drawSprite(tab->disp.window, tab->map.stret, NULL);
    sfRenderWindow_drawSprite(tab->disp.window, tab->obs.sprite_obs, NULL);
    sfRenderWindow_drawSprite(tab->disp.window, sprite, NULL);
    sfRenderWindow_drawText(tab->disp.window, tab->text, NULL);
    sfRenderWindow_drawText(tab->disp.window, tab->t_score, NULL);
    sfRenderWindow_display(tab->disp.window);
    while (sfRenderWindow_pollEvent(tab->disp.window, &tab->evt.event))
        if (tab->evt.event.type == sfEvtKeyPressed)
            if (tab->evt.event.key.code == sfKeyP)
                loop = 0;
    return (loop);
}

void cod_i_pause(struct tab *tab, sfTexture* texture, sfSprite* sprite)
{
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    sfMusic_play(tab->music);
}

void pause_game(struct tab *tab)
{
    sfTexture* texture;
    sfSprite* sprite;

    if (tab->evt.event.type == sfEvtKeyPressed
        && tab->evt.event.key.code == sfKeyP) {
        texture = sfTexture_createFromFile("./image.png/menu_pause.png",
        NULL);
        sprite = sfSprite_create();
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfMusic_pause(tab->music);
        while (tab->loop) {
            if (tab->evt.event.key.code == sfKeyEscape ||
                    tab->evt.event.type == sfEvtClosed) {
                sfRenderWindow_close(tab->disp.window);
                tab->loop = 0;
            }
            tab->loop = display_pause(tab, tab->loop, sprite);
        }
        cod_i_pause(tab, texture, sprite);
    }
}