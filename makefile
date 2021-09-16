NAME	=	libftprintf.a

SRCS 	=	ft_parse_flags.c ft_proc_char.c ft_proc_int.c ft_proc_pointer.c ft_proc_prc.c ft_proc_string.c ft_putchar.c ft_proc_uint.c ft_uns_itoa.c translator.c what_flags.c ft_isdigit.c ft_itoa.c ft_strdup.c ft_strlen.c ft_tolower.c ft_proc_hexa.c ft_printf.c

HEADER	=	includes/ft_printf.h

LIBFT	= 	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c\
			ft_lstdelone.c	ft_lstclear.c		ft_lstiter.c	ft_lstmap.c

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

FLAGS	=	-Wall -Wextra -Werror

all		:	${NAME}

${NAME} :	${OBJS} ${HEADER}
			ar rc $(NAME) ${OBJS}

%.o		:	%.c ${HEADER}
	gcc ${FLAGS} -c $< -o $@

clean	:
	@rm -f ${OBJS}

fclean	: 	clean
	@rm -f ${NAME}

re 		:	fclean all

.PHONY :	all clean fclean re
