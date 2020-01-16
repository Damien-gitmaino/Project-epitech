/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** initialisation_sprite_image
*/

#include "runner.h"

void init_plus(struct tab *tab, char **image)
{
    sfVector2f vec2 = {tab->x_p, tab->run.y_space};
    sfVector2f vec = {0, 2};

    tab->map.water = sfSprite_create();
    sfSprite_setTexture(tab->map.water, tab->map.tex_water, sfTrue);
    tab->map.boat = display_sripte(3, image);
    tab->map.tex_street = sfTexture_createFromFile(image[4], NULL);
    sfTexture_setRepeated(tab->map.tex_street, sfTrue);
    tab->map.stret = sfSprite_create();
    sfSprite_setTexture(tab->map.stret, tab->map.tex_street, sfTrue);
    tab->run.runner = display_sripte(5, image);
    tab->run.runner_space = display_sripte(6, image);
    tab->obs.sprite_obs = display_sripte(7, image);
    sfSprite_setPosition(tab->run.runner, vec2);
    sfSprite_setPosition(tab->run.runner_space, vec2);
    sfSprite_setPosition(tab->map.stret, vec);
}

void initialisation_sprite(struct tab *tab)
{
    char *image[8] = {"./image.png/nuage.png", "./image.png/map_after.png",
                        "./image.png/water_is_coming.png",
                        "./image.png/boat.png", "./image.png/street.png",
                        "./image.png/runner_2.png",
                        "./image.png/runner_2_space.png",
                        "./image.png/obstacle_1.png"};

    tab->map.tex = sfTexture_createFromFile(image[0], NULL);
    sfTexture_setRepeated(tab->map.tex, sfTrue);
    tab->map.sprite_map_back = sfSprite_create();
    sfSprite_setTexture(tab->map.sprite_map_back, tab->map.tex, sfTrue);
    tab->map.tex_after = sfTexture_createFromFile(image[1], NULL);
    sfTexture_setRepeated(tab->map.tex_after, sfTrue);
    tab->map.sprite_map_after = sfSprite_create();
    sfSprite_setTexture(tab->map.sprite_map_after,
    tab->map.tex_after, sfTrue);
    tab->map.tex_water = sfTexture_createFromFile(image[2], NULL);
    sfTexture_setRepeated(tab->map.tex_water, sfTrue);
    init_plus(tab, image);
}

void initialisation_two(struct tab *tab)
{
    tab->run.space_activ = 0;
    tab->map.rect_street.left = 0;
    tab->map.rect_street.height = 1080;
    tab->map.rect_street.width = 1920;
    tab->map.x_boat = -342;
    tab->map.rand_boat = 0;
    tab->run.rect_run.top = 0;
    tab->run.rect_run.left = 0;
    tab->run.rect_run.height = 125;
    tab->run.rect_run.width = 109;
    tab->run.rect_run_space.top = 0;
    tab->run.rect_run_space.left = 0;
    tab->run.rect_run_space.height = 125;
    tab->run.rect_run_space.width = 120;
    tab->map.speed = 0.0001;
    tab->x_p = 100;
    tab->loop = 1;
    set_text(tab);
}

void initialisation(struct tab *tab)
{
    tab->map.rect_map_back.top = 0;
    tab->map.rect_map_back.left = 0;
    tab->map.rect_map_back.height = 1080;
    tab->map.rect_map_back.width = 1920;
    tab->map.rect_map_after.top = 0;
    tab->map.rect_map_after.left = 0;
    tab->map.rect_map_after.height = 1080;
    tab->map.rect_map_after.width = 1920;
    tab->map.rect_water.top = 0;
    tab->map.rect_water.left = 0;
    tab->map.rect_water.height = 1080;
    tab->map.rect_water.width = 1920;
    tab->map.rect_street.top = 0;
    tab->run.y_space = 895;
    tab->obs.index_map_x = 0;
    tab->obs.x_spawn = 1920;
    tab->obs.box = 0;
    tab->score = 0;
    initialisation_two(tab);
}
