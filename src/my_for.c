/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

int my_for(env_t *new_env, char **tab)
{
    int incr = 0;

    for (incr = 0; new_env->good_env[incr] && str_ncmp(tab[1], \
    new_env->good_env[incr]) != 1; incr += 1);
    return (incr);
}

void my_dup(tree_t *tree)
{
    dup2(tree->fd[0], 0);
    dup2(tree->fd[1], 1);
}