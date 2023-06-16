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
 * struct pass_information - contains arguements to pass into  function.
 *allowing uniform prototype for function pointer struct
 * @ar_g: a string  from getline containing arguements.
 *
 * @arg_v:an array containing values.
 *
 * @path_arg: a string pathed  for  command.
 *
 * @arg_c: number of arguments.
 *
 * @error_line_count: the error counter.
 *
 * @error_number: error code for exit()s.
 *
 * @line_counter_flag: if on count this line of input.
 *
 * @file_name: the filename.
 *
 * @env_list: linked list local copy of environment
 *
 * @enviro_n:  modified copy of environment from Linked list env_list.
 *
 * @history_n: node history.
 *
 * @alia_s:  alias node.
 *
 * @env_change: if environ be changed.
 *
 * @status: the return status of the last command.
 *
 * @cmd_buffer: address of pointer to cmd_buffer if chainging.
 *
 * @cmd_buffer__type: CMD_types ||, &&, ;.
 *
 * @read_f: the f from which, to read line input.
 *
 * @history_count: line nubmer count.
 */
typedef struct pass_information
{
	char *ar_g;
	char **arg_v;
	char *path_arg;
	int arg_c;
	unsigned int error_line_count;
	int error_num;
	int line_counter_flag;
	char *file_name;
	my_list_t *env_list;
	my_list_t *history_n;
	my_list_t *alia_s;
	char **enviro_n;
	int env_change;
	int status;

	char **cmd_buffer; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buffer_type; /* CMD_type ||, &&, ; */
	int read_f;
	int history_count;
} information_t;
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
