/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

void add_env(env_t *new_env, int incr, char **tab)
{
    char **new_tab = malloc(sizeof(char *) * tab_lengt(new_env->good_env));
    int array = 0;

    for (; array < incr; array += 1)
        new_tab[array] = str_cpy(new_env->good_env[array]);
    if (tab[2] == NULL)
        new_tab[array] = cat(tab[1], "=");
    else
        new_tab[array] = cat(cat(tab[1], "="), tab[2]);
    array += 1;
    for (; new_env->good_env[array]; array += 1)
        new_tab[array] = str_cpy(new_env->good_env[array]);
    new_tab[array] = NULL;
    new_env->good_env = new_tab;
}

int new_environement(env_t *new_env, char **tab)
{
    char **new_tab = malloc(sizeof(char *) * \
(tab_lengt(new_env->good_env) + 1));
    int array = 0;

    for (; new_env->good_env[array]; array += 1)
        new_tab[array] = str_cpy(new_env->good_env[array]);
    if (tab[2] == NULL)
        new_tab[array] = cat(tab[1], "=");
    else
        new_tab[array] = cat(cat(tab[1], "="), tab[2]);
    new_tab[array + 1] = NULL;
    new_env->good_env = new_tab;
    return (0);
}

int error(char *str)
{
    for (int temps = 0; str[temps]; temps += 1) {
        if (str[temps] < 'A' || (str[temps] > 'Z' && \
        str[temps] < 'a') || str[temps] > 'z') {
            return (0);
        }
    }
    return (1);
}

int display_err(void)
{
    my_putstr("setenv: Variable name must conta\
in alphanumeric characters.", 0, 1);
    return (0);
}

int setenv_(env_t *new_env, char *cmd)
{
    char **tab = my_str_to_word_array(cmd);
    int incr = 0;

    if (tab[1] == NULL) {
        display_env(new_env);
        return (0);
    }
    if (error(tab[1]) == 0)
            return (display_err());
    if (tab[2] != NULL) {
        if (tab[3] != NULL) {
            my_putstr("setenv: Too many arguments.", 0, 1);
            return (0);
        }
    }
    for (incr = 0; new_env->good_env[incr] && str_ncmp(tab[1], \
new_env->good_env[incr]) != 1; incr += 1);
    if (new_env->good_env[incr] == NULL)
        return (new_environement(new_env, tab));
    add_env(new_env, incr, tab);
    return (0);
}