/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

int just_cd(env_t *new_env, last_line_t *last_line)
{
    char **home = search_home(new_env);

    if (home == NULL) {
        my_putstr("cd: No home directory.", 0, 1);
        return (0);
    }
    my_memset(last_line->line, 9999);
    getcwd(last_line->line, 9999);
    chdir(home[1]);
    return (0);
}

void cd_jsp(char **cd, env_t *new_env, int temp, last_line_t *last_line)
{
    if (temp > 2)
        my_putstr("cd: Trop d'arguments.", 0, 1);
    if (cd[1][0] == '~' || temp == 1)
        just_cd(new_env, last_line);
}

int cd_moin(env_t *new_env, last_line_t *last_line)
{
    if (last_line->line == NULL)
        return (just_cd(new_env, last_line));
    else
        chdir(last_line->line);
    return (0);
}

void err_cd(char *cmd)
{
    if (errno == 2) {
        my_putstr(cmd, 0, 0);
        my_putstr(": Command not found.", 0, 1);
        return;
    }
    if (errno == 20) {
        my_putstr(cmd, 0, 0);
        my_putstr(": Not a directory.", 0, 1);
        return;
    }
}

int just_cd_argv(char **cd, env_t *new_env, last_line_t *last_line)
{
    int temp;
    int error = 0;

    for (temp = 0; cd[temp]; temp += 1);
    if (temp == 1) {
        just_cd(new_env, last_line);
        return (0);
    }
    cd_jsp(cd, new_env, temp, last_line);
    if (cd[1][0] == '-')
        return (cd_moin(new_env, last_line));
    if (temp == 2 && cd[1][0] != '~') {
        my_memset(last_line->line, 9999);
        getcwd(last_line->line, 9999);
        error = chdir(cd[1]);
        if (error == -1)
            err_cd(cd[1]);
    }
    return (0);
}

int my_cd(char *cmd, env_t *new_env, last_line_t *last_line, tree_t *tree)
{
    dup2(tree->fd[0], 0);
    dup2(tree->fd[1], 1);
    if (str_cmp("cd\n", cmd) == 1)
        return (just_cd(new_env, last_line));
    if (str_ncmp("cd ", cmd) == 1)
        return (just_cd_argv(my_str_to_word_array(cmd), new_env, last_line));
    else {
        cmd[my_strlen(cmd) - 1] = '\0';
        my_putstr(cat(cmd, ": Commande introuvable."), 0, 1);
    }
    return (0);
}