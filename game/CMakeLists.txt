set(SRC_LIST
    main.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
