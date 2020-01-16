/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** draw_sprite_coopa
*/

#include "include/params.h"

void draw_sprite_coopa(struct params_play *go, struct valeur_init *init,
                            sfVector2f vector)
{
    sfRenderWindow_drawSprite(go->window, go->sprite_copa, NULL);
    sfSprite_setPosition(go->sprite_copa, vector);
}

void print_res(struct valeur_init *init)
{
    my_printf("\t\tGAME OVER\n");
    my_printf("SCORE: %i\n", init->score);
}

void res_coord(struct valeur_init *init)
{
    if (init->score_app == 5) {
        init->score_app = 0;
        init->acc += 0.2;
    }
    if (init->x >= 1920) {
        init->x = -105;
        init->y = rand()%500;
        init->game_over -= 1;
    }
    init->x += init->acc;
}
