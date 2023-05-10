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

HEADERS =	include/philo.h \
         	include/common_tools.h \
         	include/philo_tools.h \
         	include/philo_time.h \

SRC =	main.c \
       	check_args.c \
       	set_params_from_args.c \
       	create_all_philosophers.c \
       	init_all_philosophers.c \
       	common_tools/error_msg.c \
       	common_tools/ft_atoll.c \
       	start_all_philosophers_threads.c \
       	common_tools/philo_time.c \
       	common_tools/print_state_change.c \
       	common_tools/all_philos_are_alive.c \
       	philosophers_tools/philosopher_eats.c \
       	philosophers_tools/philosopher_sleeps.c \
       	monitor/monitor_thread.c \
       	philosophers/philosopher_thread.c \

BONUS_FLAG = #-DBONUS_FLAG
FLAGS = -Wall -Wextra -Werror
FSAN = -fsanitize=thread
OBJ = $(addprefix obj/,$(SRC:.c=.o))
OBJ_BONUS = $(addprefix bonus/,$(SRC:.c=.o))
INCLUDE_LIBFT = #-I libft
LINK_LIBFT = #-L ./libft -lft
LIBFT = #libft/libft.a
INCLUDE_HEADERS = -I include




all	: create_obj_folder
	#make -C libft
	make $(NAME)
	@make end_message

obj/%.o : src/%.c $(HEADERS) Makefile
	cc -c -g3 ${FLAGS} $(FSAN) $(INCLUDE_LIBFT) $(INCLUDE_HEADERS) $< -o $@

bonus/%.o : src/%.c $(HEADERS) Makefile
	cc -c -g3 -O3 ${FLAGS} $(FSAN) $(BONUS_FLAG) $(INCLUDE_LIBFT) $(INCLUDE_HEADERS) $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	cc $(OBJ) $(FSAN) -g3  $(LINK_LIBFT) -o $(NAME)

$(NAME)_bonus: libft/libft.a $(OBJ_BONUS)
	cc $(OBJ_BONUS) $(FSAN) -g3 $(LINK_LIBFT) -o $(NAME)_bonus

create_obj_folder :
	@mkdir -p obj/common_tools obj/monitor obj/philosophers obj/philosophers_tools
	@mkdir -p bonus

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	@if [ -d "./obj" ]; then\
		rm -r obj;\
	fi
	#make clean -C libft

fclean: clean
	#make fclean -C libft
	rm -f $(NAME)
	rm -f $(NAME)_bonus

re:
	make fclean
	make all

end_message:
	@echo "Done !"

bonus:
	@make create_obj_folder
	#make -C libft
	make $(NAME)_bonus
	@make end_message

.PHONY: all clean fclean re create_obj_folder end_message bonus
