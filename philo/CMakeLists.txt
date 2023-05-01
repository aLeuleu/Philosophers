cmake_minimum_required(VERSION 3.21)
project(philo)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -fsanitize=address")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(
        philo
        include/check_args.h
        include/common_tools.h
        src/main.c
        src/check_args.c
        src/set_global_params_from_args.c
        src/create_all_philosophers.c
        src/init_all_philosophers.c
        src/common_tools/error_msg.c
        src/common_tools/ft_atoll.c
        )

#target_link_libraries(minishell ~/minishell/libft/libft.a)
#target_link_libraries(minishell readline)