/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** mouvemt
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Mouse.h>
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include "include/params.h"

void sprite_coopa(struct valeur_init *init, char **image, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float sec = (float) time.microseconds / 10000000.0;

    if (sec > 0.02) {
        init->rect.left += 101;
        sfClock_restart(clock);
    }
    if (init->rect.left == 505)
        init->rect.left = 0;
}
