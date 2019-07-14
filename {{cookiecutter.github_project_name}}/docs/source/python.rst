

Python Module
=================

Folder Structure
**********************

We use pybind11_ to create the python bindings.
The python subfolder contains all the code related 
to the python bindings.
The module/{{cookiecutter.python_package_name}} subfolder contains all the *.py files of the module.
The src folder container the cpp files used to export the C++ functionality to python via pybind11_. 
The test folder contains all python tests.

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
TODO:
    * WHERE IS THE BUILD MODULE LOCATED
    * HOW TO INSTALL THE PYTHON MODULE

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
pybind11_ can create modules from C++ without the use of any *.py files.
Nevertheless we prefer to have a regular Python package with a proper `__init__.py`. From the `__init__.py` we import all the C++ / pybind11 exported functionality from the build submodule named `_{{cookiecutter.python_package_name}}`.
This allows us to add new functionality in different ways:
    * new functionality from c++ via pybind11
    * new puren python functionality
    * exteding the functionality from c++ via pybind11 from python

Add New Python Functionality from C++
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
TODO


Add New Pure Python Functionality
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
To add new pure Python functionality,
just add the desired function / classes to 
a new *.py file and put this file to the 
module/{{cookiecutter.python_package_name}} subfolder.
After adding the new file, cmake needs to be rerun since we copy the content module/{{cookiecutter.python_package_name}} during the build process.



Extending C++ functionality from Python
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
TODO



Adding New Python Tests
********************************************

We use pytest_ as python test framework.
To add new tests, just add new `test_*.py` files
to the test subfolder.
To run the actual test use the `python-test` target

.. code-block:: shell

    make python-test


.. _pybind11: https://github.com/pybind/pybind11
.. _pytest: https://docs.pytest.org/en/latest/