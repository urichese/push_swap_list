cmake_minimum_required(VERSION 3.19)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap sources/main.c
        sources/push_swap.h
        sources/parsing/parse_func.c
        sources/parsing/parse_func2.c
        sources/parsing/check_func.c
        sources/simple_sort.c
        libft/ft_atoi.c libft/ft_calloc.c libft/ft_bzero.c
        libft/ft_isdigit.c libft/ft_isspace_bonus.c libft/ft_isdigit.c libft/ft_memset.c
        libft/ft_putstr_fd.c libft/ft_putnbr_fd.c libft/ft_putchar_fd.c
        libft/ft_lstnew.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c
        libft/ft_lstlast.c libft/ft_lstsize.c
        sources/quick_sort.c
        sources/instructions/instruction_func.c
        sources/instructions/operation_func.c
        sources/instructions/operation_func2.c
        sources/instructions/lstadd_back.c
        sources/instructions/lstadd_front.c
        sources/instructions/lstlast.c
        sources/instructions/lstnew.c
        sources/instructions/lstsize.c sources/instructions/lstdel.c)