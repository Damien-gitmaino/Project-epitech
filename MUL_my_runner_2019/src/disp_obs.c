/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** disp_obs
*/

#include "runner.h"
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include <time.h>

void cod_i_tireh(void)
{
    my_printf("MAP:\n");
    my_printf("\tTo create a map, use this 0, 1 and 2:\n");
    my_printf("\t\t0: represents nothing\n");
    my_printf("\t\t1: represents the ground\n");
    my_printf("\t\t2: represents a box\n");
    my_printf("\texample:\n\t\t02200202202002\n\t\t11111111111111\n");
    my_printf("GOAL:\n");
    my_printf("\tThe goal of my_runner is to avoid obstacles in");
    my_printf("the way of your character.\n");
}

void print_tireh(struct tab *tab)
{
    my_printf("USAGE:\n");
    my_printf("\t./my_runner {FLAG} {MAP}\n");
    my_printf("FLAGS:\n");
    my_printf("\t-i\tInfinity mode\tThe map runs in a loop.\n");
    my_printf("\t-m\tMap mode\tThe game lasts the time of a map.\n");
    my_printf("\t-h\tInfo mode\tDiplay information of programme.\n");
    my_printf("KEYS:\n");
    my_printf("\tSPACE\tThe space key allows you to jump the character.\n");
    my_printf("\tESCAPE\tThe escape key quits the game.\n");
    my_printf("\tP\tPut game in pause. Represse P for play game.\n");
    cod_i_tireh();
}

void disp_spaw_obs(struct tab *tab)
{
    sfVector2f vec_obs = {tab->obs.x_spawn, 931};

    clock_spawn_obs(tab);
    if (tab->obs.box == 1) {
        check_obs(tab);
        sfSprite_setPosition(tab->obs.sprite_obs, vec_obs);
        sfRenderWindow_drawSprite(tab->disp.window,
                                tab->obs.sprite_obs, NULL);
    }
}

void check_obs(struct tab *tab)
{
    sfVector2f vec = sfSprite_getPosition(tab->run.runner_space);

    if (tab->obs.x_spawn == 100 + 109 && vec.y + 126 > 931)
        game_over(tab);
    else if (vec.y <= 931 && tab->obs.x_spawn <= vec.x + 85
    && vec.x <= tab->obs.x_spawn) {
        tab->run.y_space = 810;
    }
}

int tireh(char *str, struct tab *tab)
{
    if (str == NULL) {
        my_printf("MISSING ALL !!!!, please conslute -h!\n");
        return (84);
    }
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] != '-' && str[i] != 'h' && str[i] != 'i' && str[i] != 'm')
            || i == 2) {
            my_printf("FLAG ERROR, pleave give a good flags for play game\n");
            exit (84);
        }
    if (str[0] == '-' && str[1] == 'h' && my_strlen(str) == 2) {
        print_tireh(tab);
        return (0);
    }
    else if (str[0] == '-' && str[1] == 'i' && my_strlen(str) == 2)
        tab->play_mode = 1;
    else
        tab->play_mode = 0;
}
