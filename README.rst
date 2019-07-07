=================================================
Cpp Cookiecutter
=================================================


.. image:: https://readthedocs.org/projects/cpp-cookiecutter/badge/?version=latest
    :target: https://cpp-cookiecutter.readthedocs.io/en/latest/?badge=latest
    :alt: Documentation Status
      

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
    * Modern C++ 14
    * Build system with modernized yet not modern CMake  (this is a major todo)
    * `preconfigured conda recipe included <https://cpp-cookiecutter.readthedocs.io/en/latest/conda_recipe.html>`_
    * Rendered projects have pre-configured CI scripts for: travis-ci circleci and azure-pipelines
    * Rendering of projects itself is tested on several continuous integration plattforms as `travis-ci <https://travis-ci.org/DerThorsten/cpp_cookiecutter>`_ `circleci <https://circleci.com/gh/DerThorsten/cpp_cookiecutter/tree/master>`_ and `azure-pipelines <https://dev.azure.com/derthorstenbeier/cpp_cookiecutter/_build/latest?definitionId=1&branchName=master>`_
    * `C++ unit tests with cpp doctest <https://cpp-cookiecutter.readthedocs.io/en/latest/unit_tests.html>`_
    * `Benchmark code with google benchmark <https://cpp-cookiecutter.readthedocs.io/en/latest/benchmark.html>`_
    * Docs with sphinx breathe and readthedocs support
    * `Google Benchmark <https://cpp-cookiecutter.readthedocs.io/en/latest/benchmark.html>`_and `Doctest <https://cpp-cookiecutter.readthedocs.io/en/latest/unit_tests.html>`_ are downloaded at cmake-config time via external-projects 
      since these dependencies are just for testing and benchmarking (and those are not yet available on conda)
    * bumpversion
    * `Python bindings are created via pybind11`<https://cpp-cookiecutter.readthedocs.io/en/latest/python.html>_
   

.. _rtd_unit_test:





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
    conda env create -f cpptools-dev-requirements.yml
    source activate cpptools-dev-requirements
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
    ./benchmark_cpptools


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





Conda Recipe:
--------

The generated projects contain a conda recipe which can be used to build conda packages.
    
.. code-block:: shell

    cd cpptools
    conda install conda-build
    conda build recipe

.. _cookiecutter: https://github.com/audreyr/cookiecutter
    
