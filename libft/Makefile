# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aheister <aheister@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/05 11:41:15 by aheister      #+#    #+#                  #
#    Updated: 2021/04/29 10:06:21 by aheister      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a
OBJ_FILES		= 	ft_atoi.o\
					ft_strncmp.o\
					ft_lstadd_front.o\
					ft_lstadd_back.o\
					ft_lstdel.o\
					ft_lstlast.o\
					ft_lstnew.o\
					ft_lstsize.o\

HEADER_FILES	=	libft.h
CFLAGS			=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ_FILES)
			ar -rcs $(NAME) $(OBJ_FILES)

%.o: 		%.c $(HEADER_FILES)
			gcc -c $(CFLAGS) -o $@ $<

clean:
			rm -f $(OBJ_FILES)

fclean: clean
			rm -f $(NAME)

re:
			$(MAKE) fclean
			$(MAKE) all

.PHONY: 	all clean fclean re
