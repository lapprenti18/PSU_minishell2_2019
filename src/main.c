/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

// ; , >, >>, <, <<, | 

#include "../my.h"

int check_separator(char *str)
{
    for (int temp = 0; str[temp]; temp += 1) {
        if (str[temp] == '|' || str[temp] == '>' || str[temp] == '<' || str[temp] == ';')
            return (0);
    }
    return (1);
}

char *hight_separator(char *str)
{
    char *opt = malloc(sizeof(char) * 3);

    memset(opt, 0, 3);
    for (int temp = 0; str[temp]; temp += 1) {
        if (str[temp] == ';') {
            opt[0] = ';';
            opt[1] = '\0';
            continue;
        }
        if (str[temp] == '>' && str[temp + 1] != '>' && opt[0] != ';') {
            opt[0] = '>';
            opt[1] = '\0';
            continue;
        }
        if (str[temp] == '>' && str[temp + 1] == '>' && opt[0] != ';' && opt[0] != '>') {
            opt[0] = '>';
            opt[1] = '>';
            continue;
        }
        if (str[temp] == '<' && str[temp + 1] != '<' && opt[0] != '>' && opt[0] != ';') {
            opt[0] = '<';
            opt[1] = '\0';
            continue;
        }
        if (str[temp] == '<' && str[temp + 1] == '<' && opt[0] != ';' && opt[0] != '>' && opt[0] != '<') {
            opt[0] = '<';
            opt[1] = '<';
            continue;
        }
        if (str[temp] == '|' && opt[0] != ';' && opt[0] != '>' && opt[0] != '<') {
            opt[0] = '|';
            opt[1] = '\0';
        }
    }
    return (opt);
}

char *parse_left(char *str, int size_str)
{
    char *left = malloc(sizeof(char) * (size_str + 2));

    left[size_str + 1] = '\0';
    left[size_str] = '\n';
    for (int size = 0; size < size_str ; size += 1)
        left[size] = str[size];
    return (left);
}

char *parse_right(char *str, int size_str, int size_tot)
{
    char *left = malloc(sizeof(char) * (size_tot + 2));

    left[size_tot + 1] = '\0';
    for (int temp = 0; str[size_str]; size_str += 1) {
       left[temp] = str[size_str];
       temp += 1;
    }
    if (left[size_tot - 1] == '\n')
        left[size_tot] = '\0';
    else
        left[size_tot] = '\n';
    return (left);
}

void parse_str(parse_t *parser, char *str)
{
    int size_str = my_strlen(str) - 1;
    int size_str_temp = size_str;
    parser->opt = hight_separator(str);

    for (; size_str != 0; size_str--) {
        if (str[size_str] == parser->opt[0] && parser->opt[1] == '\0') {
            parser->left = parse_left(str, size_str);
            parser->right = parse_right(str, size_str + 1, size_str_temp - size_str);
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
    tree->opt = NULL;
    tree->fd[0] = 0;
    tree->fd[1] = 0;
    return (tree);
}

void recursive(tree_t *tree, char *str)
{
    parse_t *parser = malloc(sizeof(parse_t));

    if (check_separator(str) == 1) {
        tree->str = str_cpy(str);
        tree->opt = NULL;
        return;
    }
    parse_str(parser, str);
    tree->opt = str_cpy(parser->opt);
    // printf("%s\n", parser->left);
    // printf("%s\n", parser->opt);
    // printf("%s\n", parser->right);
    tree->right = create_box(parser->right);
    tree->left = create_box(parser->left);
    recursive(tree->right, parser->right);
    recursive(tree->left, parser->left);
    return;
}

int main(int ac, char **av, char **env)
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
        tree->right = NULL;
        tree->left = NULL;
        tree->fd[0] = 0;
        tree->fd[1] = 0;
        tree->opt = NULL;
        tree->str = str_cpy(line);
        recursive(tree, line);
        execute_tree(tree, &new_env, &last_line);
    } while (read != -1);
    return (0);
}