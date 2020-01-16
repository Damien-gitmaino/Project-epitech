/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** main
*/

#include "runner.h"

void render_two(struct tab *tab)
{
    sfRenderWindow_drawSprite(tab->disp.window,
                        tab->map.sprite_map_back, NULL);
    sfRenderWindow_drawSprite(tab->disp.window, tab->map.water, NULL);
    sfRenderWindow_drawSprite(tab->disp.window,
                    tab->map.sprite_map_after, NULL);
    if (tab->map.rand_boat == 0)
        sfRenderWindow_drawSprite(tab->disp.window, tab->map.boat, NULL);
    sfRenderWindow_drawSprite(tab->disp.window, tab->map.stret, NULL);
    sfRenderWindow_drawText(tab->disp.window, tab->text, NULL);
    sfRenderWindow_drawText(tab->disp.window, tab->t_score, NULL);
    disp_spaw_obs(tab);
    cod_i_display(tab);
    sfRenderWindow_display(tab->disp.window);
}

void render(struct tab *tab)
{
    sfVector2f vec = {tab->map.x_boat, 570};

    tab->loop = 1;
    sfRenderWindow_clear(tab->disp.window, sfBlack);
    clock_map_back(tab);
    clock_map_after(tab);
    clock_map_water(tab);
    clock_boat(tab);
    clock_street(tab);
    sfSprite_setTextureRect(tab->map.sprite_map_back, tab->map.rect_map_back);
    sfSprite_setTextureRect(tab->map.sprite_map_after,
                            tab->map.rect_map_after);
    sfSprite_setTextureRect(tab->map.water, tab->map.rect_water);
    sfSprite_setTextureRect(tab->map.stret, tab->map.rect_street);
    sfSprite_setPosition(tab->map.boat, vec);
    render_two(tab);
}

void destroy(struct tab *tab)
{
    sfMusic_destroy(tab->jump_music);
    sfMusic_destroy(tab->music);
    sfClock_destroy(tab->map.clock_map_back);
    sfClock_destroy(tab->map.clock_map_after);
    sfClock_destroy(tab->map.clock_water);
    sfClock_destroy(tab->map.clock_boat);
    sfClock_destroy(tab->run.run_clock);
    sfClock_destroy(tab->run.run_clock_space);
    sfClock_destroy(tab->map.clock_plat);
    sfClock_destroy(tab->obs.clock_spawn);
    sfClock_destroy(tab->run.pos_space);
    sfSprite_destroy(tab->obs.sprite_obs);
    sfSprite_destroy(tab->run.runner);
    sfSprite_destroy(tab->run.runner_space);
    sfSprite_destroy(tab->map.stret);
    sfSprite_destroy(tab->map.boat);
    sfSprite_destroy(tab->map.water);
    sfSprite_destroy(tab->map.sprite_map_after);
    sfSprite_destroy(tab->map.sprite_map_back);
    sfRenderWindow_destroy(tab->disp.window);
}

void loop(struct tab *tab)
{
    set_clock(tab);
    initialisation_sound(tab);
    while (sfRenderWindow_isOpen(tab->disp.window)) {
        while (sfRenderWindow_pollEvent(tab->disp.window, &tab->evt.event)) {
            if (tab->evt.event.key.code == sfKeyEscape ||
                tab->evt.event.type == sfEvtClosed)
                sfRenderWindow_close(tab->disp.window);
            if ((sfKeyboard_isKeyPressed(sfKeySpace) ||
            sfKeyboard_isKeyPressed(sfKeyUp)) && tab->run.space_activ == 0) {
                tab->run.space_activ = 1;
                sfMusic_play(tab->jump_music);
            }
            pause_game(tab);
        }
        render(tab);
    }
    destroy(tab);
}

int main(int ac, char **av)
{
    sfVideoMode mode = {1920, 1080, 32};
    struct tab tab;

    if (tireh(av[1], &tab) == 84)
        return (84);
    if (ac < 3) {
        my_printf("Missing map, please create or give map\n");
        return (84);
    } else if (ac > 3) {
        my_printf("Too much argument\n");
        return (84);
    srand(time(0));
    tab.disp.window = sfRenderWindow_create(mode, "MY_RUNNER", sfResize
                                            | sfClose, NULL);
    initialisation(&tab);
    initialisation_sprite(&tab);
    fs_print_first_line(av[2], &tab);
    read_map(&tab);
    loop(&tab);
}
