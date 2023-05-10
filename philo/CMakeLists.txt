cmake_minimum_required(VERSION 3.21)
project(philo)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -fsanitize=thread")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(
        philo
        include/philo.h
        include/common_tools.h
        include/philo_tools.h
        include/philo_time.h
        src/main.c
        src/check_args.c
        src/set_params_from_args.c
        src/create_all_philosophers.c
        src/init_all_philosophers.c
        src/common_tools/error_msg.c
        src/common_tools/ft_atoll.c
        src/start_all_philosophers_threads.c
        src/common_tools/philo_time.c
        src/common_tools/print_state_change.c
        src/common_tools/all_philos_are_alive.c
        src/philosophers_tools/philosopher_eats.c
        src/philosophers_tools/philosopher_sleeps.c
        src/monitor/monitor_thread.c
        src/philosophers/philosopher_thread.c
)

#target_link_libraries(minishell~/minishell/libft/libft.a)
#target_link_libraries(minishell readline)