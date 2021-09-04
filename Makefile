LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = push_swap

SRCS =  sources/bubble_sort.c \
		sources/functions.c \
		sources/main.c

SURPL_O = sources/bubble_sort.o \
          sources/functions.o \
          sources/main.o

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) libft.a -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O)
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all