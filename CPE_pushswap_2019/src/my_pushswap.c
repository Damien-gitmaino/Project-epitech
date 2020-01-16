/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** my_pushswap
*/

#include "pushswap.h"
#include <stdlib.h>
#include <unistd.h>

void great_swap(struct index *index, struct tab *tab)
{
    if (tab->l_a[index->index_l_a] > tab->l_a[index->index_l_a + 1])
        order_sa(tab, index);
}

void algo(struct index *index, struct tab *tab)
{
    while (1) {
        while (index->index_l_a < index->nb) {
            great_swap(index, tab);
            order_pb(tab, index);
        }
        order_pb(tab, index);
        if (index->index_ord >= 25000000 * 5) {
            write(1, tab->ord, my_strlen(tab->ord));
            index->index_ord = 0;
            free(tab->ord);
            tab->ord = malloc(sizeof(char) * (25000000 * 6));
        }
        while (index->index_l_b < index->nb)
            order_pa(tab, index);
        if (check_sort(tab->l_a, index->nb) == 0)
            break;
    }
}

void initialisation(struct index *index, int ac, struct tab *tab)
{
    int nub = ac - 2;

    tab->l_a = malloc(sizeof(int) * ac + 1);
    tab->l_b = malloc(sizeof(int) * ac + 1);
    tab->ord = malloc(sizeof(char) * (25000000 * 6));
    for (int i = 0; i < ac; i++)
        tab->l_b[i] = 0;
    index->index_l_a = 0;
    index->index_l_b = nub;
    index->index_ord = 0;
    index->nb = nub;
    index->index_ord = 0;
}

int my_pushswap(int ac, char **av)
{
    struct index index;
    struct tab tab;

    initialisation(&index, ac, &tab);
    fill_l_a(ac, av, &tab);
    if (check_sort(tab.l_a, ac - 1) == 0) {
        my_printf("\n");
        return (0);
    }
    algo(&index, &tab);
    write(1, tab.ord, my_strlen(tab.ord) - 1);
    my_putchar('\n');
    free(tab.l_a);
    free(tab.l_b);
    free(tab.ord);
    return (0);
}
