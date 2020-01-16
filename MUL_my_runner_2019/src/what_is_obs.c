/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** what_is_obs
*/

#include "runner.h"

void read_map(struct tab *tab)
{
    for (int i = 0; i < tab->obs.y_map; i++)
        if (tab->obs.map[i][tab->obs.index_map_x] == '2')
            tab->obs.box = 1;
        else if (tab->obs.map[i][tab->obs.index_map_x] == '3')
            tab->obs.pic = 1;
    tab->obs.index_map_x += 1;
    tab->score += 100;
    sfText_setString(tab->t_score, my_supergetnbr(tab->score));
    if (tab->obs.index_map_x >= tab->obs.x_map && tab->play_mode == 1) {
        tab->obs.index_map_x = 0;
        tab->map.speed *= 0.1;
    } else if (tab->obs.index_map_x > tab->obs.x_map && tab->play_mode == 0)
        game_win(tab);
}
