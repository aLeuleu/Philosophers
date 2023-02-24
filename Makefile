
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 15:01:30 by alevra            #+#    #+#              #
#    Updated: 2023/01/09 11:45:21 by alevra           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEADER = $(NAME).h

SRC = main.c

FLAGS = -Wall -Wextra -Werror

BONUS_FLAG = -DBONUS_FLAG

OS := $(shell uname)
ifeq ($(OS),Darwin)

else

endif

OBJ = $(addprefix obj/,$(SRC:.c=.o))
OBJ_BONUS = $(addprefix bonus/obj_bonus/,$(SRC:.c=.o))

FSAN = -fsanitize=address

all	: create_obj_folder
	make -C libft
	make -j1 -C $(MLX)
	cp $(MLX)/$(MLX_LIB) ./$(MLX_LIB)
	make $(NAME)
	@make end_message

$(NAME): libft/libft.a $(OBJ) $(HEADER)
	cc $(OBJ) $(FSAN) $(MLX_FLAGS) -g3 -O3 -L ./libft -lft -lm -o $(NAME)

$(NAME)_bonus: libft/libft.a $(OBJ_BONUS) $(HEADER)
	cc $(OBJ_BONUS) $(FSAN) $(MLX_FLAGS) -g3  -L ./libft -lft -lm -o $(NAME)_bonus

bonus/obj_bonus/%.o : src/%.c $(HEADER) Makefile
				cc -c -g3 -O3 ${FLAGS} $(FSAN) $(BONUS_FLAG) $< -o $@ -I $(MLX) -I.

obj/%.o : src/%.c $(HEADER) Makefile
		cc -c -g3 ${FLAGS} $(FSAN) $< -o $@ -I $(MLX) -I.

create_obj_folder :
	mkdir -p obj
	mkdir -p bonus
	mkdir -p bonus/obj_bonus

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	make clean -C $(MLX)
	@if [ -d "./obj" ]; then\
		rm -r obj;\
	fi
	make clean -C libft

fclean: clean
	make fclean -C libft
	make clean -C $(MLX)
	rm -f $(NAME)
	rm -f $(NAME)_bonus
	rm -f $(MLX_LIB)

re:
	make fclean
	make all

end_message:
	@echo "Done !"

bonus:
	make create_obj_folder
	make -C libft
	make -j1 -C $(MLX)
	cp $(MLX)/$(MLX_LIB) ./$(MLX_LIB)
	make $(NAME)_bonus
	@make end_message

.PHONY: all clean fclean re create_obj_folder end_message bonus
