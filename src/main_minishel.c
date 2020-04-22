/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

void siginthandler(int sig_num)
{
    (void)sig_num;
    signal(SIGINT, siginthandler);
    my_putstr("\n$>", 0, 0);
}

// void main_loop(env_t *new_env, last_line_t *last_line)
// {
//     size_t len = 0;
//     ssize_t read;
//     int no_binary = 0;
//     char *line;

//     do {
//         no_binary = 0;
//         signal(SIGINT, siginthandler);
//         display_prompt();
//         if ((read = getline(&line, &len, stdin)) == -1) {
//             if (isatty(0))
//                 my_putstr("exit", 0, 1);
//             exit (0);
//         }
//         no_binary = no_bin(new_env, line, last_line);
//         if (no_binary == 2)
//             go_fork(new_env, my_str_to_word_array(line));
//     } while (read != -1 && no_binary != -1);
// }

// int main_minishel(char *str, char **env)
// {
//     last_line_t last_line;
//     env_t new_env;

//     new_env.good_env = str_cpy_tab(env);
//     last_line.line = malloc(sizeof(char) * 9999);
//     main_loop(&new_env, &last_line);
//     return (0);
// }