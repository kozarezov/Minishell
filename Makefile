# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceccentr <ceccentr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/07 18:40:14 by cgarth            #+#    #+#              #
#    Updated: 2020/09/19 18:20:16 by ceccentr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Werror -Wextra 

OUR_LIBS = -Llibft/ -lft

SOURCE_h = ./minishell.h

SOURCE_lib = ./libft/libft.a

SRC_c =  minishell.c gnl.c prompt_string.c do_cd.c do_echo.c help_function.c big_split.c parse_env.c take_env.c do_env.c do_export.c do_unset.c take_path.c do_pwd.c do_exit.c switch_our_func_realize.c lsh_launch.c do_redirection.c list_function.c clear.c do_cmd.c check_collision_line.c do_signal.c

CC = clang

.PHONY: all clean fclean re bonus

SRC_obj = $(SRC_c:.c=.o)

all: lib $(NAME)

bonus: all

lib:
	make -C ./libft/

$(NAME): $(SRC_obj) $(SOURCE_lib)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c $(SOURCE_h)
	$(CC) -g -c $(FLAGS) $<

clean:
	rm -f $(SRC_obj)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all