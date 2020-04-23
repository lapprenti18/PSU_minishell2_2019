/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

void simple_right_redirect(tree_t *tree, env_t *new_env, last_line_t *last_line)
{
    int fd;
    char **cmd = NULL;

    if (tree->right->opt == NULL) {
        my_putstr("Missing name for redirect.", 0, 1);
        return;
    }
    if (tree->left->opt == NULL) {
        my_putstr("Invalid null command.", 0, 1);
        return;
    }
    cmd = my_str_to_word_array_path(tree->right->opt);
    cmd[0][my_strlen(cmd[0]) - 1] = '\0';
    fd = open(cmd[0], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd == -1)
        return;
    tree->left->fd[1] = fd;
    execute_tree(tree->left, new_env, last_line);
    close(fd);
}

void double_right_redirect(tree_t *tree, env_t *new_env, last_line_t *last_line)
{
    int fd;
    char **cmd = NULL;

    if (tree->right->opt == NULL) {
        my_putstr("Missing name for redirect.", 0, 1);
        return;
    }
    if (tree->left->opt == NULL) {
        my_putstr("Invalid null command.", 0, 1);
        return;
    }
    cmd = my_str_to_word_array_path(tree->right->opt);
    cmd[0][my_strlen(cmd[0]) - 1] = '\0';
    fd = open(cmd[0], O_WRONLY | O_CREAT | O_APPEND, 0664);
    tree->left->fd[1] = fd;
    execute_tree(tree->left, new_env, last_line);
    close(fd);
}

void simple_left_redirect(tree_t *tree, env_t *new_env, last_line_t *last_line)
{
    int fd;
    char **cmd = NULL;

    if (tree->right->opt == NULL) {
        my_putstr("Missing name for redirect.", 0, 1);
        return;
    }
    if (tree->left->opt == NULL) {
        my_putstr("Invalid null command.", 0, 1);
        return;
    }
    cmd = my_str_to_word_array_path(tree->right->opt);
    cmd[0][my_strlen(cmd[0]) - 1] = '\0';
    fd = open(cmd[0], O_RDONLY);
    tree->left->fd[0] = fd;
    execute_tree(tree->left, new_env, last_line);
    close(fd);
}

void pipe_redirect(tree_t *tree, env_t *new_env, last_line_t *last_line)
{
   pid_t pid;
   int new_fd[2];

    if (tree->left->opt == NULL || tree->right->opt == NULL) {
        my_putstr("Invalid null command.", 0, 1);
        return;
    }
    tree->left->fd[0] = tree->fd[0];
    tree->right->fd[1] = tree->fd[1];
    pipe(new_fd);
    tree->left->fd[1] = new_fd[1];
    tree->right->fd[0] = new_fd[0];
    pid = fork();
    if (pid == 0) {
        execute_tree(tree->left, new_env, last_line);
        exit (0);
    } else {
        close(tree->left->fd[1]);
        execute_tree(tree->right, new_env, last_line);
        wait(&pid);
    }
}
