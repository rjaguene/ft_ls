#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 17:52:57 by tfleming          #+#    #+#              #
#    Updated: 2018/08/10 15:39:24 by rojaguen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =				libft.a

CC =				gcc
FLAGS =				-Wall -Werror -Wextra

INCLUDES =			./includes
FT_SRC_DIR =		./libft
PRINTF_SRC_DIR =	./printf

FT_COMPILED =		ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
ft_toupper.o ft_tolower.o ft_atoi.o ft_strstr.o ft_strlen.o ft_strdup.o \
ft_strcpy.o ft_strncpy.o ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o \
ft_strrchr.o ft_strcmp.o ft_strnstr.o ft_memset.o ft_bzero.o ft_memcpy.o \
ft_memccpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strncmp.o \
ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o \
ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o \
ft_strjoin.o ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o ft_putstr.o \
ft_putendl.o ft_putnbr.o ft_putchar_fd.o ft_sqrt.o \
ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_strupcase.o ft_strlowcase.o \
ft_lstiter.o ft_lstadd.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstmap.o \
ft_is_prime.o ft_find_next_prime.o get_next_line.o

PRINTF_COMPILED =					ft_printf.o \
									ft_stock_percent.o \
									ft_stock_s.o \
									ft_stock_u.o \
									ft_stock_x.o \
									ft_strcat_f.o \
									ft_check_flag.o \
									ft_init_bool.o  \
									ft_itoa2.o \
									ft_itoa_base.o \
									ft_stock_c.o \
									ft_stock_d.o \
									ft_stock_d2.o \
									ft_stock_lx.o \
									ft_stock_o.o \
									ft_stock_p.o

COMPILED =			$(FT_COMPILED) $(PRINTF_COMPILED)

all: $(NAME)

$(NAME): $(COMPILED)
	@ar rc $(NAME) $(COMPILED)
	@ranlib $(NAME)
	@echo "made" $(NAME)

$(FT_COMPILED): %.o: $(FT_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(INCLUDES) $< -o $@

$(PRINTF_COMPILED): %.o: $(PRINTF_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(INCLUDES) $< -o $@


clean:
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
