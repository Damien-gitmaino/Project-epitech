/*
** EPITECH PROJECT, 2019
** CPE_BSQ_bootstrap_2019
** File description:
** BSQ
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char *recup_number(char *str);

int count_nb_back(char *str);

int check_number_first_ligne(char *str);

int check_ob_point(char c);

char *print_number(char *str, int i);

int number_carat_first_line(char *str, int i)
{
    for (; str[i] != '\n'; i++)
    return (i);
}

int over_error(char *str)
{
    int u = number_carat_first_line(str, 0);

    if (check_number_first_ligne(str) == 84 || check_ob_point(str[u + 1]) == 84
        || count_nb_back(str) != my_getnbr(recup_number(str)))
        return (84);    
}

int check_error(int size, int fd, int read_c)
{
    if (fd == -1)
        return (84);
    else if (read_c == -1)
        return (84);
    else if (read_c == 0)
        return (84);
    return (0);
}

int my_stat(char const *file)
{
    struct stat *buf = malloc(sizeof(struct stat));
    int size = 0;

    stat(file, buf);
    size = buf->st_size;
    free (buf);
    return (size);
}

int fs_print_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size = my_stat(filepath);
    char *buffer = malloc(sizeof(char) * size + 1);
    int read_c = read(fd, buffer, size);
    int i = 0;

    if (check_error(size, fd, read_c) == 84) {
        close (fd);
        return (84);
    }
    buffer[size] = '\0';
    i = number_carat_first_line(buffer, 0) + 1;
    print_number(buffer, i);
    close (fd);
    return (0);
}
