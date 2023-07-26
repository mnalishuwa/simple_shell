#ifndef MAIN_H
#define MAIN_H

#define _ASC_SPACES "\t\n\v\f\r \x85\xa0"
#define _SETENVERR "usage: setenv name value"
#define _UNSETENVERR "usage: unsetenv name"
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

/**
 * struct env_linkedlist_node - type definition for env variable node
 * @name: string variable name
 * @value: string vvariable value
 * @next_node: pointer to next node
 *
 * Description: defines a node for an env variable
 */
typedef struct env_linkedlist_node
{
	char *name;
	char *value;
	struct env_linkedlist_node *next_node;
} enode;

typedef struct env_liskedlist_node *env_linkedlist_ptr;

/* _putchar - print single char to stdout */
int _putchar(char c);

void _puts(char *str);

/* cmdline_to_argv - splits string, returns an array of words in the string */
char **cmdline_to_argv(char *_str);

/* print_prompt - prints prompt to screen */
void print_prompt(void);

/* read_line - reads a line of input from stdin */
/* char *read_line(void); */
char *read_line(enode *env);

/* _strip - remove whitespace from a string */
char *_strip(char *_str);

/* _is_wspace - check if a char is whitespace */
int _is_wspace(char c);

/* print_path - prints all directories on the PATH environment variable */
void print_path(void);

/* _getenv - gets the value of an environment variable */
char *_getenv(const char *vname, enode *env);

/* _setenv - sets the value of an environment variable */
/* int _setenv(const char *name, const char *value, int overwrite); */
int _setenv(char *name, char *value, int overwrite, enode *env);

/* _unsetenv - deletes the value of an environment variable */
/* int _unsetenv(const char *name); */
int _unsetenv(char *name, enode **env);

void ctrlc_handler(int sig_int);

/* void eof_handler(int nread, int e_no, char *lineptr); */
void eof_handler(int nread, int e_no, char *lineptr, enode *env);

/* void _exit_hsh(char *lineptr, char **args, int status); */
void _exit_hsh(char *lineptr, char **args, enode *env, int status);

void rm_linefeed(char *_str);

/* int check_inbuilt(char *command, char **env); */
/* int check_inbuilt(char *command, char **args, char **env); */
int check_inbuilt(char *command, char **args, enode *env);

/* void _printenv(char **env); */
void _printenv(enode *head);

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

/* char *search_path(char *command, char **env); */
char *search_path(char *command, enode *env);

void create_path(char *dest, char *s1, char *s2);

void free_args(char **args);

/* void _run_shell(char **env); */
void _run_shell(enode *env);

/* int launch_program(char **args, char **env); */
int launch_program(char **args, enode *env);

void print_number(int n);

int _pow_recursion(int x, int y);

/* void cmd_not_found(char *command, int num, char **env); */
/* void cmd_not_found(char *command, char **args, int num, char **env); */
void cmd_not_found(char *command, char **args, int num, enode *env);

void normalize_wspace2(char *_str);

void create_path2(char *dest, char *s1, char *s2, char sep);

int _atoi(char *s);

void _non_interactive(char **env);

char *_strdup(char *str);

/* int _cd_home(char *path, char **env); */
/* int _cdir(char *filepath, char **env); */
int _cdir(char *filepath, enode *env);

char *_memset(char *s, char b, unsigned int n);

int free_null(char *dstr);

char **copy_args(char **args);

int _len_args(char **args);

/* linked list functions */
/* int _setenv_ls(char *name, char *value, int overwrite, enode *env); */
/* int _unsetenv_ls(char *name, enode *env); */
/* int _unsetenv_ls(char *name, enode **env); */
/* char *_getenv_ls2(const char *vname, enode *env); */
/* enode *strargs_tolist(char **args, enode *head); */
enode *strargs_tolist(char **args);
enode *add_node_end(enode *head, char *vname, char *vvalue);
/* void free_list(enode *head); */
void free_list(enode **head);
/* int delete_node(enode *head, char *vname); */
int delete_node(enode **head, char *vname);

int _size_envlist(enode *head);

ssize_t _getline2(char **lineptr, size_t *n, FILE *stream);

int _run_inbuilt(char *command, char **args, int i, enode *env);

void launch_prep(char **args, char *command);
/* int _cdir_ls(char *filepath, enode *env); */

#endif
