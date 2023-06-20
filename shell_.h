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


#define _ CMD_NORM	(0)
#define _CMD_OR		1
#define _CMD_AND	2
#define _CMD_CHAIN	3


#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2


#define GET_LINE 0
#define START_OK 0

#define HISTORY_FILE	"_simple_shell_history"
#define HISTORY_MAX	4096

extern char **environment;


/**
 * struct my_list - sing linked list.
 *
 * @number: the number of  field.
 * @s: string.
 *
 * @next: pointer to point to the next node.
 */
typedef struct my_list
{
	int number;
	char *s;
	struct my_list *next;
} my_list_t;

/**
 *struct pass_information - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@line_count: the error count.
 *@fname: the program filename.
 *@argv: an array of strings generated from arg.
 */
typedef struct pass_information
{
	char **argv;
	unsigned int line_count;
	char *fname;
} info_t;










int strlen_func(char *);
int strcmp_func(char *, char *);
char *starts_with_func(const char *, const char *);
char *strcat_func(char *, char *);
char *strcpy_func(char *, char *);
char *strdup_func(const char *);
void puts_func(char *);
int _putchar(char);
char strncpy_2(char *, char *, int );
char strncat_2(char *, char *, int );
char strchr_2(char *, char );
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
int eputchar(char);
int putfd_func(char c, int fd);
int putsfd_print(char *str, int fd);








#endif
