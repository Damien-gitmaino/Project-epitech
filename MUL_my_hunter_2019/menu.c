/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** menu
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Mouse.h>
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include "include/params.h"

sfSprite* display_sripte(int index, char **image);

int manage_mouse_menu(struct menu menu)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(menu.window);
    sfVector2f vec;

    vec.x = mouse.x;
    vec.y = mouse.y;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (mouse.x >= 276 && mouse.x <= 496
            && mouse.y >= 236 && mouse.y <= 346)
                return (1);
    }
    return (0);
}

void relod(struct menu menu)
{
    sfRenderWindow_clear(menu.window, sfBlack);
    sfRenderWindow_drawSprite(menu.window, menu.menu_sprite, NULL);
    sfRenderWindow_drawText(menu.window, menu.text, NULL);
    sfRenderWindow_display(menu.window);
}

void des_menu(struct menu menu)
{
    sfText_destroy(menu.text);
    sfFont_destroy(menu.font);
    sfSprite_destroy(menu.menu_sprite);
    sfRenderWindow_destroy(menu.window);
}

int loop_menu(struct menu menu)
{
    while (sfRenderWindow_isOpen(menu.window)) {
        while (sfRenderWindow_pollEvent(menu.window, &menu.event))
            if (manage_mouse_menu(menu) == 1)
                sfRenderWindow_close(menu.window);
            if (menu.event.key.code == sfKeyEscape ||
                menu.event.type == sfEvtClosed) {
                des_menu(menu);
                return (1);
            }
        relod(menu);
    }
    des_menu(menu);
}

int menu(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfVector2f lol = {225, 50};
    struct menu menu;
    char *img[1] = {"menu.png"};

    menu.window = sfRenderWindow_create(mode, "MENU", sfResize | sfClose, NULL);
    menu.menu_sprite = display_sripte(0, img);
    menu.font = sfFont_createFromFile("BADABB__.TTF");
    if (!menu.font)
        return EXIT_FAILURE;
    menu.text = sfText_create();
    sfText_setString(menu.text, "MY HUNTER");
    sfText_setCharacterSize(menu.text, 100);
    sfText_setFont(menu.text, menu.font);
    sfText_setPosition(menu.text, lol);
    if (loop_menu(menu) == 1)
        return (1);
    return (0);
}
