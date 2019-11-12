/*
** PERSONAL PROJECT, 2019
** fibonacci
** File description:
** fibonacci help
*/

#include <stdio.h>
#include "../include/my.h"

static void help2(void)
{
    printf("NUM\033[0m\n\t\tCompute"
    " the sequence until the \033[4mNUM\033[0mth Fibonacci number.\n\n\t"
    "\033[1m-E\033[0m \033[4mNUM\033[0m, \033[1m--end\033[0m=\033[4mNUM\033[0m"
    "\n\t\tCompute the sequence while the result is inferior to \033[4mNUM"
    "\033[0m.\n\n\t\033[1m-F\033[0m \033[4mNUM\033[0m, \033[1m--find\033[0m="
    "\033[4mNUM\033[0m\n\t\tFind and print the \033[4mNUM\033[0mth Fibonacci "
    "number. Using this will\n\t\tdeny all other parameter.\n\n\t\033[1m-S"
    "\033[0m \033[4mNUM\033[0m, \033[1m--start\033[0m=\033[4mNUM\033[0m\n\t\t"
    "\033[1mNOT IMPLEMENTED YET\033[0m\n\t\t"
    "Start computing the sequence at \033[4mNUM\033[0m.\n\n\tAn invalid parame"
    "ter will automatically set the associated option  to\n\tdefault. You can "
    "quit the program by hitting CTRL+C.\n\n   "
    "\033[1mExit status\033[0m:\033[0m\n\t0\tif everything went as exp"
    "ected,\n\t84\tif an invalid argument was passed to the program.\n\n "
    "\033[1mPRINTING FORMAT\033[0m\n\t$>  F(\033[4mn\033[0m)          "
    "=        \033[4mvalue\033[0m\n\n \033[1mAUTHOR\033[0m\n\tWritten by "
    "Quentin di Meo.\n\n \033[1mREPORTING BUGS\033[0m\n\tReport any bug or "
    "functioning error to <quentin.di-meo@epitech.eu>\n\n");
}

int help(void)
{
    printf("\n\tWelcome to Fibonacci.\n\n \033[1mUSAGE\033[0m\n\t"
    "./fibonacci [\033[4mOPTION\033[0m]\n\n \033[1mDESCRIPTION\033[0m\n\t"
    "The  Fibonacci  sequence  consists  in adding up the two last numbers\n\t"
    "to obtain a third number, which will be used to continue the sequence\n\t"
    "in an never-ending manner, using 0 and 1 and the two first members.\n\t"
    "We thus have F(0) = 0 and F(1) = 1, so F(2) = F(0) + F(1) = 0 + 1 = 1\n"
    "\n\t\033[1m-d\033[0m \033[4mDIG\033[0m, \033[1m--digits\033[0m=\033[4m"
    "DIG\033[0m\n\t\tCompute the sequence until the result is \033[4mDIG"
    "\033[0m-digits long.\n\n\t\033[1m-h\033[0m, \033[1m--help\033[0m\n\t\t"
    "Display this help.\n\n\t\033[1m--silent\033[0m\n\t\tMake it so that the p"
    "rogram doesn't display what it finds.\n\n\t\033[1m--slow\033[0m=\033[4mMS"
    "\033[0m\n\t\tSlow down the program by  waiting  \033[4mMS\033[0m  milli"
    "seconds  after\n\t\tevery iteration.  I'm suggesting 50, the limit is 100"
    ",000.\n\n\t\033[1m--store\033[0m\n\t\tMake the program store the results "
    " it  finds in  a  file,\n\t\t\033[3mcalculations_fib.txt\033[0m, allowing"
    " you to read all of the last\n\t\trequested results. Be careful, it grows"
    " exponentially fast\n\t\tin size (7MB for results from F(0) to F(8300))."
    "\n\n\t\033[1m-u\033[0m \033[4mNUM\033[0m, \033[1m--until\033[0m=\033[4m");
    help2();
    return (SUCCESS);
}
