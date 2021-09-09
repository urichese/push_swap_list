LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = push_swap

SRCS =  sources/check_func.c \
		sources/instruction_func.c \
		sources/main.c \
        sources/operation_func.c \
        sources/parse_func.c \
        sources/quick_sort.c \
        sources/simple_sort.c

SURPL_O = sources/check_func.o \
          sources/instruction_func.o \
          sources/main.o \
		  sources/operation_func.o \
		  sources/parse_func.o \
		  sources/quick_sort.o \
		  sources/simple_sort.o

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
	rm -rf *.o

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all