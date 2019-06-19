#include "pybind11/pybind11.h"

#include "xtensor/xmath.hpp"
#include "xtensor/xarray.hpp"

#define FORCE_IMPORT_ARRAY
#include "xtensor-python/pyarray.hpp"
#include "xtensor-python/pyvectorize.hpp"

#include <iostream>
#include <numeric>


// our headers
#include "{{cookiecutter.cpp_root_folder_name}}/{{ cookiecutter.package_name}}.hpp"

namespace py = pybind11;



namespace {{cookiecutter.cpp_namespace}} {


    inline double example1(xt::pyarray<double> &m)
    {
        return m(0);
    }

    inline xt::pyarray<double> example2(xt::pyarray<double> &m)
    {
        return m + 2;
    }

    // Readme Examples

    inline double readme_example1(xt::pyarray<double> &m)
    {
        auto sines = xt::sin(m);
        return std::accumulate(sines.cbegin(), sines.cend(), 0.0);
    }

    // Vectorize Examples

    inline double scalar_func(double i, double j)
    {
        return std::sin(i) + std::cos(j);
    }



    void def_examples(py::module & module){

        // lambda to have pyarray as input
        module.def("example1", 
            [](xt::pyarray<double> &m){
                return example1(m);
            }, 
            "Return the first element of an array, of dimension at least one"
        );

        //lambda to have pyarray as in an output(!)
        module.def("example2", [](xt::pyarray<double> &m) -> xt::pyarray<double> {
            return example2(m);
        },  
        "Return the the specified array plus 2");

        // lambda to have pyarray as input
        module.def("readme_example1", [](xt::pyarray<double> &m) {
            return readme_example1(m);
        }, 
        "Accumulate the sines of all the values of the specified array");


        module.def("vectorize_example1", xt::pyvectorize(scalar_func), 
            "Add the sine and and cosine of the two specified values");
    }

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

           example1
           example2
           readme_example1
           vectorize_example1
    )pbdoc";

    {{cookiecutter.cpp_namespace}}::def_examples(module);
    {{cookiecutter.cpp_namespace}}::def_build_config(module);
    {{cookiecutter.cpp_namespace}}::def_class(module);

    module.attr("__version__") = "dev";
}