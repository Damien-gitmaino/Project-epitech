/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** manage_mouse
*/

#include "include/params.h"

int manage_mouse_click(sfMouseButtonEvent mouse_lol, struct valeur_init *init,
                        struct params_play *go)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(go->window);
    sfVector2f vec;

    vec.x = mouse.x;
    vec.y = mouse.y;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (mouse.x >= init->x && mouse.x <= init->x + 130
            && mouse.y >= init->y && mouse.y <= init->y + 96)
            return (1);
    }
    return (0);
}
