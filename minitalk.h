#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

# define	STDOUT	1
# define	STDIN	0

# define	FLAG1	1
# define	FLAG2	2

typedef struct s_glob
{
	pid_t	spid;
	int		sig_flag;
}				t_glob;

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
int		ft_isspace(int c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);

char	*ctobs(int n);
int		bstoc(const char bs[8]);

int		*received(void);
void	set_received(int val);
int		get_received(void);
int		*spid(void);
void	set_spid(int val);
int		get_spid(void);
int		*sig_flag(void);
void	set_sig_flag(int val);
int		get_sig_flag(void);

#endif
