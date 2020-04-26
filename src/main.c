/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

void parse_str(parse_t *parser, char *str)
{
    int size_str = my_strlen(str) - 1;
    int size_str_temp = size_str;
    parser->opt = hight_separator(str);

    for (; size_str != -1; size_str--) {
        if (str[size_str] == parser->opt[0] && parser->opt[1] == '\0') {
            parser->left = parse_left(str, size_str, parser->opt[0]);
            parser->right = parse_right(str, size_str + 1,\
             size_str_temp - size_str);
            break;
        }
        else if (str[size_str] == parser->opt[0]) {
            parser->left = test(str, parser->opt[0]);
            parser->right = parse_right(str, size_str + 1,\
             size_str_temp - size_str);
            break;
        }
    }
}

tree_t *create_box(char *str)
{
    tree_t *tree = malloc(sizeof(tree_t));

    tree->right = NULL;
    tree->left = NULL;
    tree->str = str_cpy(str);
    tree->opt = str_cpy(str);
    tree->fd[0] = 0;
    tree->fd[1] = 1;
    return (tree);
}

void recursive(tree_t *tree, char *str)
{
    parse_t *parser = malloc(sizeof(parse_t));

    if (check_separator(str) == 1) {
        tree->opt = str_cpy(str);
        return;
    }
    parse_str(parser, str);
    tree->opt = str_cpy(parser->opt);
    tree->right = create_box(parser->right);
    tree->left = create_box(parser->left);
    recursive(tree->right, parser->right);
    recursive(tree->left, parser->left);
    return;
}

void main_minishell_2(char **env)
{
    tree_t *tree = malloc(sizeof(tree_t));
    size_t len = 0;
    ssize_t read;
    char *line;
    last_line_t last_line;
    env_t new_env;

    new_env.good_env = str_cpy_tab(env);
    last_line.line = malloc(sizeof(char) * 9999);
    do {
        signal(SIGINT, siginthandler);
        display_prompt();
        if ((read = getline(&line, &len, stdin)) == -1) {
            if (isatty(0))
                my_putstr("exit", 0, 1);
            exit (0);
        }
        tree = create_box(line);
        recursive(tree, line);
        execute_tree(tree, &new_env, &last_line);
    } while (read != -1);
}

int main(int ac, char **av, char **env)
{
    (void)av;
    if (ac > 1)
        return (84);
    main_minishell_2(env);
    return (0);
}