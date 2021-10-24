set(SRC_LIST
    main.cpp
<<<<<<< HEAD
    Game.cpp
=======
    Island.cpp
>>>>>>> 4e911c8ee3ff9975263a5867257802cf0c91fbae
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})

target_link_libraries(${PROJECT_NAME} PRIVATE json-lib)
