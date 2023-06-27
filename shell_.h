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
#define CMD__AND		2
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
typedef struct my_liststr
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
 *@input: String input for the current command.
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
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readf: the fd from which to read line input
 *@historycount: line number counter.
 */
typedef struct passinfo
{
	char *arg;
	char **arg_v;
	char *input;
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

void eputs_func(char *);
int eputchar_func(char);
int putfd_func(char c, int fd);
int putsfd_d(char *str, int fd);

int strlen_func(char *);
int strcmp_func(char *, char *);
char *starts_with_func(const char *, const char *);
char *strcat_func(char *, char *);
<<<<<<< HEAD
char *strcpy_func(char *, char *);
char *strdup_func(const char *);
void puts_func(char *);
int _putchar(char);
/** str*/

char *strncpy_2(char *, char *, int);
char *strncat_2(char *, char *, int);
char *strchr_2(char *, char);

//char strncpy_2(char *, char *, int);
//char strncat_2(char *, char *, int);
//char strchr_2(char *, char);
/** str*/
char *strncpy_2(char *, char *, int );
char *strncat_2(char *, char *, int );
char *strchr_2(char *, char );
/*char strncpy_2(char *, char *, int);
//char strncat_2(char *, char *, int);
<<<<<<< HEAD
//char strchr_2(char *, char);*/

//char strchr_2(char *, char
//
char **strtow_func(char *, char *);
char **strtow_func2(char *, char);
char *memset_func(char *, char, unsigned int);
void free_func(char **);
void *realloc_func(void *, unsigned int, unsigned int);
int free_function(void **);
int convarte_(char *);
void error_1(info_t *, char *);
int print_func(int, int);
char *convert_3(long int, int, int);
void remove_comments_message(char *);
void eputs_func(char *);
int Eput(char);
int putfd_func(char c, int fd);
int putsfd_print(char *str, int fd);
my_list_t *add_new_node(my_list_t **, const char *, int);
my_list_t *add_end_node(my_list_t **, const char *, int);
size_t print_str(const my_list_t *);
int remove_node(my_list_t **, unsigned int);
void freee_func(my_list_t **);
int if_cmd(info_t *, char *);
char *d_char(char *, int, int);
char *f_path(info_t *, char *, char *);
char *find_history_file(info_t *info);
int history_w(info_t *info);
int history_r(info_t *info);
int history_l(info_t *info, char *buf, int linecount);
int history_rm(info_t *info);
int ischain_fun(info_t *, char *, size_t *);
void checkchain_fun(info_t *, char *, size_t *, size_t, size_t);
int repalias_fun(info_t *);
int repvars_fun(info_t *);
int repstring_fun(char **, char *);
char **getenv_f(info_t *);
int unsetenv_fun(info_t *, char *);
int setenv_fun(info_t *, char *, char *);
char *getenv_fun(info_t *, const char *);
int env_fun(info_t *);
int setenv_f(info_t *);
int unsetenv_f(info_t *);
int penv_list(info_t *);
void clearinfo_fun(info_t *);
void setinfo_fun(info_t *, char **);
void freeinfo_fun(info_t *, int);
ssize_t getinput_fun(info_t *);
int getline_fun(info_t *, char **, size_t *);
void sigintandler_fun(int);
ssize_t inputbuf_fun(info_t *, char **, size_t *);
ssize_t readbuf_fun(info_t *, char *, size_t *);
int history_fun(info_t *);
int alias_fun(info_t *);
int printalias_fun(my_list_t *);
int setalias_fun(info_t *, char *);
int unsetalias_fun(info_t *, char *);
int exit_fun(info_t *);
int cd_fun(info_t *);
int help_fun(info_t *);
int interactive_fun(info_t *);
int delim_fun(char, char *);
int alpha_fun(int);
int atoi_fun(char *);
int mshell(info_t *, char **);
int findbuilt_fun(info_t *);
void git_cmd(info_t *);
void f_cmd(info_t *);



#endif


