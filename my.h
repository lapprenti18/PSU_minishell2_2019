/*
** EPITECH PROJECT, 2019
** my
** File description:
** include
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <getopt.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <stdbool.h>
#include <grp.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <sys/sysmacros.h>
#include <signal.h>
#include <ncurses.h>


typedef struct tree_s
{
    char *opt;
    char *str;
    struct tree_s *left;
    struct tree_s *right;
    int fd[2];
} tree_t;

typedef struct parse_s
{
    char *opt;
    char *right;
    char *left;
} parse_t;

typedef struct last_line_s
{
    char *line;
} last_line_t;

typedef struct env_s
{
    char **good_env;
} env_t;

int my_strlen(char *str);
char **str_cpy_tab(char **tab);
char *str_cpy(char *str);
void display_prompt(void);
void my_putchar12(char c);
void my_putstr(char *str, int space, int slash);
void siginthandler(int sig_num);
void execute_tree(tree_t *tree, env_t *new_env, last_line_t *last_line);

char *cat(char *start, char *line);
int no_bin(env_t *new_env, char *cmd, last_line_t *last_line, tree_t *tree);
int str_cmp(char *str, char *str2);
char **my_str_to_word_array_path(char *str);
char **my_str_to_word_array(char *str);
void go_fork(env_t *new_env, char **cmd, int *fd);
int str_ncmp(char *str, char *str2);
char *my_memset(char *str, int size);
int my_cd(char *cmd, env_t *new_env, last_line_t *last_line, tree_t *tree);
int just_cd_argv(char **cd, env_t *new_env, last_line_t *last_line);
int cd_moin(env_t *new_env, last_line_t *last_line);
void cd_jsp(char **cd, env_t *new_env, int temp, last_line_t *last_line);
int just_cd(env_t *new_env, last_line_t *last_line);
int display_env(env_t *new_env, tree_t *tree);
char **search_home(env_t *new_env);
int tab_lengt(char **tab);
int unsetenv_(env_t *new_env, char *cmd, tree_t *tree);
void delet_env(env_t *new_env, int incr);
void add_env(env_t *new_env, int incr, char **tab);
int new_environement(env_t *new_env, char **tab);
int setenv_(env_t *new_env, char *cmd, tree_t *tree);
void segfault(int pid);
int main_minishel(char *str, char **env);
void simple_right_redirect(tree_t *tree, env_t *new_env\
, last_line_t *last_line);
void double_right_redirect(tree_t *tree, env_t *new_env\
, last_line_t *last_line);
void pipe_redirect(tree_t *tree, env_t *new_env, last_line_t *last_line);
void simple_left_redirect(tree_t *tree, env_t *new_env, last_line_t *last_line);
char *clear_str(char *str);
void err_cd(char *cmd);
void my_dup(tree_t *tree);
int my_for(env_t *new_env, char **tab);
int check_separator(char *str);
char *opt_jsp(char *str, int temp, char *opt);
char *opt_two(char *str, int temp, char *opt);
char *hight_separator(char *str);
char *test(char *str, char opt);
char *parse_left(char *str, int size_str, char opt);
char *parse_right(char *str, int size_str, int size_tot);
void fd_gestion(int nb, tree_t *tree, int *new_fd);

#endif /* MY_H_ */
