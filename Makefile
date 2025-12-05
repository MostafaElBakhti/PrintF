CC = gcc
CFLAGS = -Wall -Wextra -Werror
Name = libftprintf.a

SRCS = ft_printf.c \
	   ft_printf_utils.c \
	   ft_printf_utils2.c \
	   ft_printf_utils3.c \
	   ft_printf_utils4.c
OBJS = $(SRCS:.c=.o)

all: $(Name)

$(Name): $(OBJS)
	ar rcs $(Name) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(Name)

re: fclean all
