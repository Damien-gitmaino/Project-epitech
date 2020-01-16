/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** sokaban
*/

#include "sokaban.h"
struct valeur init;

int check_error(int fd, int read_c)
{
    if (fd == -1)
        return (84);
    else
        return (0);
}

char *fs_print_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size;
    char *buffer;
    int read_c;

    if (check_error(fd, read_c) == 84)
        exit (84);
    size = my_stat(filepath);
    buffer = malloc(sizeof(char) * size + 1);
    read_c = read(fd, buffer, size);
    buffer[size] = '\0';
    close (fd);
    return (buffer);
}

char **fill(char *str)
{
    int nb_ligne = count_number_n(str);
    int nb_colum = count_number_colum(str);
    int index_str = 0;
    char **map = malloc(sizeof(char *) * nb_ligne + 1);

    init.nub_col = nb_colum;
    init.nub_line = nb_ligne;
    for (int i = 0; i < nb_ligne; i++) {
        map[i] = malloc(sizeof(char) * nb_colum + 1);
        map[i][nb_colum] = '\0';
    }
    for (int i = 0; i < nb_ligne; i++) {
        for (int o = 0; str[index_str] != '\n'; o++) {
            map[i][o] = str[index_str];
            index_str += 1;
        }
        index_str += 1;
    }
    return (map);
}

int interlude(int ac, char **av)
{
    char *tmp = fs_print_first_line(av[1]);
    init.mesg = fill(tmp);
    init.dup = fill(tmp);
    int number_n = count_number_n(tmp);

    if (number_n < 3)
        return (84);
    if (game(number_n, tmp, &init) == 84) {
        free (init.mesg);
        free (init.dup);
        return (84);
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h' && my_strlen(av[1]) == 2) {
        tireh();
        return (0);
    }
    if (interlude(ac, av) == 84)
        return (84);
    free (init.mesg);
    free (init.dup);
    return (0);
}
