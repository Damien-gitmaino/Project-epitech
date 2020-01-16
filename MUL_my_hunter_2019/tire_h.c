/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** tire_h
*/

#include "include/params.h"

void tiret_h(void)
{
    my_printf("USAGE:\n\tmy_hunter is a shooting game, the goal being to kill");
    my_printf("as many enemies as possible, attention you only had three life");
    my_printf(".\n\nDESCRIPTION:\n\tto close the window there are two possibl");
    my_printf("e choices either the ESC key or the cross at the top right.\n");
    my_printf("\tthe left mouse click is the shot.\n\tpress p to pause\n\tech");
    my_printf("ap allows the closing of the window and games.\n\tbe careful ");
    my_printf("there is audio\n\n\t\tGOOD GAME!\n");
}

void draw_curseur(struct params_play *go)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(go->window);
    sfVector2f vec;

    vec.x = mouse.x - 25;
    vec.y = mouse.y - 25;
    sfRenderWindow_drawSprite(go->window, go->sprite_mouse, NULL);
    sfSprite_setPosition(go->sprite_mouse, vec);
}

void music(struct params_play *go)
{
    go->music = sfMusic_createFromFile("Super Mario Bros Soundtrack.ogg");
    sfMusic_play(go->music);
}

void loop_infinty(struct valeur_init *init, struct params_play *go,
                char **image)
{
    sfVector2f vec = {700, 300};

    go->font = sfFont_createFromFile("BADABB__.TTF");
    go->print_pause = sfText_create();
    sfText_setString(go->print_pause, "PAUSE");
    sfText_setCharacterSize(go->print_pause, 200);
    sfText_setFont(go->print_pause, go->font);
    sfText_setPosition(go->print_pause, vec);
    loop(go, image, init);
    destroy(go, init);
}