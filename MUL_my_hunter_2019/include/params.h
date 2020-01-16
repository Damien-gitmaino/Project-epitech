/*
** EPITECH PROJECT, 2019
** C_graphical_p_boostramp_2019
** File description:
** params
*/

#ifndef PARAMS_H_
#define PARAMS_H_

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include <time.h>

struct params_play
{
    sfRenderWindow* window;
    sfTexture* texture;
    sfSprite* sprite;
    sfSprite* sprite_copa;
    sfSprite* sprite_mouse;
    sfText* text_score;
    sfText* score;
    sfText* print_pause;
    sfText* life;
    sfMusic* music;
    sfText* life_score;
    sfEvent event;
    sfFont* font;
    sfMouseButtonEvent mouse;
};

struct valeur_init
{
    float x;
    int y;
    sfIntRect rect;
    sfClock* clock;
    sfVector2f vector;
    int score;
    int game_over;
    float acc;
    int score_app;
};

struct menu
{
    sfRenderWindow* window;
    sfFont* font;
    sfText* text;
    sfSprite* menu_sprite;
    sfEvent event;
};

sfSprite* display_sripte(int index, char **image);
void draw_curseur(struct params_play *go);
int manage_mouse_click(sfMouseButtonEvent mouse_lol, struct valeur_init *init,
                        struct params_play *go);
void print_res(struct valeur_init *init);
void draw_sprite_coopa(struct params_play *go, struct valeur_init *init,
                            sfVector2f vector);
int menu(void);
void res_coord(struct valeur_init *init);
void tiret_h(void);
void sprite_coopa(struct valeur_init *init, char **image, sfClock *clock);
int display_sheet_anime_coopa(int x, int y);
void print_text(struct params_play *go);
char *my_supergetnbr(int nb);
void print_life(struct params_play *go, struct valeur_init *init);
void dispay_h(struct params_play *go, int ac, char **av);
void pause(struct params_play *go, struct valeur_init *init, sfClock* clock,
            char **image);
void loop(struct params_play *go, char **image, struct valeur_init *init);
void destroy(struct params_play *go, struct valeur_init *init);
void render(struct params_play *go, char **image,
    struct valeur_init *init, sfClock *clock);
void initialisation(struct valeur_init *init);
void music(struct params_play *go);
void loop_infinty(struct valeur_init *init, struct params_play *go,
                char **image);

#endif /* !PARAMS_H_ */
