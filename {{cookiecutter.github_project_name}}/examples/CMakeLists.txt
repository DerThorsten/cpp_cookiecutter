
file(GLOB_RECURSE CPP_EXAMPLE_FILES
     RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)


# custom target for `make examples`
add_custom_target(examples)

foreach(CPP_EXAMPLE_FILE ${CPP_EXAMPLE_FILES})
    get_filename_component(EXAMPLE_TARGET_NAME ${CPP_EXAMPLE_FILE} NAME)
    add_executable( ${EXAMPLE_TARGET_NAME}
        ${CPP_EXAMPLE_FILE}
    )

    target_include_directories(  ${EXAMPLE_TARGET_NAME} PRIVATE 
        "$<BUILD_INTERFACE:${PROJECT_INCLUDE_DIR}>"
    )

    # add example to custom target for `make examples`
    add_dependencies(examples ${EXAMPLE_TARGET_NAME})

endforeach(CPP_EXAMPLE_FILE)

