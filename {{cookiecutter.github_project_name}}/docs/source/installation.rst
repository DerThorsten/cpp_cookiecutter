Installation
============

Although ``{{cookiecutter.project_name}}`` is a header-only library, we provide standardized means to install it, with package managers or with cmake.

Besides the {{cookiecutter.project_name}} headers, all these methods place the ``cmake`` project configuration file in the right location so that third-party projects can use cmake's ``find_package`` to locate {{cookiecutter.project_name}} headers.



.. code-block:: shell

    cd {{cookiecutter.github_project_name}}
    conda env create -f {{cookiecutter.project_name}}-dev-requirements.yml
    source activate {{cookiecutter.project_name}}-dev-requirements
    mkdir build
    cd build
    cmake ..
    make -j2
    make cpp-test
    make python-test
    make install
    cd examples
    ./hello_world
    cd ..
    cd benchmark
    ./benchmark_cpptools


On a windows machine this looks like:

.. code-block:: shell

    cd {{cookiecutter.github_project_name}}
    conda env create -f {{cookiecutter.project_name}}-dev-requirements.yml
    call activate {{cookiecutter.project_name}}-dev-requirements
    mkdir build
    cd build
    cmake .. -G"Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE=Release  ^
          -DDEPENDENCY_SEARCH_PREFIX="%CONDA_PREFIX%\Library" -DCMAKE_PREFIX_PATH="%CONDA_PREFIX%\Library"
    call activate cpptools-dev-requirements
    cmake --build . --target ALL_BUILD
    cmake --build . --target python-test
    cmake --build . --target cpp-test
    cmake --build . --target install


