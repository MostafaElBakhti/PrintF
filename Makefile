CC = cc
CFLAGS = -Wall -Wextra -Werror 
NAME = libftprintf.a
RM = rm -f 
AR = ar rcs 

SRCS = ft_printf.c \
       ft_putstr.c \
       ft_putchar.c \
       ft_puthex.c \
       ft_putnbr.c \
       ft_putunsigned.c \
       ft_putptr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@ 


clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
