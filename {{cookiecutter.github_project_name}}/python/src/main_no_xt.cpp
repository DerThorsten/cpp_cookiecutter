#include "pybind11/pybind11.h"
#include "pybind11/numpy.h"

#include <iostream>
#include <numeric>


// our headers
#include "{{cookiecutter.cpp_root_folder_name}}/{{ cookiecutter.package_name}}.hpp"

namespace py = pybind11;



namespace {{cookiecutter.cpp_namespace}} {


    


    void def_examples(py::module & module){

     
    }


    void def_class(py::module & m)
    {
        py::class_<MyClass>(m, "MyClass")
            .def(py::init<uint64_t>(),py::arg("size"))
            .def("hello_world", &MyClass::hello_world)
        ;
    }

}


// Python Module and Docstrings
PYBIND11_MODULE(_{{cookiecutter.python_package_name}} , module)
{


    module.doc() = R"pbdoc(
        _{{cookiecutter.python_package_name}}  python bindings

        .. currentmodule:: _{{cookiecutter.python_package_name}} 

        .. autosummary::
           :toctree: _generate
    )pbdoc";

    {{cookiecutter.cpp_namespace}}::def_examples(module);
    {{cookiecutter.cpp_namespace}}::def_class(module);

    module.attr("__version__") = "dev";
}