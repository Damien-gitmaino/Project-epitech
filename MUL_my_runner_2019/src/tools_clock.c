/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** tools_clock
*/

#include "runner.h"

void clock_map_back(struct tab *tab)
{
    sfTime time = sfClock_getElapsedTime(tab->map.clock_map_back);
    float sec = (float) time.microseconds / 10000000.0;

    if (sec > 0.02) {
        tab->map.rect_map_back.left += 1;
        sfClock_restart(tab->map.clock_map_back);
    }
}

void clock_map_after(struct tab *tab)
{
    sfTime time = sfClock_getElapsedTime(tab->map.clock_map_after);
    float sec = (float) time.microseconds / 10000000.0;

    if (sec > 0.01) {
        tab->map.rect_map_after.left += 1;
        sfClock_restart(tab->map.clock_map_after);
    }
}

void clock_map_water(struct tab *tab)
{
    sfTime time = sfClock_getElapsedTime(tab->map.clock_water);
    float sec = (float) time.microseconds / 10000000.0;

    if (sec > 0.01) {
        tab->map.rect_water.left -= 1;
        sfClock_restart(tab->map.clock_water);
    }
}

void clock_boat(struct tab *tab)
{
    sfTime time = sfClock_getElapsedTime(tab->map.clock_boat);
    float sec = (float) time.microseconds / 10000000.0;

    if (tab->map.rand_boat != 0)
        tab->map.rand_boat = rand()%25;
    else if (sec > 0.001) {
        tab->map.x_boat += 1;
        sfClock_restart(tab->map.clock_boat);
    }
    if (tab->map.x_boat == 1920) {
        tab->map.x_boat = -342;
        tab->map.rand_boat = rand()%25;
    }
}

void clock_runner(struct tab *tab)
{
    sfTime time = sfClock_getElapsedTime(tab->run.run_clock);
    float sec = (float) time.microseconds / 10000000.0;

    if (sec > 0.01) {
        tab->run.rect_run.left += 109;
        sfClock_restart(tab->run.run_clock);
    }
    if (tab->run.rect_run.left >= 1100)
        tab->run.rect_run.left = 0;
}