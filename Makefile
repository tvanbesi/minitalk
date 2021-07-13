SRCS		= 	conversion.c \
				ft_atoi.c \
				ft_isdigit.c \
				ft_isspace.c \
				ft_putchar_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_strlen.c \
				acknowledge.c \
				spid.c \
				sig_flag.c
OBJS		= ${SRCS:.c=.o}
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
NAME		= server
RM			= rm -f

%.o :			%.c
				${CC} ${CFLAGS} -c $<
all :			${NAME}
${NAME} :		server.o client.o ${OBJS}
				clang -o ${NAME} server.o ${OBJS}
				clang -o client client.o ${OBJS}
clean :
				${RM} ${OBJS} server.o client.o
fclean :		clean
				${RM} ${NAME} client
re :			fclean all
.PHONY :
			all ${NAME} clean fclean re
