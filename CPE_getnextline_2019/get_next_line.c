/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** getnextline
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct tab
{
    int read_c;
}tab;

char *my_realloc_tmp(char *str)
{
    int tmp = 0;
    int i = 0;
    char *new = NULL;

    for (; str[tmp] != '\n' && str[tmp] != '\0'; tmp++);
    tmp++;
    if (str[tmp] == '\0')
        return (NULL);
    new = malloc(sizeof(char) * READ_SIZE - tmp + 1);
    for (; tmp < READ_SIZE && str[tmp] != '\0'; i++, tmp++)
        new[i] = str[tmp];
    new[i] = '\0';
    free (str);
    return (new);
}

char *my_realloc(char *str, int nb)
{
    char *new = malloc(sizeof(char) * nb + 1);

    new[nb] = '\0';
    for (int i = 0; i < nb; i++)
        new[i] = str[i];
    return (new);
}

char *cod_i(char *buf, int fd)
{
    if (buf == NULL) {
        buf = malloc(sizeof(char) * READ_SIZE + 1);
        tab.read_c = read(fd, buf, READ_SIZE);
        buf[tab.read_c] = '\0';
        if (tab.read_c == 0)
            return (NULL);
        return (buf);
    } else if (buf[0] == '\0') {
        free (buf);
        buf = malloc(sizeof(char) * READ_SIZE + 1);
        tab.read_c = read(fd, buf, READ_SIZE);
        buf[tab.read_c] = '\0';
        if (tab.read_c == 0)
            return (NULL);
        return (buf);
    }
    return (buf);
}

char *get_next_line(int fd)
{
    static char *buf = NULL;
    char *str = malloc(sizeof(char) * 36000 + 1);
    int nb = 0;

    buf = cod_i(buf, fd);
    if (buf == NULL)
        return (NULL);
    for (int i = 0; buf[i] != '\n' &&
        tab.read_c > 0; i++, nb++) {
        str[nb] = buf[i];
        if (buf[i + 1] == '\0') {
            i = -1;
            buf = malloc(sizeof(char) * 1);
            buf[0] = '\0';
            buf = cod_i(buf, fd);
        }
    }
    buf = my_realloc_tmp(buf);
    return (my_realloc(str, nb));
}
