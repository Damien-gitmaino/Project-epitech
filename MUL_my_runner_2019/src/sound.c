/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** runner
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

void set_clock(struct tab *tab)
{
    tab->map.clock_map_back = sfClock_create();
    tab->map.clock_map_after = sfClock_create();
    tab->map.clock_water = sfClock_create();
    tab->map.clock_boat = sfClock_create();
    tab->run.run_clock = sfClock_create();
    tab->run.run_clock_space = sfClock_create();
    tab->map.clock_plat = sfClock_create();
    tab->obs.clock_spawn = sfClock_create();
    tab->run.pos_space = sfClock_create();
}

void initialisation_sound(struct tab *tab)
{
    tab->music = sfMusic_createFromFile("2.ogg");
    tab->jump_music = sfMusic_createFromFile("jump_sound.ogg");
    sfMusic_play(tab->music);
}

void set_text(struct tab *tab)
{
    sfFont* font;
    sfVector2f vec = {1300, 1020};
    sfVector2f vec2 = {1600, 1020};

    font = sfFont_createFromFile("04B_30__.TTF");
    tab->text = sfText_create();
    tab->t_score = sfText_create();
    sfText_setString(tab->text, "SCORE:");
    sfText_setFont(tab->text, font);
    sfText_setFont(tab->t_score, font);
    sfText_setCharacterSize(tab->text, 50);
    sfText_setCharacterSize(tab->t_score, 50);
    sfText_setPosition(tab->text, vec);
    sfText_setPosition(tab->t_score, vec2);
}
