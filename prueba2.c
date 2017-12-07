#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
int    main()
{
	char *line;
	int out;
	int p[2];
	int fd;
	int ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcd\n", 5);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	if (strcmp(line, "abcd") == 0)
		ft_putstr("GUAY1\n");
	ret = get_next_line(p[0], &line);
	if (ret == 0)
		ft_putstr("GUAY2\n");
}
