/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

void one_cmd(char *str, env_t *new_env, last_line_t *last_line, int *fd)
{
    int no_binary = no_bin(new_env, str, last_line);

    if (no_binary == 2)
        go_fork(new_env, my_str_to_word_array(str), fd);
}

int tree_right(char *str)
{
    for (int temp = 0; str[temp]; temp += 1) {
        if (str[temp] != ' ' && str[temp] != '\n' && str[temp] != '\t')
            return (0);
    }
    return (1);
}

void execute_tree(tree_t *tree, env_t *new_env, last_line_t *last_line)
{
    if (tree == NULL || tree->opt == NULL)
        return;
    if (tree->right) {
        if ((tree_right(tree->right->opt)) == 1)
            tree->right->opt = NULL;
    }
    if (str_cmp(";", tree->opt) == 1) {
        tree->left ? execute_tree(tree->left, new_env, last_line) : 0;
        tree->right ? execute_tree(tree->right, new_env, last_line) : 0;
        return;
    }
    if (str_cmp(">>", tree->opt) == 1) {
        double_right_redirect(tree, new_env, last_line);
        return;
    }
    if (str_cmp(">", tree->opt) == 1) {
        simple_right_redirect(tree, new_env, last_line);
        return;
    }
    if (str_cmp("<", tree->opt) == 1) {
        simple_left_redirect(tree, new_env, last_line);
        return;
    }
    if (str_cmp("|", tree->opt) == 1) {
        pipe_redirect(tree, new_env, last_line);
        return;
    }
    one_cmd(tree->opt, new_env, last_line, tree->fd);
}
