/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** tools_text
*/

#include "include/params.h"

void print_text(struct params_play *go)
{
    sfVector2f vec = {100, 925};
    sfVector2f vec2 = {1600, 925};

    go->text_score = sfText_create();
    sfText_setString(go->text_score, "SCORE :");
    sfText_setCharacterSize(go->text_score, 70);
    sfText_setFont(go->text_score, go->font);
    sfText_setPosition(go->text_score, vec);
    go->score = sfText_create();
    go->life = sfText_create();
    sfText_setString(go->life, "LIFE :");
    sfText_setCharacterSize(go->life, 70);
    sfText_setFont(go->life, go->font);
    sfText_setPosition(go->life, vec2);
    go->life_score = sfText_create();
}

void print_life(struct params_play *go, struct valeur_init *init)
{
    sfVector2f vec = {300, 925};
    sfVector2f vec2 = {1750, 925};

    sfText_setString(go->score, my_supergetnbr(init->score));
    sfText_setCharacterSize(go->score, 70);
    sfText_setFont(go->score, go->font);
    sfText_setPosition(go->score, vec);
    sfText_setString(go->life_score, my_supergetnbr(init->game_over));
    sfText_setCharacterSize(go->life_score, 70);
    sfText_setFont(go->life_score, go->font);
    sfText_setPosition(go->life_score, vec2);
    sfRenderWindow_drawText(go->window, go->score, NULL);
    sfRenderWindow_drawText(go->window, go->life, NULL);
    sfRenderWindow_drawText(go->window, go->life_score, NULL);
}

void dispay_h(struct params_play *go, int ac, char **av)
{
    srand(time(0));
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && my_strlen(av[1]) == 2)
        tiret_h();
}

int display_pause(struct params_play *go, int loop)
{
    sfRenderWindow_clear(go->window, sfBlack);
    sfRenderWindow_drawSprite(go->window, go->sprite, NULL);
    sfRenderWindow_drawSprite(go->window, go->sprite_copa, NULL);
    sfRenderWindow_drawSprite(go->window, go->sprite_mouse, NULL);
    sfRenderWindow_drawText(go->window, go->print_pause, NULL);
    sfRenderWindow_display(go->window);
    while (sfRenderWindow_pollEvent(go->window, &go->event))
        if (go->event.type == sfEvtKeyPressed)
            if (go->event.key.code == sfKeyP)
                loop = 0;
    return (loop);
}

void pause(struct params_play *go, struct valeur_init *init, sfClock* clock,
                char **image)
{
    int loop = 1;

    if (go->event.type == sfEvtKeyPressed && go->event.key.code == sfKeyP) {
            while (loop) {
                if (go->event.key.code == sfKeyEscape ||
                        go->event.type == sfEvtClosed) {
                    sfRenderWindow_close(go->window);
                    loop = 0;
                }
                sfMusic_pause(go->music);
                loop = display_pause(go, loop);
            }
            sfMusic_play(go->music);
            sfClock_restart(clock);
        }
}