#-------------------------------------------------------------------------------------------------------------------
# Add The module
#-------------------------------------------------------------------------------------------------------------------
find_package(xtl               REQUIRED)
find_package(xtensor           REQUIRED)
find_package(xtensor-python    CONFIG  REQUIRED)


set(PY_MOD_NAME {{cookiecutter.python_package_name}} )
set(PY_MOD_LIB_NAME _${PY_MOD_NAME})

# add_library(${PY_MOD_LIB_NAME} MODULE main.cpp)
# # link pybind11
# target_link_libraries(${PY_MOD_LIB_NAME} 
#     pybind11::module xtensor xtl)


pybind11_add_module(${PY_MOD_LIB_NAME}  main.cpp)
# # link pybind11
target_link_libraries(${PY_MOD_LIB_NAME} PUBLIC  xtensor pybind11::module)

set(PY_INCLUDE_DIRS 
    ${PYTHON_NUMPY_INCLUDE_DIR}
    ${xtensor-python_INCLUDE_DIRS}
)


install(TARGETS ${PY_MOD_LIB_NAME} 
    DESTINATION ${PYTHON_MODULE_INSTALL_DIR}/${PY_MOD_NAME}/)