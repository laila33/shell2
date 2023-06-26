#ifndef SHELL__H_
#define SHELL__H_

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
#define _FLUSH -1


#define CMD_NORM	(0)
#define CMD_OR		1
#define CMD_AND	        2
#define CMD_CHAIN	3


#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2


#define HIST_FILE	"__simple_shell_history"
#define HIST_MAX	4096
extern char **environment;


/**
 * struct my_list - sing linked list.
 *
 * @number: the number of  field.
 * @s: string.
 *
 * @next: pointer to point to the next node.
 */
typedef struct my_liststr
{
	int number;
	char *s;
	struct my_liststr *next;
} my_list_t;

/**
 *struct pass_information - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@l_count: the error count.
 *@fname: the program filename.
 *@argv: an array of strings generated from arg.
 *@input: a string path for the current command.
 *@history: history node.
 *@historycount: history line number count.
 *@lcount_ch: if on count this line of input.
 *@status: return status of  last command.
 */
typedef struct pass_information
{
	char **argv;
	unsigned int l_count;
	char *fname;
	char *input;
	my_list_t *history;
	int historycount;
	int lcount_ch;
	int status;
} info_t;










int strlen_func(char *);
int strcmp_func(char *, char *);
char *starts_with_func(const char *, const char *);
char *strcat_func(char *, char *);
char *strcpy_func(char *, char *);
char *strdup_func(const char *);
void puts_func(char *);
int _putchar(char);
char *strncpy_2(char *, char *, int );
char *strncat_2(char *, char *, int );
char *strchr_2(char *, char );
char **strtow_func(char *, char *);
char **strtow_func2(char *, char);
char *memset_func(char *, char , unsigned int);
void free_func(char **);
void *realloc_func(void *, unsigned int , unsigned int);
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






#endif
