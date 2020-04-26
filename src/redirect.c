/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

char *clear_str(char *str)
{
    char *reslt = malloc(sizeof(char) * my_strlen(str) + 1);
    int temp = 0;

    if (str == NULL)
        return (NULL);
    my_memset(reslt, my_strlen(str));
    for (; str[temp] == ' '; temp += 1);
    for (int index = 0; str[temp]; temp += 1) {
        reslt[index] = str[temp];
        index += 1;
    }
    return (reslt);
}

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
    if (cmd[0][my_strlen(cmd[0]) - 1] == '\n')
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
    if (cmd[0][my_strlen(cmd[0]) - 1] == '\n')
        cmd[0][my_strlen(cmd[0]) - 1] = '\0';
    fd = open(cmd[0], O_WRONLY | O_APPEND | O_APPEND, 0664);
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
    if (cmd[0][my_strlen(cmd[0]) - 1] == '\n')
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
    fd_gestion(0, tree, new_fd);
    pipe(new_fd);
    fd_gestion(1, tree, new_fd);
    pid = fork();
    if (pid == 0) {
        execute_tree(tree->left, new_env, last_line);
        close(new_fd[0]);
        close(new_fd[1]);
        exit (0);
    } else {
        close(tree->left->fd[1]);
        execute_tree(tree->right, new_env, last_line);
        wait(&pid);
    }
}
