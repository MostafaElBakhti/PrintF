CC = gcc
CFLAGS = -Wall -Wextra -Werror
Name = libftprintf.a

SRCS = ft_printf.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putnbr.c \
	   ft_putunsigned.c \
	   ft_puthex.c \
	   ft_putptr.c 
	   
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
