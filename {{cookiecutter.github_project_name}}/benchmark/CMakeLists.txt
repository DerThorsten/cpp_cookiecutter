if(DOWNLOAD_GOOGLE_BENCHMARK OR GOOGLE_BENCHMARK_SRC_DIR)



    configure_file(downloadGBenchmark.cmake.in googlebenchmark-download/CMakeLists.txt)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                    RESULT_VARIABLE result
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googlebenchmark-download )
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
                    RESULT_VARIABLE result
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googlebenchmark-download )

    # Add googlebenchmark directly to our build. This defines
    # the gtest and gtest_main targets.
    add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googlebenchmark-src
                     ${CMAKE_CURRENT_BINARY_DIR}/googlebenchmark-build)


    set(GBENCHMARK_INCLUDE_DIRS "${googlebenchmark_SOURCE_DIR}/include")
    set(GBENCHMARK_LIBRARIES benchmark)


else()
    find_package(GOOGLE_BENCHMARK REQUIRED)
endif()


file(GLOB_RECURSE ${PROJECT_NAME}_BENCHMARKS 
     RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
list(REMOVE_ITEM ${PROJECT_NAME}_BENCHMARKS main.cpp)
set(${PROJECT_NAME}_BENCHMARK_TARGET benchmark_${PROJECT_NAME})


# all benchmarks
set(${PROJECT_NAME}_BENCHMARKS 
    benchmark_{{cookiecutter.cmake_project_name}}.cpp
)



add_executable( ${${PROJECT_NAME}_BENCHMARK_TARGET}
    main.cpp
    ${${PROJECT_NAME}_BENCHMARKS}
)

SET(BENCHMARK_INCLUDE_DIRS ${GBENCHMARK_INCLUDE_DIRS} ${VIGRA_INCLUDE_DIRS} ${GRAPH_INCLUDE_DIRS})
target_include_directories(  ${${PROJECT_NAME}_BENCHMARK_TARGET} PRIVATE 
    "$<BUILD_INTERFACE:${PROJECT_INCLUDE_DIR};${BENCHMARK_INCLUDE_DIRS}>"
)


target_link_libraries( ${${PROJECT_NAME}_BENCHMARK_TARGET}
                      ${GBENCHMARK_LIBRARIES}
)

if (NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang" )
    # if flags ffast-math is defined, __extern_always_inline
    # gives errors on clang
    target_compile_options(${${PROJECT_NAME}_BENCHMARK_TARGET}
        PRIVATE  -ffast-math -Ofast -march=native  -pthread)
endif()