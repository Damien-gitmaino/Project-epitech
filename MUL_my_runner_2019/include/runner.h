/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** runner
*/

#ifndef RUNNER_H_
#define RUNNER_H_

/*
** Les includes
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include <time.h>

/*
** Les structures
*/
struct tab
{
    struct display
    {
        sfRenderWindow* window;
    } disp;
    struct event
    {
        sfEvent event;
    } evt;
    struct map
    {
        sfClock* clock_map_back;
        sfClock* clock_map_after;
        sfClock* clock_water;
        sfClock* clock_boat;
        sfClock* clock_plat;
        sfIntRect rect_map_back;
        sfIntRect rect_map_after;
        sfIntRect rect_water;
        sfIntRect rect_street;
        sfSprite *sprite_map_back;
        sfSprite *sprite_map_after;
        sfSprite *water;
        sfSprite *boat;
        sfSprite *stret;
        sfTexture *tex;
        sfTexture *tex_after;
        sfTexture *tex_water;
        sfTexture* tex_street;
        int x_boat;
        int rand_boat;
        float speed;
    } map;
    struct obstacle
    {
        sfSprite *sprite_obs;
        sfClock* clock_spawn;
        char **map;
        int x_obs;
        int x_map;
        int x_spawn;
        int y_map;
        int box;
        int pic;
        int index_map_x;
    } obs;
    struct character
    {
        sfClock* run_clock;
        sfClock* run_clock_space;
        sfClock* pos_space;
        sfIntRect rect_run_space;
        sfIntRect rect_run;
        sfSprite* runner;
        sfSprite* runner_space;
        int space_activ;
        int y_space;
    } run;
    int score;
    int loop;
    int play_mode;
    int indicat;
    int x_p;
    int y_p;
    sfMusic* music;
    sfMusic* jump_music;
    sfMusic* boum_music;
    sfText* text;
    sfText* t_score;
};

/*
** the Clock
*/

void clock_map_back(struct tab *tab);
void clock_map_after(struct tab *tab);
void clock_map_water(struct tab *tab);
void clock_boat(struct tab *tab);
void clock_runner(struct tab *tab);
void clock_runner_space(struct tab *tab);
void clock_street(struct tab *tab);
void clock_spawn_obs(struct tab *tab);
void clock__pos_space(struct tab *tab);

/*
** tools
*/

sfSprite *display_sripte(int index, char **img);
void read_map(struct tab *tab);
void fs_print_first_line(char const *filepath, struct tab *tab);
void disp_spaw_obs(struct tab *tab);
void check_obs(struct tab *tab);
void cod_i_display(struct tab *tab);
int tireh(char *str, struct tab *tab);
void destroy(struct tab *tab);
void game_over(struct tab *tab);
void game_win(struct tab *tab);
void pause_game(struct tab *tab);
void set_clock(struct tab *tab);
void repos_sp(struct tab *tab);
void set_text(struct tab *tab);

/*
** initialisation
*/

void initialisation_sprite(struct tab *tab);
void initialisation(struct tab *tab);
void initialisation_sound(struct tab *tab);

#endif /* !RUNNER_H_ */
