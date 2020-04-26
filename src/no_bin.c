/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

int display_env(env_t *new_env, tree_t *tree)
{
    dup2(tree->fd[0], 0);
    dup2(tree->fd[1], 1);
    for (int temp = 0; new_env->good_env[temp]; temp += 1)
        my_putstr(new_env->good_env[temp], 0, 1);
    return (0);
}

char **search_home(env_t *new_env)
{
    int temp = 0;
    char **path;
    int boool = 0;

    for (int temp = 0; new_env->good_env[temp]; temp += 1) {
        if (str_ncmp("HOME=", new_env->good_env[temp]))
            boool = 1;
    }
    if (boool == 0)
        return (NULL);
    for (; (str_ncmp("HOME=", new_env->good_env[temp]) != 1); temp += 1);
    path = my_str_to_word_array_path(new_env->good_env[temp]);
    return (path);
}

int tab_lengt(char **tab)
{
    int a = 0;

    for (; tab[a]; a += 1);
    return (a + 1);
}

int no_bin(env_t *new_env, char *cmd, last_line_t *last_line, tree_t *tree)
{
    if (str_cmp("exit\n", clear_str(cmd)) == 1)
        return (-1);
    if (str_cmp("env\n", cmd) == 1)
        return (display_env(new_env, tree));
    if (str_ncmp("setenv", cmd) == 1)
        return (setenv_(new_env, cmd, tree));
    if (str_ncmp("unsetenv", clear_str(cmd)) == 1)
        return (unsetenv_(new_env, clear_str(cmd), tree));
    if (str_ncmp("cd", clear_str(cmd)) == 1) {
        my_cd(clear_str(cmd), new_env, last_line, tree);
        return (0);
    }
    return (2);
}