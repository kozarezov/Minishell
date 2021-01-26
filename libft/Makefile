# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceccentr <ceccentr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/07 18:40:14 by cgarth            #+#    #+#              #
#    Updated: 2020/09/18 13:01:26 by ceccentr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SOURCE_h = libft.h

SRC_c =  ft_memccpy.c ft_memcpy.c ft_memset.c ft_atoi.c ft_bzero.c ft_strncmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_strrchr.c ft_strnstr.c ft_strchr.c ft_memcmp.c ft_strdup.c ft_memchr.c ft_memmove.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

bonus_SRC_c = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c ft_lstiter.c ft_lstdelone.c ft_lstclear.c

.PHONY: all clean fclean re bonus

SRC_obj = $(SRC_c:.c=.o)

bonus_SRC_obj = $(bonus_SRC_c:.c=.o)

all: $(NAME)

$(NAME): $(SRC_obj)
	ar rc $(NAME) $?

$(SRC_obj): %.o: %.c $(SOURSE_h)
	$(CC) -c $(FLAGS) $<

bonus: $(NAME) $(bonus_SRC_obj) 
	ar rc $(NAME) $(bonus_SRC_obj)

$(bonus_SRC_obj): %.o: %.c $(SOURSE_h)
	$(CC) -c $(FLAGS) $<

clean:
	rm -f $(SRC_obj) $(bonus_SRC_obj)

fclean: clean
	rm -f $(NAME)

re: fclean all