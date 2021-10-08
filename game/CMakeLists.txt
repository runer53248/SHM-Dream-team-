set(SRC_LIST
    main.cpp
)

add_executable(${PROJECT_NAME}-debug ${SRC_LIST})
target_compile_options(${PROJECT_NAME}-debug PRIVATE ${COMPILER_DEBUG_FLAGS})

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILER_RELEASE_FLAGS})
