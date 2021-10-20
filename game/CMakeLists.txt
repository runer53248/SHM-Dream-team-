set(SRC_LIST
    main.cpp
    Game.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})

target_link_libraries(${PROJECT_NAME} PRIVATE json-lib)
