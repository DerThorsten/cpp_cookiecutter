=================================================
Cpp Cookiecutter
=================================================


.. image:: https://travis-ci.org/DerThorsten/cpp_cookiecutter.svg?branch=master
    :target: https://travis-ci.org/DerThorsten/cpp_cookiecutter

.. image:: https://circleci.com/gh/DerThorsten/cpp_cookiecutter/tree/master.svg?style=svg
    :target: https://circleci.com/gh/DerThorsten/cpp_cookiecutter/tree/master

.. image:: https://dev.azure.com/derthorstenbeier/cpp_cookiecutter/_apis/build/status/DerThorsten.cpp_cookiecutter?branchName=master&jobName=Linux
    :target: https://dev.azure.com/derthorstenbeier/cpp_cookiecutter/_build/latest?definitionId=1&branchName=master

.. image:: https://dev.azure.com/derthorstenbeier/cpp_cookiecutter/_apis/build/status/DerThorsten.cpp_cookiecutter?branchName=master&jobName=macOS
    :target: https://dev.azure.com/derthorstenbeier/cpp_cookiecutter/_build/latest?definitionId=1&branchName=master

.. image:: https://dev.azure.com/derthorstenbeier/cpp_cookiecutter/_apis/build/status/DerThorsten.cpp_cookiecutter?branchName=master&jobName=Windows
    :target: https://dev.azure.com/derthorstenbeier/cpp_cookiecutter/_build/latest?definitionId=1&branchName=master







Features
--------

Current features include: 

    * modern C++ 14
    * build system with modernized yet not modern CMake  (this is a major todo)
    *  preconfigured conda conda recipe included 
    * generated projects have pre-configured CI scripts for: travis-ci circleci and azure-pipelines
    * generating of projects itself is tested on several continuous integration plattforms as travis-ci circleci and azure-pipelines
    * cpp unit tests with cpp doctest
    * benchmark code with google benchmark
    * docs with sphinx breathe and readthedocs support
    * google benchmark and cpp doctest are downloaded at cmake-config time via external-projects 
      since these dependencies are just for testing and benchmarking
    * bumpversion
    * python bindings are created via pybind11
   



Todos:
--------

Things which need to be done
    * Add better documentation how to use the cookiecutter




Usage:
--------

Install _cookiecutter 

.. code-block:: shell

    $ pip install cookiecutter


After installing cookiecutter, use the cpp-cookiecutter:

.. code-block:: shell

    $ cookiecutter https://github.com/DerThorsten/cpp_cookiecutter


This cookiecutter is bet used in conjunction with conda:
Assuming your package is named cpptools the following script
shows the usage of the generated project cookiecutter on Linux/MacOS

.. code-block:: shell

    cd cpptools
    conda env create -f cpptools-dev-requirements.yml || exit 1
    source activate cpptools-dev-requirements || exit 1
    mkdir build
    cd build
    cmake ..
    make -j2
    make cpp-test
    make python-test
    cd examples
    ./hello_world
    cd ..
    cd benchmark
    ./benchmark_{{cookiecutter.cmake_project_name}}


On a windows machine this looks like:

.. code-block:: shell

    cd cpptools
    call activate cpptools-dev-requirements
    mkdir build
    cd build
    cmake .. -G"Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE=Release  ^
          -DDEPENDENCY_SEARCH_PREFIX="%CONDA_PREFIX%\Library" -DCMAKE_PREFIX_PATH="%CONDA_PREFIX%\Library"
    call activate cpptools-dev-requirements
    cmake --build . --target ALL_BUILD
    cmake --build . --target python-test
    cmake --build . --target cpp-test




.. _cookiecutter: https://github.com/audreyr/cookiecutter

