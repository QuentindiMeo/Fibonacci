/*
** PERSONAL PROJECT, 2019
** fibonacci
** File description:
** fibonacci writing functions
*/

#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../include/fib.h"
#include "../include/my.h"

static void writing_result(int fd, char *nth, char *nb)
{
    lseek(fd, 0, SEEK_END);
    write(fd, "  F(", 4);
    write(fd, nth, my_strlen(nth));
    write(fd, ")\t", 3);
    if (my_strlen(nth) < 3)
        write(fd, "\t", 1);
    write(fd, "=\t", 2);
    write(fd, nb, my_strlen(nb));
    write(fd, "\n", 1);
}

void write_result(uint nth, char *nb, set_t *settings)
{
    int fd;
    char *n_th = NULL;

    if (!settings->silent)
        printf("  F(%u)\t%c=\t%s\n", nth, nth > 99 ? '\0' : '\t', nb);
    if (settings->store) {
        n_th = my_utoa(nth);
        fd = open("calculations_fib.txt", O_CREAT | O_WRONLY);
        fchmod(fd, 0666);
        writing_result(fd, n_th, nb);
        close(fd);
        free(n_th);
    }
    usleep(settings->slow);
}
