# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 13:39:06 by ygonzale          #+#    #+#              #
#    Updated: 2022/11/25 11:48:47 by ygonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
SRC = philosophers.c

OBJS = $(SRC:.c=.o)
FLAGS = gcc -Wall -Werror -Wextra -g3 -fsanitize=address 

$(NAME): $(OBJS)
	@echo ✅ "\033[92;3;4mcompilation done\033[0m" ✅
	@$(FLAGS) $(LINKS) $(SRC) -o philosophers

%.o : %.c
	$(FLAGS) -c $< -o $@


all: $(NAME)

clean:
	@rm -f $(OBJS)
	@echo 🗑 "\033[31;3;4mall clean\033[0m" 🗑

fclean: clean
	@rm -f $(NAME)
	@rm -rf philosophers

re: fclean all

.PHONY = all clean fclean re