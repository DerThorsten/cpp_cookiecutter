#include "pybind11/pybind11.h"
#include "pybind11/numpy.h"

#include <iostream>
#include <numeric>


// our headers
#include "{{cookiecutter.cpp_root_folder_name}}/{{ cookiecutter.package_name}}.hpp"
#include "{{cookiecutter.cpp_root_folder_name}}/{{ cookiecutter.package_name}}_config.hpp"


namespace py = pybind11;



namespace {{cookiecutter.cpp_namespace}} {

    void def_build_config(py::module & m)
    {

        struct Configuration        {
            
        };


        py::class_<Configuration>(m, "Configuration",
        "This class show the compile Configuration\n"
        "Of {{cookiecutter.python_package_name}}\n"
        )
        .def_property_readonly_static("VERSION_MAJOR", [](py::object /* self */) {
           return {{cookiecutter.cpp_macro_prefix}}_VERSION_MAJOR ;
        })
        .def_property_readonly_static("VERSION_MINOR", [](py::object /* self */) {
           return {{cookiecutter.cpp_macro_prefix}}_VERSION_MINOR ;
        })
        .def_property_readonly_static("VERSION_PATCH", [](py::object /* self */) {
           return {{cookiecutter.cpp_macro_prefix}}_VERSION_MAJOR ;
        })
        .def_property_readonly_static("DEBUG", [](py::object /* self */) {
            #ifdef  NDEBUG
            return false;
            #else
            return true;
            #endif
        })

;



    }

}
