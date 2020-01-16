/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_hunter
*/

#include "include/params.h"

void initialisation(struct valeur_init *init)
{
    init->rect.top = 0;
    init->rect.left = 0;
    init->rect.height = 130;
    init->rect.width = 96;
    init->x = -105;
    init->y = 0;
    init->score = 0;
    init->game_over = 3;
    init->acc = 0.3;
    init->score_app = 0;
}

void render(struct params_play *go, char **image,
    struct valeur_init *init, sfClock *clock)
{
    sfVector2f vector = {init->x, init->y};

    res_coord(init);
    sfRenderWindow_clear(go->window, sfBlack);
    sfRenderWindow_drawSprite(go->window, go->sprite, NULL);
    sfRenderWindow_drawText(go->window, go->text_score, NULL);
    sprite_coopa(init, image, clock);
    sfSprite_setTextureRect(go->sprite_copa, init->rect);
    draw_sprite_coopa(go, init, vector);
    draw_curseur(go);
    print_life(go, init);
    if (init->game_over == 0) {
        sfRenderWindow_close(go->window);
        print_res(init);
    }
    sfRenderWindow_display(go->window);
}

void destroy(struct params_play *go, struct valeur_init *init)
{
    sfMusic_destroy(go->music);
    sfFont_destroy(go->font);
    sfText_destroy(go->text_score);
    sfText_destroy(go->score);
    sfSprite_destroy(go->sprite_copa);
    sfSprite_destroy(go->sprite);
    sfRenderWindow_destroy(go->window);
}

void loop(struct params_play *go, char **image, struct valeur_init *init)
{
    go->sprite_copa = display_sripte(1, image);
    go->sprite_mouse = display_sripte(2, image);
    print_text(go);
    sfClock *clock = sfClock_create();
    sfRenderWindow_setMouseCursorVisible(go->window, sfFalse);
    while (sfRenderWindow_isOpen(go->window)) {
        while (sfRenderWindow_pollEvent(go->window, &go->event)) {
            if (go->event.key.code == sfKeyEscape ||
                go->event.type == sfEvtClosed)
                sfRenderWindow_close(go->window);
            else if (manage_mouse_click(go->event.mouseButton, init, go) == 1) {
                init->score += 100;
                init->score_app += 1;
                init->x = -105;
                init->y = rand()%500;
            }
            pause(go, init, clock, image);
        }
        render(go, image, init, clock);
    }
}

int main(int ac, char **av)
{
    sfVideoMode mode = {1920, 1080, 32};
    struct params_play go;
    struct valeur_init init;
    char *image[4] = {"prototype_map.png", "sprite_sheets_copa_fly.png",
            "curseur.png", "pause.png"};

    dispay_h(&go, ac, av);
    while (1) {
        music(&go);
        if (menu() == 1) {
            sfMusic_destroy(go.music);
            return (0);
        }
        initialisation(&init);
        go.window = sfRenderWindow_create(mode, "MY_HUNTER", sfResize
                                            | sfClose, NULL);
        go.sprite = display_sripte(0, image);
        loop_infinty(&init, &go, image);
    }
    return EXIT_SUCCESS;
}
