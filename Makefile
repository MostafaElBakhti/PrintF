CC = cc #even without this line, cc is used by default
CFLAGS = -Wall -Wextra -Werror #even without this line, these flags are used by default
NAME = libftprintf.a
RM = rm -f 
AR = ar rcs ## r -> replace or add, c -> create, s -> index

SRCS = ft_printf.c \
       ft_putstr.c \
       ft_putchar.c \
       ft_puthex.c \
       ft_putnbr.c \
       ft_putunsigned.c \
       ft_putptr.c

OBJS = $(SRCS:.c=.o) # replace .c with .o , called substitution pattern

## default target , should be the first one
all: $(NAME)

## create static library
$(NAME): $(OBJS) 
	$(AR) $(NAME) $(OBJS)

## compile source files to object files
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@ 
# $< is the first dependencie (the .c file), $@ is the target (the .o file)
# we add ft_printf.h as a dependency to recompile if the header changes

## clean up object files
clean: 
	$(RM) $(OBJS)

## remove library file
fclean: clean
	$(RM) $(NAME)

## full clean and rebuild
re: fclean all
