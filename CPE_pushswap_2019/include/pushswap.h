/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** pushswap
*/

#ifndef PUSHSWAP_H_
#define PUSHSWAP_H_

#include "my.h"

struct index
{
    int index_l_a;
    int index_l_b;
    int index_ord;
    int nb;
};

struct tab
{
    int *l_a;
    int *l_b;
    char *ord;
};

int my_pushswap(int ac, char **av);

/*
** order
*/

void order_sa(struct tab *tab, struct index *i);
void order_sb(struct tab *tab, struct index *i);
void order_pb(struct tab *tab, struct index *i);
void order_pa(struct tab *tab, struct index *i);

/*
**check
*/

int check_sort(int *list, int nb_carat);
void fill_l_a(int ac, char **av, struct tab *tab);

#endif /* !PUSHSWAP_H_ */
