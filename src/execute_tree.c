/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

void one_cmd(char *str, env_t *new_env, last_line_t *last_line)
{
    // printf("cmd split = %s\n", str);
    int no_binary = no_bin(new_env, str, last_line);

    if (no_binary == 2)
        go_fork(new_env, my_str_to_word_array(str));
}

void execute_tree(tree_t *tree, env_t *new_env, last_line_t *last_line)
{
    // printf("oooh %s|\n", tree->str);
    if (tree->opt == NULL && tree->left == NULL && tree->right == NULL) {
        one_cmd(tree->str, new_env, last_line);
        return;
    }
    if (str_cmp(";", tree->opt) == 1) {
        if (tree->left->opt == NULL) {
            // printf("left\n");
            one_cmd(tree->left->str, new_env, last_line);
        }
        if (tree->left->opt != NULL) {
            // printf("test2\n");
            execute_tree(tree->left, new_env, last_line);
        }
        if (tree->right->opt == NULL) {
            // printf("right\n");
            one_cmd(tree->right->str, new_env, last_line);
        }
        if (tree->right->opt != NULL) {
            // printf("test1\n");
            execute_tree(tree->right, new_env, last_line);
        }
    }
}
