/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** sokaban
*/

#ifndef SOKABAN_H_
#define SOKABAN_H_

#include <ncurses.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

struct valeur
{
    char **mesg;
    char **dup;
    int x_p;
    int y_p;
    int row;
    int col;
    int key;
    int loop;
    int nb_obj;
    int nb_x;
    int nb_o;
    int nub_col;
    int nub_line;
};

void tireh(void);
int count_number_n(char *str);
int my_stat(char const *file);
int count_number_colum(char *str);
void search_p(struct valeur *init, int nb_ligne, int nb_colum);
void moove_op(struct valeur *init);
void moove_down(struct valeur *init);
void moove_left(struct valeur *init);
void moove_right(struct valeur *init);
int game(int number_n, char *tmp,
        struct valeur *init);
int count_obj(struct valeur *init, int nb_ligne, int nb_colum);
int check_block(int nb_col, struct valeur *init);
void swap_right_one(struct valeur *init);
void swap_left_one(struct valeur *init);
void swap_op_one(struct valeur *init);
void swap_down_one(struct valeur *init);
int error_soko(char **map, int nb_ligne, int nb_colum);
void count_x_o(int nb_ligne, int nb_colum, struct valeur *init);
void check_without_o(int nb_ligne, int nb_colum, struct valeur *init);
void swap_right_two(struct valeur *init);
void swap_left_two(struct valeur *init);
void swap_op_two(struct valeur *init);
void swap_down_two(struct valeur *init);
void op_bis(struct valeur *init);
void down_bis(struct valeur *init);
void left_bis(struct valeur *init);
void right_bis(struct valeur *init);

#endif /* !SOKABAN_H_ */
