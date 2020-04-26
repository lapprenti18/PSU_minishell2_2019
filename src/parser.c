/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

int check_separator(char *str)
{
    if (str == NULL)
        return (1);
    for (int temp = 0; str[temp]; temp += 1) {
        if (str[temp] == '|' || str[temp] == '>' ||\
         str[temp] == '<' || str[temp] == ';')
            return (0);
    }
    return (1);
}

char *opt_jsp(char *str, int temp, char *opt)
{
    if (str[temp] == ';') {
        opt[0] = ';';
        opt[1] = '\0';
        return (opt);
    }
    if (str[temp] == '>' && str[temp + 1] == '>' && opt[0] != ';'\
     && opt[0] != '>') {
        opt[0] = '>';
        opt[1] = '>';
        return (opt);
    }
    if (str[temp] == '>' && str[temp + 1] != '>' && str[temp - 1] != '>'\
     && opt[0] != ';') {
        opt[0] = '>';
        opt[1] = '\0';
        return (opt);
    }
    return (opt);
}

char *opt_two(char *str, int temp, char *opt)
{
    if (str[temp] == '<' && str[temp + 1] == '<' && opt[0] != ';' &&\
     opt[0] != '>' && opt[0] != '<') {
        opt[0] = '<';
        opt[1] = '<';
        return (opt);
    }
    if (str[temp] == '<' && str[temp + 1] != '<' && opt[0] != '>' &&\
     opt[0] != ';') {
        opt[0] = '<';
        opt[1] = '\0';
        return (opt);
    }
    if (str[temp] == '|' && opt[0] != ';' && opt[0] != '>' &&\
     opt[0] != '<') {
        opt[0] = '|';
        opt[1] = '\0';
        return (opt);
    }
    return (opt);
}

char *hight_separator(char *str)
{
    char *opt = malloc(sizeof(char) * 3);

    my_memset(opt, 3);
    for (int temp = 0; str[temp]; temp += 1) {
        opt = opt_jsp(str, temp, opt);
        if (opt[0] != ';' && opt[0] != '>')
            opt = opt_two(str, temp, opt);
    }
    return (opt);
}