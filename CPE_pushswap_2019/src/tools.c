/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** tools
*/

#include "pushswap.h"
#include <stdlib.h>
#include <stdio.h>

void order_sa(struct tab *tab, struct index *i)
{
    int tmp = 0;

    tmp = tab->l_a[i->index_l_a];
    tab->l_a[i->index_l_a] = tab->l_a[i->index_l_a + 1];
    tab->l_a[i->index_l_a + 1] = tmp;
    tab->ord[i->index_ord] = 's';
    tab->ord[i->index_ord + 1] = 'a';
    tab->ord[i->index_ord + 2] = ' ';
    tab->ord[i->index_ord + 3] = '\0';
    i->index_ord += 3;

}

void order_sb(struct tab *tab, struct index *i)
{
    int tmp = 0;

    tmp = tab->l_b[i->index_l_b];
    tab->l_b[i->index_l_b] = tab->l_b[i->index_l_b + 1];
    tab->l_b[i->index_l_b + 1] = tmp;
    tab->ord[i->index_ord] = 's';
    tab->ord[i->index_ord + 1] = 'b';
    tab->ord[i->index_ord + 2] = ' ';
    tab->ord[i->index_ord + 3] = '\0';
    i->index_ord += 3;
}

void order_pa(struct tab *tab, struct index *i)
{
    tab->l_a[i->index_l_a] = tab->l_b[i->index_l_b];
    i->index_l_a -= 1;
    i->index_l_b += 1;
    tab->ord[i->index_ord] = 'p';
    tab->ord[i->index_ord + 1] = 'a';
    tab->ord[i->index_ord + 2] = ' ';
    tab->ord[i->index_ord + 3] = '\0';
    i->index_ord += 3;
}

void order_pb(struct tab *tab, struct index *i)
{
    tab->l_b[i->index_l_b] = tab->l_a[i->index_l_a];
    i->index_l_a += 1;
    i->index_l_b -= 1;
    tab->ord[i->index_ord] = 'p';
    tab->ord[i->index_ord + 1] = 'b';
    tab->ord[i->index_ord + 2] = ' ';
    tab->ord[i->index_ord + 3] = '\0';
    i->index_ord += 3;
}
