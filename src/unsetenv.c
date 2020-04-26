/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

void delet_env(env_t *new_env, int incr)
{
    char **new_tab = malloc(sizeof(char *) * tab_lengt(new_env->good_env) - 1);
    int array = 0;

    for (; array < incr; array += 1)
        new_tab[array] = str_cpy(new_env->good_env[array]);
    for (; new_env->good_env[array + 1]; array += 1)
        new_tab[array] = str_cpy(new_env->good_env[array + 1]);
    new_tab[array] = NULL;
    new_env->good_env = new_tab;
}

int unsetenv_(env_t *new_env, char *cmd, tree_t *tree)
{
    char **tab = my_str_to_word_array(cmd);
    int incr = 0;

    dup2(tree->fd[0], 0);
    dup2(tree->fd[1], 1);
    if (tab[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.", 0, 1);
        return (0);
    }
    for (; tab[incr]; incr += 1);
    if (incr != 2)
        return (0);
    for (incr = 0; new_env->good_env[incr] && str_ncmp(tab[1], \
    new_env->good_env[incr]) != 1; incr += 1);
    if (new_env->good_env[incr] == NULL)
        return (0);
    delet_env(new_env, incr);
    return (0);
}