#include "pybind11/pybind11.h"

#include "xtensor/xmath.hpp"
#include "xtensor/xarray.hpp"

#define FORCE_IMPORT_ARRAY
#include "xtensor-python/pyarray.hpp"
#include "xtensor-python/pyvectorize.hpp"

#include <iostream>
#include <numeric>
#include <string>
#include <sstream>


// our headers
#include "{{cookiecutter.cpp_root_folder_name}}/{{ cookiecutter.package_name}}.hpp"
#include "{{cookiecutter.cpp_root_folder_name}}/{{ cookiecutter.package_name}}_config.hpp"

namespace py = pybind11;



namespace {{cookiecutter.cpp_namespace}} {


    // implementation in def_myclass.cpp
    void def_class(py::module & m);

    // implementation in def_myclass.cpp
    void def_build_config(py::module & m);

    // implementation in def.cpp
    void def_build_config(py::module & m);

}


// Python Module and Docstrings
PYBIND11_MODULE(_{{cookiecutter.python_package_name}} , module)
{
    xt::import_numpy();

    module.doc() = R"pbdoc(
        _{{cookiecutter.python_package_name}}  python bindings

        .. currentmodule:: _{{cookiecutter.python_package_name}} 

        .. autosummary::
           :toctree: _generate

           BuildConfiguration
           MyClass
    )pbdoc";

    {{cookiecutter.cpp_namespace}}::def_build_config(module);
    {{cookiecutter.cpp_namespace}}::def_class(module);

    // make version string
    std::stringstream ss;
    ss<<{{cookiecutter.cpp_macro_prefix}}_VERSION_MAJOR<<"."
      <<{{cookiecutter.cpp_macro_prefix}}_VERSION_MINOR<<"."
      <<{{cookiecutter.cpp_macro_prefix}}_VERSION_PATCH;
    module.attr("__version__") = ss.str().c_str();
}