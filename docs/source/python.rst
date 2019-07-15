

Python Module
=================

Here we document how to use and extend the python bindings for a project created with this cookiecutter.
See `cpptools.readthedocs.io/en/latest/python.html https://cpptools.readthedocs.io/en/latest/python.html>`_
for the python documentation of a sample project created with this cookiecutter.

Folder Structure
**********************

We use pybind11_ to create the python bindings.
The python subfolder contains all the code related 
to the python bindings.
The :code:`module/{{cookiecutter.python_package_name}}` subfolder contains all the :code:`*.py` files of the module.
The src folder contains the :code:`*.cpp` files used to export the C++ functionality to python via pybind11_. 
The :code:`test` folder contains all python tests.

::

    {{cookiecutter.github_project_name}}
    ├── ...
    ├── python          
    │   ├── module
    │   │   └── {{cookiecutter.python_package_name}}
    │   │       ├── __init__.py
    │   │       └── ...
    │   ├── src
    │   │   ├── CMakeLists.txt
    │   │   ├── main.cpp
    │   │   ├── def_build_config.cpp
    │   │   ├── ...
    │   └── test
    │       ├── test_build_configuration.py
    │       └── ...
    └── ...





Build System
**********************

To build the python package use the :code:`python-module` target.

.. code-block:: shell

    make python-module

This will build the :code:`*.cpp` files in the :code:`src` folder and copy the folder :code:`module/{{cookiecutter.python_package_name}}` folder to build location of the python module, namely :code:`${CMAKE_BINARY_DIR}/python/module/` where :code:`${CMAKE_BINARY_DIR}` is the  build directory.


Usage
**********************

After a successfully building and installing the python module can be
imported like the following:

.. code-block:: python

    import {{cookiecutter.python_package_name}}

    config = {{cookiecutter.python_package_name}}.BuildConfiguration
    print(config.VERSION_MAJOR)



Run Python Tests
********************************************

To run the python test suite use the `python-test` target:

.. code-block:: shell

    make python-test



Adding New Python Functionality
********************************************

We use pybind11_ to export functionality from C++ to Python.
pybind11_ can create modules from C++ without the use of any :code:`*.py` files.
Nevertheless we prefer to have a regular Python package with a proper :code:`__init__.py`. From the :code:`__init__.py` we import all the C++ / pybind11_ exported functionality from the build submodule named :code:`_{{cookiecutter.python_package_name}}`.
This allows us to add new functionality in different ways:
    * new functionality from c++ via pybind11_
    * new puren python functionality

Add New Python Functionality from C++
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
To export functionality from C++ to python via pybind11_ it is 
good practice to split functionality in multiple  :code:`def_*.cpp` files.
This allow for readable code, and parallel builds.
To add news functionality we create a new file, for example :code:`def_new_stuff.cpp`.


.. code-block:: cpp

    #include "pybind11/pybind11.h"
    #include "pybind11/numpy.h"

    #include <iostream>
    #include <numeric>

    #define FORCE_IMPORT_ARRAY
    #include "xtensor-python/pyarray.hpp"
    #include "xtensor-python/pytensor.hpp"

    // our headers
    #include "{{cookiecutter.cpp_root_folder_name}}/{{ cookiecutter.package_name}}.hpp"

    namespace py = pybind11;


    namespace {{cookiecutter.cpp_namespace}} {

        void def_new_stuff(py::module & m)
        {
            py::def('new_stuff',[](xt::pytensor<1,double> values){
                return values * 42.0;
            });
        }

    }

Next we need to declare and call the :code:`def_new_stuff` from :code:`main.cpp`.
To declare the function modify the following block in :code:`main.cpp`

.. code-block:: cpp

    namespace {{cookiecutter.cpp_namespace}} {

        // ....
        // ....
        // ....

        // implementation in def_myclass.cpp
        void def_class(py::module & m);

        // implementation in def_myclass.cpp
        void def_build_config(py::module & m);

        // implementation in def.cpp
        void def_build_config(py::module & m);

        // implementation in def.cpp
        void def_build_config(py::module & m);

        // implementation in def_new_stuff.cpp     
        void def_new_stuff(py::module & m);             // <- our new functionality

    }

After declaring the function  :code:`def_new_stuff`, we can call  :code:`def_new_stuff`. We modify the :code:`PYBIND11_MODULE` in
code:`main.cpp`:


.. code-block:: cpp

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
               new_stuff
        )pbdoc";

        {{cookiecutter.cpp_namespace}}::def_build_config(module);
        {{cookiecutter.cpp_namespace}}::def_class(module);
        {{cookiecutter.cpp_namespace}}::def_new_stuff(module);  // <- our new functionality

        // make version string
        std::stringstream ss;
        ss<<{{cookiecutter.cpp_macro_prefix}}_VERSION_MAJOR<<"."
          <<{{cookiecutter.cpp_macro_prefix}}_VERSION_MINOR<<"."
          <<{{cookiecutter.cpp_macro_prefix}}_VERSION_PATCH;
        module.attr("__version__") = ss.str();
    }


We need to add this file to the :code:`CMakeLists.txt` file at 
:code:`{cookiecutter.github_project_name}}/python/src/CMakeLists.txt`
The file needs to be passed as an argument to the :code:`pybind11_add_module` function.

.. code-block:: cmake
        
    # add the python library
    pybind11_add_module(${PY_MOD_LIB_NAME}  
        main.cpp
        def_build_config.cpp
        def_myclass.cpp
        def_new_stuff.cpp  # <- our new functionality
    )



Now we are ready to build the freshly added functionality.

.. code-block:: shell

    make python-test


After a successful build we can use the new functionality from python.


.. code-block:: python

    import numpy as np
    import {{cookiecutter.python_package_name}}

    {{cookiecutter.python_package_name}}.new_stuff(numpy.arange(5), dtype='float64')



Add New Pure Python Functionality
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
To add new pure Python functionality,
just add the desired function / classes to 
a new :code:`*.py` file and put this file to the 
:code:`module/{{cookiecutter.python_package_name}}` subfolder.
After adding the new file, cmake needs to be rerun since we copy the content :code:`module/{{cookiecutter.python_package_name}}` during the build process.




Adding New Python Tests
********************************************

We use pytest_ as python test framework.
To add new tests, just add new :code:`test_*.py` files
to the test subfolder.
To run the actual test use the :code:`python-test` target

.. code-block:: shell

    make python-test


.. _pybind11: https://github.com/pybind/pybind11
.. _pytest: https://docs.pytest.org/en/latest/