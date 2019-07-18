.. role:: bash(code)
   :language: bash


Unit Tests
=================

We use doctest_ to create a benchmark for the C++ code.


The test subfolder contains all the code related 
to the C++ unit tests.
In :code:`main.cpp` implements the benchmarks runner,
The unit tets are implemented in :code:`test_*.cpp`.


For better readability we assume that the rendered project uses the default values
for the cookiecutter variables.
This means instead of :code:`{{cookiecutter.github_project_name}}`
 we will use :code:`cpptools`

::

    cpptools
    ├── ...
    ├── test
    │   ├── CMakeLists.txt
    │   ├── main.cpp         
    │   ├── test_cpptools_config.cpp
    └── ...




Build System
**********************

There is a meta target called :code:`test_cpptools` (assuming your cpptools is the package name) which bundles the
build process of unit tests.
Assuming you cmake-build directory is called :code:`bld` the following
will build all examples.

.. code-block:: shell

    $ cd bld
    $ make test_cpptools

To run the actual test you can use the target :code:`cpp_tests`

.. code-block:: shell

    $ cd bld
    $ make cpp_tests


Adding New Tests
**********************

To add new tests just add a new cpp file to the test
folder and update the :code:`CMakeLists.txt`.
Assuming we named the new cpp file :code:`test_my_new_feture.cpp`, 
the relevant part in the :code:`CMakeLists.txt` shall look like this:

.. code-block:: cmake

    # all tests
    set(${PROJECT_NAME}_TESTS
        test_cpptools_config.cpp
        test_my_new_feture.cpp
    )




After changing the :code:`CMakeLists.txt` cmake needs to be rerun
to configure the build again.
After that  :code:`make examples` will build all examples including the
freshly added examples.

.. code-block:: shell

    $ cd bld
    $ cmake .
    $ make examples


.. _doctest: https://github.com/google/benchmark
