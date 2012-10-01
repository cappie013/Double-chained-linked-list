## Copyright 2012 Sebastien Loyer

## Licensed under the Apache License, Version 2.0 (the "License");
## you may not use this file except in compliance with the License.
## You may obtain a copy of the License at

## http://www.apache.org/licenses/LICENSE-2.0

## Unless required by applicable law or agreed to in writing, software
## distributed under the License is distributed on an "AS IS" BASIS,
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
## See the License for the specific language governing permissions and
## limitations under the License.

NAME		=	lib_linkedlist.a

CC		=	gcc

CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		+=	-I$(DIR_HEADERS)

RM		=	rm -vf

DIR_HEADERS	=	header/

DIR_FILES	=	srcs/

FILES		=	list_init.c		\
			list_push_back.c	\
			list_push_front.c	\
			list_push_at.c		\
			list_concat_back.c	\
			list_concat_front.c	\
			list_concat_at.c	\
			list_pop_back.c		\
			list_pop_front.c	\
			list_get_back.c		\
			list_get_front.c	\
			list_get_at.c		\
			list_iter.c		\
			list_iter_rev.c		\
			list_clear.c		\
			list_remove_range.c	\
			list_remove_at.c	\
			list_delete.c		\
			list_dup.c		\
			list_reverse.c		\
			list_find.c		\
			list_swap.c		\

SRCS		=	$(addprefix $(DIR_FILES), $(FILES))

OBJS		=	$(SRCS:.c=.o)

$(NAME):		$(OBJS)
			@ar rc $(NAME) $(OBJS)
			@echo -en "\033[36m"
			ranlib $(NAME)
			@echo  "\033[1;32mLinkedlist library ready !\033[0m"

all:			$(NAME)

clean :
			@$(RM) $(OBJS)

fclean:			clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY: 		all clean fclean re
