# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aheister <aheister@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/27 10:21:22 by aheister      #+#    #+#                  #
#    Updated: 2021/05/05 12:37:50 by aheister      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER	=	checker
NAME_PUSHSWAP	=	push_swap
NAMES			=	$(NAME_CHECKER) $(NAME_PUSHSWAP)

CFLAGS			=	-Wall -Werror -Wextra
CC				=	gcc -g

LIBFT			=	libft/libft.a

SH_SRCS			=	srcs/checks.o\
					srcs/initialize.o\
					srcs/ops_multi.o\
					srcs/ops_single.o\

CH_SRCS			=	srcs/checker/checker.o\
					srcs/checker/get_next_line.o\
					srcs/checker/get_next_line_utils.o\
					
PS_SRCS			=	srcs/push_swap/push_swap.o\
					srcs/push_swap/sort_small.o\
					srcs/push_swap/sort_medium.o\
					srcs/push_swap/sort_big.o\
					srcs/push_swap/sort_big_utils.o\

HEADER_FILES	=	includes/push_swap.h

%.o:				%.c $(HEADER_FILES)
					$(CC) -c $(CFLAGS) -o $@ $<	

OBJ_CHECKER		=	$(CH_SRCS) $(SH_SRCS)
OBJ_PUSHSWAP	=	$(PS_SRCS) $(SH_SRCS)

all:				$(NAMES)

$(LIBFT):			
					$(MAKE) -C libft

$(NAME_CHECKER):	$(OBJ_CHECKER) $(LIBFT)
					$(CC) $(CFLAGS) -o $(NAME_CHECKER) $(OBJ_CHECKER) $(LIBFT)
					
$(NAME_PUSHSWAP):	$(OBJ_PUSHSWAP) $(LIBFT)
					$(CC) $(CFLAGS) -o $(NAME_PUSHSWAP) $(OBJ_PUSHSWAP) $(LIBFT)

clean:
					rm -f $(SH_SRCS) $(CH_SRCS) $(PS_SRCS)
					$(MAKE) clean -C libft

fclean:				clean
					rm -f $(NAME_CHECKER) $(NAME_PUSHSWAP)
					rm -f $(LIBFT)

re:
					$(MAKE) fclean
					$(MAKE) all

.PHONY:				all clean fclean re
