Basic usage
===========


Install _cookiecutter via conda (recommended)

.. code-block:: shell

    $ conda install cookiecutter -c conda-forge

or

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

Install dev requirements
=========================

To install all dev requirements install the dependencies via the requirements yaml file

.. code-block:: shell

    $ conda env create -fg cpp_cookiecutter-dev-requiremnts.yml

This will create a fresh conda environments with all dependencies to use the cookiecutter and 
to build the documentation of this project