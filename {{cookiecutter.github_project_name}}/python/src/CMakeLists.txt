#-------------------------------------------------------------------------------------------------------------------
# Add The module
#-------------------------------------------------------------------------------------------------------------------
{% if cookiecutter.use_xtensor == 'yes' -%}
find_package(xtl               REQUIRED)
find_package(xtensor           REQUIRED)
find_package(xtensor-python    CONFIG  REQUIRED)
{% endif %}


set(PY_MOD_NAME {{cookiecutter.python_package_name}} )
set(PY_MOD_LIB_NAME _${PY_MOD_NAME})


# add the python library
pybind11_add_module(${PY_MOD_LIB_NAME}  
    main.cpp
    def_build_config.cpp
    def_myclass.cpp
)

# `link` against pybind11 interface module
target_link_libraries(${PY_MOD_LIB_NAME} PUBLIC  
    ${INTERFACE_LIB_NAME}
    pybind11::module)

# include directories for non-modern cmake
set(PY_INCLUDE_DIRS 
    ${PYTHON_NUMPY_INCLUDE_DIR}
    ${xtensor-python_INCLUDE_DIRS}
)
target_include_directories(${PY_MOD_LIB_NAME} PUBLIC  ${PY_INCLUDE_DIRS})



add_custom_command(TARGET ${PY_MOD_LIB_NAME} POST_BUILD 
  COMMAND "${CMAKE_COMMAND}" -E copy 
     "$<TARGET_FILE:${PY_MOD_LIB_NAME}>"
     "${CMAKE_BINARY_DIR}/python/module/${PY_MOD_NAME}/$<TARGET_FILE_NAME:${PY_MOD_LIB_NAME}>" 
  COMMENT "Copying to output directory")




add_custom_target(python-test COMMAND ${PYTHON_EXECUTABLE}  -m pytest ../../../python/  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/python/module" )
add_dependencies(python-test ${PY_MOD_LIB_NAME} )

add_dependencies(test python-test)

install(TARGETS ${PY_MOD_LIB_NAME} 
    DESTINATION ${PYTHON_MODULE_INSTALL_DIR}/${PY_MOD_NAME}/)