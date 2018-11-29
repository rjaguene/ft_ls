# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rojaguen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 15:24:39 by rojaguen          #+#    #+#              #
#    Updated: 2018/11/07 15:48:03 by rojaguen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ls

CC			=	gcc #-Wall -Wextra -Werror 
FLAGS		= #-fsanitize=address -g3  -fsanitize-address-use-after-scope \

LIBFTDIR	=	libft/
LIBFT 		=	$(LIBFTDIR)libft.a

SRCDIR		=	src/

SRCS		=	main.c \
				parser/pars.c \
				lst.c \
				print.c

OBJDIR		=	bin/
SUBDIRS		= parser	#structs \
					parser

OBJDIRS		=	$(addprefix $(OBJDIR), $(SUBDIRS))
OBJS		=	$(addprefix $(OBJDIR), $(SRCS:.c=.o))

all: $(LIBFT) $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	@echo "Creating the ft_ls executable..."
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "ft_ls"

$(LIBFT):
	@make -C $(LIBFTDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIRS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(FLAGS) -Iincludes -o $@ -c $<

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
