# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 13:39:06 by ygonzale          #+#    #+#              #
#    Updated: 2023/03/24 14:00:18 by ygonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philosophers
SRC		=	philosophers.c \
			src/utils.c \
			src/linked_list.c \
			src/create_pthread.c 

OBJS	=	$(SRC:.c=.o)
FLAGS	=	gcc -Wall -Werror -Wextra -g3 -fsanitize=address 

#Windows
#FLAGS	=	gcc -Wall -Werror -Wextra -std=c11 -g -D_REENTRANT
#LDLIBS	=	-lpthread

all: $(NAME)

$(NAME): $(OBJS)
	@echo ✅ "\033[92;3;4mcompilation done\033[0m" ✅
	@$(FLAGS) $(LINKS) $(SRC) -o philosophers

#Windows
#$(NAME): $(OBJS)
#	@$(FLAGS) $(LINKS) $(SRC) -o philosophers $(LDLIBS)

%.o : %.c
	$(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo 🗑 "\033[31;3;4mall clean\033[0m" 🗑

fclean: clean
	@rm -f $(NAME)
	@rm -rf philosophers
	@rm -rf philosophers.dSYM

re: fclean all

.PHONY = all clean fclean re