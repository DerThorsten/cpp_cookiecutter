

# all examples
set(CPP_EXAMPLE_FILES
   hello_world.cpp
)



# custom target for `make examples`
add_custom_target(examples)

foreach(CPP_EXAMPLE_FILE ${CPP_EXAMPLE_FILES})

    # get the filename without extension
    get_filename_component(EXAMPLE_TARGET_NAME_WITH_EXT ${CPP_EXAMPLE_FILE} NAME)
    string(REGEX MATCH "^(.*)\\.[^.]*$" dummy ${EXAMPLE_TARGET_NAME_WITH_EXT})
    set(EXAMPLE_TARGET_NAME ${CMAKE_MATCH_1})


    add_executable( ${EXAMPLE_TARGET_NAME}
        ${CPP_EXAMPLE_FILE}
    )

    # target_include_directories(  ${EXAMPLE_TARGET_NAME} PRIVATE 
    #     "$<BUILD_INTERFACE:${PROJECT_INCLUDE_DIR}>"
    # )

    target_link_libraries( ${EXAMPLE_TARGET_NAME}
        PRIVATE ${INTERFACE_LIB_NAME}
    )

    # add example to custom target for `make examples`
    add_dependencies(examples ${EXAMPLE_TARGET_NAME})

endforeach(CPP_EXAMPLE_FILE)

