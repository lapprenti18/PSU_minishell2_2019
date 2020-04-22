/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

void one_cmd(tree_t *tree, env_t *new_env, last_line_t *last_line)
{
    int no_binary = no_bin(new_env, tree->str, last_line);

    if (no_binary == 2)
        go_fork(new_env, my_str_to_word_array(tree->str));
    printf("test\n");
}

void execute_tree(tree_t *tree, env_t *new_env, last_line_t *last_line)
{
    if (tree->opt == NULL && tree->left == NULL && tree->right == NULL)
        one_cmd(tree, new_env, last_line);
}
