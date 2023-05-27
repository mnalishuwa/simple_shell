#ifndef MAIN_H
#define MAIN_H

#define _ASC_SPACES "\t\n\v\f\r \x85\xa0"
#define ASCII_ZERO 48
#define NEGATIVE_SIGN 45
#define BLK_SIZE 512

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* _putchar - print single char to stdout */
int _putchar(char c);

void _puts(char *str);

/* cmdline_to_argv - splits string, returns an array of words in the string */
char **cmdline_to_argv(char *_str);

/* print_prompt - prints prompt to screen */
void print_prompt(void);

/* read_line - reads a line of input from stdin */
char *read_line(void);

/* _strip - remove whitespace from a string */
char *_strip(char *_str);

/* _is_wspace - check if a char is whitespace */
int _is_wspace(char c);

/* print_path - prints all directories on the PATH environment variable */
void print_path(void);

/* _getenv - gets the value of an environment variable */
char *_getenv(const char *name, char **env);

/* _setenv - sets the value of an environment variable */
/* int _setenv(const char *name, const char *value, int overwrite); */
int _setenv(const char *name, const char *value, int overwrite, char **env);

/* _unsetenv - deletes the value of an environment variable */
int _unsetenv(const char *name);

void ctrlc_handler(int sig_int);

/* void eof_handler(int nread, int e_no); */
void eof_handler(int nread, int e_no, char *lineptr);

/* void _exit_hsh(int status); */
void _exit_hsh(char *lineptr, char **args, int status);

void rm_linefeed(char *_str);

/* int check_inbuilt(char *command, char **env); */
int check_inbuilt(char *command, char **args, char **env);

void _printenv(char **env);

int _strcmp(char *s1, char *s2);

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

int _fileno(FILE *stream);

char *normalize_wspace(char *_str, size_t len_s);

char **_strtok(char *_str, const char *_delim);

char **_strtok(char *_str, const char *_delim);

char *_strstr(char *haystack, char *needle);

char *_strncpy(char *dest, char *src, size_t n);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

int _strlen(char *s);

void del_twspace(char *s);

int is_pathbased(char *command);

char *search_path(char *command, char **env);

void create_path(char *dest, char *s1, char *s2);

void free_args(char **args);

void _run_shell(char **env);

int launch_program(char **args, char **env);

void print_number(int n);

int _pow_recursion(int x, int y);

/* void cmd_not_found(char *command, int num, char **env); */
void cmd_not_found(char *command, char **args, int num, char **env);

void normalize_wspace2(char *_str);

void create_path2(char *dest, char *s1, char *s2, char sep);

int _atoi(char *s);

void _non_interactive(char **env);

int check_inbuilt(char *command, char **args, char **env);

char *_strdup(char *str);

int _cd_home(char *path, char **env);

char *_memset(char *s, char b, unsigned int n);

#endif
