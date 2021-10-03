LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = push_swap

SRCS =  sources/instructions/instruction_func.c \
        sources/instructions/lstadd_back.c \
        sources/instructions/lstadd_front.c \
        sources/instructions/lstdel.c \
        sources/instructions/lstlast.c \
        sources/instructions/lstnew.c \
        sources/instructions/lstsize.c \
        sources/instructions/operation_func.c \
        sources/instructions/operation_func2.c \
        sources/parsing/check_func.c \
        sources/parsing/parse_func.c \
        sources/parsing/parse_func2.c \
        sources/main.c \
        sources/quick_sort.c \
        sources/simple_sort.c \
        sources/simple_sort_b.c \

SURPL_O = sources/instructions/instruction_func.o \
		  sources/instructions/lstadd_back.o \
		  sources/instructions/lstadd_front.o \
		  sources/instructions/lstdel.o \
		  sources/instructions/lstlast.o \
		  sources/instructions/lstnew.o \
		  sources/instructions/lstsize.o \
		  sources/instructions/operation_func.o \
		  sources/instructions/operation_func2.o \
		  sources/parsing/check_func.o \
		  sources/parsing/parse_func.o \
		  sources/parsing/parse_func2.o \
		  sources/main.o \
          sources/quick_sort.o \
          sources/simple_sort.o \
          sources/simple_sort_b.o \

sources/%.o: sources/%.c
	$(CC) $(FLAGS) $(INCLUDES) $< -o $@

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) libft.a -C ./libft
	$(CC) -Wall -Werror -Wextra $(OBJS) libft/libft.a -o $@

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