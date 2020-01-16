/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** display
*/

#include "runner.h"

sfSprite *display_sripte(int index, char **img)
{
    sfTexture* texture;
    sfSprite* sprite;

    texture = sfTexture_createFromFile(img[index], NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    free(texture);
    return (sprite);
}

void cod_i_display(struct tab *tab)
{
    sfVector2f vec2 = {100, tab->run.y_space};

    if (tab->run.space_activ == 1) {
        clock_runner_space(tab);
        clock__pos_space(tab);
        sfSprite_setTextureRect(tab->run.runner_space,
                                tab->run.rect_run_space);
        sfSprite_setPosition(tab->run.runner_space, vec2);
        sfRenderWindow_drawSprite(tab->disp.window,
                            tab->run.runner_space, NULL);
    } else {
        clock_runner(tab);
        sfSprite_setTextureRect(tab->run.runner, tab->run.rect_run);
        sfRenderWindow_drawSprite(tab->disp.window, tab->run.runner, NULL);
    }
}
