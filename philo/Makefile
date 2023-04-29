# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 16:18:39 by alevra            #+#    #+#              #
#    Updated: 2023/02/16 18:56:56 by alevra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = $(NAME).h

SRC =	main.c \

BONUS_FLAG = -DBONUS_FLAG
FLAGS = -Wall -Wextra #-Werror
FSAN = -fsanitize=address
OBJ = $(addprefix obj/,$(SRC:.c=.o))
OBJ_BONUS = $(addprefix bonus/,$(SRC:.c=.o))

all	: create_obj_folder
#	make -C libft
	make $(NAME)
	@make end_message

obj/%.o : src/%.c include/$(HEADER) Makefile
	cc -c -g3 ${FLAGS} $(FSAN) $< -o $@ -I include #-I libft

bonus/%.o : src/%.c include/$(HEADER) Makefile
	cc -c -g3 -O3 ${FLAGS} $(FSAN) $(BONUS_FLAG) $< -o $@ -I include #-I libft

$(NAME): $(OBJ) #libft/libft.a
	cc $(OBJ) $(FSAN) -g3 -o $(NAME) #-L ./libft -lft

$(NAME)_bonus: $(OBJ_BONUS) #libft/libft.a
	cc $(OBJ_BONUS) $(FSAN) -g3 -o $(NAME)_bonus #-L ./libft -lft

create_obj_folder :
	@mkdir -p obj
	@mkdir -p bonus

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	@if [ -d "./obj" ]; then\
		rm -r obj;\
	fi
	make clean -C libft

fclean: clean
#	make fclean -C libft
	rm -f $(NAME)
	rm -f $(NAME)_bonus

re:
	make fclean
	make all

end_message:
	@echo "Done !"

bonus:
	@make create_obj_folder
#	make -C libft
	make $(NAME)_bonus
	@make end_message

.PHONY: all clean fclean re create_obj_folder end_message bonus
