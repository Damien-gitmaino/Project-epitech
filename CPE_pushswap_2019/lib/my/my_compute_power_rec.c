/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** recursive the power
*/

int my_compute_power_rec(int nb, int p)
{
    int ter;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
        ter = nb * (my_compute_power_rec(nb, p - 1));
    return (ter);
}
