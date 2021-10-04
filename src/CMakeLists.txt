set(SRC_LIST
    main.cpp
)

add_executable(${PROJECT_NAME}-debug ${SRC_LIST})
target_compile_options(${PROJECT_NAME}-debug PUBLIC -Wall -Werror -Wpedantic -Wextra -g)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra -O3)
