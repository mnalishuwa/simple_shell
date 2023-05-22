#ifndef MAIN_H
#define MAIN_H

#define _ASC_SPACES "\t\n\v\f\r \x85\xa0"

#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

struct _argv_argcount
{
	char **_args;
	size_t _count;
};

/* _putchar - print single char to stdout */
int _putchar(char c);

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
int _setenv(const char *name, const char *value, int overwrite);

/* _unsetenv - deletes the value of an environment variable */
int _unsetenv(const char *name);

/* _strtoargs - creates a struct with an array of string arguments */
struct _argv_argcount *_strtoargs(char *_str, const char __attribute__((unused)) *_DELIM);

/* search_path - gets a command and checks if the file executable exists on the PATH */
char *search_path(char *command);

void ctrlc_handler(int sig_int);

void eof_handler(int nread, int e_no);

void _exit_hsh(int status);

typedef void (*env_func_t)(char **);
typedef void (*ext_func_t)(int);

struct inblts
{
	char *inb_command;
	union
	{
		env_func_t env_func;
		ext_func_t ext_func;
	} inb_func;
};

void rm_linefeed(char *_str);

int check_inbuilt(char *command, char **env);

void _printenv(char **env);

int _strcmp(char *s1, char *s2);

/* get a stream of characters from stdin */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* get the file descriptor from a FILE stream */
int _fileno(FILE *stream);

/* remove excess whitespace */
char *normalize_wspace(char *_str, size_t len_s);

/* tokenize string and return an array of words from the string */
char **_strtok(char *_str, const char *_delim);

/* find substring in string */
char *_strstr(char *haystack, char *needle);

/* copy string from source upto max n bytes */
char *_strncpy(char *dest, char *src, size_t n);

/* allocate new_sized ptr and copy contents of old into new ptr */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* get null terminated string length */
int _strlen(char *s);

/* delete trailing whitespace */
void del_twspace(char *s);

#endif
