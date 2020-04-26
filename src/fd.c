/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

void fd_gestion(int nb, tree_t *tree, int *new_fd)
{
    if (nb  == 0) {
        tree->left->fd[0] = tree->fd[0];
        tree->right->fd[1] = tree->fd[1];
    }
    if (nb == 1) {
        tree->left->fd[1] = new_fd[1];
        tree->right->fd[0] = new_fd[0];
    }
}