/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** count_number_back_slash_n
*/

int count_nb_back(char *str)
{
    int u = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            u++;
    return (u);
}