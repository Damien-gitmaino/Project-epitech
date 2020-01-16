/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** display
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "params.h"

sfSprite *display_sripte(int index, char **image)
{
    sfTexture* texture;
    sfSprite* sprite;

    texture = sfTexture_createFromFile(image[index], NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}
