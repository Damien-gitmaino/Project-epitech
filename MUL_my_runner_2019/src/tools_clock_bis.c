/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** tools_clock2
*/

#include "runner.h"

void clock_street(struct tab *tab)
{
    sfTime time = sfClock_getElapsedTime(tab->map.clock_plat);
    float sec = (float) time.microseconds / 10000000.0;

    if (sec > tab->map.speed) {
        tab->map.rect_street.left += 1;
        sfClock_restart(tab->map.clock_plat);
    }
}

void clock_runner_space(struct tab *tab)
{
    sfTime time = sfClock_getElapsedTime(tab->run.run_clock_space);
    float sec = (float) time.microseconds / 10000000.0;

    if (sec > 0.01) {
        tab->run.rect_run_space.left += 119;
        sfClock_restart(tab->run.run_clock_space);
    }
    if (tab->run.rect_run_space.left >= 900) {
        tab->run.rect_run_space.left = 0;
        tab->run.rect_run.left = 0;
        sfClock_restart(tab->run.run_clock);
        tab->run.space_activ = 0;
        tab->indicat = 0;
        tab->run.y_space = 895;
    }
}

void clock_spawn_obs(struct tab *tab)
{
    sfTime time = sfClock_getElapsedTime(tab->obs.clock_spawn);
    float sec = (float) time.microseconds / 10000000.0;

    if (sec > tab->map.speed) {
        tab->obs.x_spawn -= 1;
        sfClock_restart(tab->obs.clock_spawn);
    }
    if (tab->obs.x_spawn == -86) {
        tab->obs.x_spawn = 1920;
        tab->obs.box = 0;
        tab->run.y_space = 895;
        read_map(tab);
    }
}

void clock__pos_space(struct tab *tab)
{
    sfTime time = sfClock_getElapsedTime(tab->run.pos_space);
    float sec = (float) time.microseconds / 10000000.0;

    if (tab->indicat == 1)
        tab->run.y_space = 895;
    else if (sec > 0.0001) {
        if (tab->run.rect_run_space.left < 450)
            tab->run.y_space -= 1;
        else if (tab->run.rect_run_space.left > 450)
            tab->run.y_space += 1;
        if (tab->run.y_space == 895)
            tab->indicat = 1;
        sfClock_restart(tab->run.pos_space);
    }
}
