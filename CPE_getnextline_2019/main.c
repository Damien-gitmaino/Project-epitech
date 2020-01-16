/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

char *get_next_line(int fd);

int main(void)
{
	printf("%d\n", READ_SIZE);
	int fd = open("map", O_RDONLY);
	int i = 0;
	char *str = NULL;
	while ((str = get_next_line(fd)) != NULL) {
		printf("-----str-----\n%s\n", str);
		i++;
	}
	printf("%d\n", i);
	close (fd);
	return (0);
}
