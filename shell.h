#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


#define READ__SIZE 1024
#define WRITE__SIZE 1024
#define BUF_FLUSH -1


#define CMD__NORM	0
#define CMD__OR		1
#define CMD__AND	2
#define CMD__CHAIN	3


#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2


#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct my_lists_t - singly linked list
 * @number:  number of field.
 * @s: a string
 * @next: point to next node.
 */
typedef struct my_lists_t
{
	int number;
	char *s;
	struct my_lists_t *next;
} my_list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@arg_v: array of strings generated from arg
 *@path: String input for the current command.
 *@arg_c: Argument count.
 *@l_count: error countER
 *@err_num: the error code for exit()s
 *@lcount_ch: If count this line of input.
 *@filename:  the filename.
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@the_history:  History node.
 *@alias: the alias node
 *@env_ch: on if environ was changed
 *@statuss: Return status of the last executed command.
 *@cmd_buff: address of pointer to cmd_buf, on if chaining
 *@cmd_type: CMD_type ||, &&, ;
 *@readf: the fd from which to read line input
 *@historycount: line number counter.
 */
typedef struct passinfo
{
	char *arg;
	char **arg_v;
	char *path;
	int arg_c;
	unsigned int l_count;
	int err_num;
	int lcount_ch;
	char *filename;
	my_list_t *env;
	my_list_t *the_history;
	my_list_t *alias;
	char **environ;
	int env_ch;
	int statuss;

	char **cmd_buff; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_type; /* CMD_type ||, &&, ; */
	int readf;
	int historycount;
} info_tt;

#define INFO__INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtinn - builtin string and function
 *@type: the builtin command flag
 *@fun: the function
 */
typedef struct builtinn
{
	char *type;
	int (*fun)(info_tt *);
} builtintable;

char *memset_func(char *, char, unsigned int);
void free_str(char **);
void *find_str(void *, unsigned int, unsigned int);

int interactive_fun(info_tt *);
int isdelim_fun(char, char *);
int isalpha_fun(int);
int atoi_fun(char *);

int help_fun(info_tt *);
int exit_fun(info_tt *);
int cd_fun(info_tt *);

int history_fun(info_tt *);
int alias_fun(info_tt *);

int if_cmd(info_tt *, char *);
char *d_char(char *, int, int);
char *f_path(info_tt *, char *, char *);

int env_fun(info_tt *);
char *getenv_fun(info_tt *, const char *);
int setenv_fun(info_tt *);
int unsetenv_fun(info_tt *);
int popenv_list(info_tt *);

int free_function(void **);

char **getenviron_fun(const char *v);
int __unsetenv(char **ar, char **fr);
int __setenv(char **ar, char **fr);

void clearinfo_fun(info_tt *);
void setinfo_fun(info_tt *, char **);
void freeinfo_fun(info_tt *, int);

ssize_t getinput_fun(info_tt *);
void siginthandler_fun(int);
int getline_fun(info_tt *, char **, size_t *);

char *find_history_file(info_tt *info);
int history_w(info_tt *info);
int history_rm(info_tt *info);
int bhistoryl(info_tt *info, char *buf, int l_count);
int history_r(info_tt *info);

my_list_t *insert_node(my_list_t **, const char *, int);
my_list_t *insert_end_node(my_list_t **, const char *, int);
size_t print_node(const my_list_t *);
int delete_index(my_list_t **, unsigned int);
void free_linked(my_list_t **);

size_t l_l(const my_list_t *);
char **l_to_s(my_list_t *);
size_t put_liststr(const my_list_t *);
my_list_t *start_node(my_list_t *, char *, char);
ssize_t find_node_index(my_list_t *, my_list_t *);

int convert_func(char *);
void put_error(info_tt *, char *);
int _putt(int, int);
char *convert_d(long int, int, int);
void delete_message(char *);

void eputs_func(char *);
int eputchar_func(char);
int putfd_func(char ch, int filed);
int putsfd_d(char *s, int filed);

int hsh(info_tt *, char **);
int findbuilt_fun(info_tt *);
void git_cmd(info_tt *);
void f_cmd(info_tt *);

int strlen_func(char *);
int strcmp_func(char *, char *);
char *starts_with_func(const char *, const char *);
char *strcat_func(char *, char *);

char *strcpy_func1(char *, char *);
char *strdup_func1(const char *);
int _putchar(char);
void puts_func(char *);

char *strncpy_func2(char *, char *, int);
char *strncat_func2(char *, char *, int);
char *strchr_func2(char *, char);

int ischain_fun(info_tt *, char *, size_t *);
void checkchain_fun(info_tt *, char *, size_t *, size_t, size_t);
int repalias_fun(info_tt *);
int repstring_fun(char **, char *);
int repvars_fun(info_tt *);

char **strtow_func(char *, char *);
char **strtow_func2(char *, char);

int main(int, char **);
#endif
