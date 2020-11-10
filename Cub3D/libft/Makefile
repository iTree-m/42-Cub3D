# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichejra <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 10:44:40 by ichejra           #+#    #+#              #
#    Updated: 2020/03/09 12:38:46 by ichejra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FUNCTIONS = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_strlen ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_strlcpy ft_strlcat ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_isspace

BONUSFT = ft_lstnew_bonus ft_lstadd_front_bonus ft_lstsize_bonus ft_lstlast_bonus ft_lstadd_back_bonus ft_lstdelone_bonus ft_lstclear_bonus ft_lstiter_bonus ft_lstmap_bonus ft_strcmp_bonus ft_strcpy_bonus ft_strncpy_bonus ft_strstr_bonus ft_strcat_bonus ft_is_prime_bonus

FLAGS = -Wall -Wextra -Werror -c
BINS = $(patsubst %, %.o, $(FUNCTIONS))
BINBON = $(patsubst %, %.o, $(BONUSFT))

all: $(NAME)

$(NAME): $(BINS)
	@gcc $(FLAGS) $(patsubst %, %.c, $(FUNCTIONS)) -I .
	@ar rc $(NAME) $(BINS)
	@ranlib $(NAME)

clean:
	@rm -f $(BINS)
	@rm -f $(BINBON)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: all $(BINBON)
	@gcc $(FLAGS) $(patsubst %, %.c, $(BONUSFT)) -I .
	@ar rc $(NAME) $(BINBON)
	@ranlib $(NAME)
