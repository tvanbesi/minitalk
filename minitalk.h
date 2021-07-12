#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

//REMOVE FOR DEFENCE
# include <errno.h>
# include <string.h>
# include <stdio.h>

# define	STDOUT	1
# define	STDIN	0

# define	FLAG1	0
# define	FLAG2	1

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
int		ft_isspace(int c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);

char	*ctobs(int n);
int		bstoc(const char *bs);

#endif
