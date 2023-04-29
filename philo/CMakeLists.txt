cmake_minimum_required(VERSION 3.21)
project(philo)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -fsanitize=address")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(philo src/main.c src/check_args/check_args.c src/check_args/ft_atoll.c)

#target_link_libraries(minishell ~/minishell/libft/libft.a)
#target_link_libraries(minishell readline)