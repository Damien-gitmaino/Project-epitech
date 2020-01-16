/*
** EPITECH PROJECT, 2020
** my_ls_tmp
** File description:
** my_ls
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <string.h>
#include <getopt.h>

void select_mod(int ac, char **av);
void open_print(int nb, char *folder);
void open_save(char *str, char *tmp, int ac);
void read_folder_flag_lrt(char *folder, int ac);
char *cod_i_reaload(int run, char *str, char *tmp, char *file);
char *filepath_reload(char *str, char *tmp, int ac, char *file);
char *check_slash(char *str);
void check_file(char *filepath);
void print_info(struct stat info_f);
void cod_i_print_ex(struct stat *info_f);
void cod_i_print_ex_t(struct stat *info_f);
void recur_l(char *str);
void recur_lr(char *str);

#endif /* !MY_LS_H_ */
