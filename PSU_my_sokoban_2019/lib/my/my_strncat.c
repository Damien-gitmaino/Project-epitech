/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** lib
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int u = 0;
    int compt = 0;

    while (dest[i] != '\0')
        i++;
        while (src[u] != '\0' && u < nb) {
            dest[i] = src[u];
            u++;
            i++;
        }
    dest[i] = '\0';
    return (dest);
}
