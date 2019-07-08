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



.. list-table:: Title
   :widths: 25 25 50
   :header-rows: 1

   * - Cookiecutter variable
     - Description
     - Default
   * - full_name
     - Author Name
     - John Doe
   * - email                        
     - email of author
     - john@doe.de
   * - project_name                 
     - name of the project
     - cpptools
   * - project_slug                 
     - url friendly version of package name
     - cpptools
   * - package_name                 
     - package name
     - cpptools
   * - conda_package_name           
     - conda package name
     - cpptools
   * - readthedocs_package_name     
     - readthedocs package name
     - cpptools
   * - cpp_namespace                
     - name of C++ namespace
     - cpptools
   * - cpp_root_folder_name         
     - name of the root C++ folder 
     - cpptools
   * - cpp_macro_prefix             
     - prefix for all macros in C++
     - CPPTOOLS
   * - cpp_standart                 
     - which C++ standard should be used
     - 14
   * - cmake_project_name           
     - name of the project within cmake
     - cpptools
   * - cmake_interface_library_name 
     - name of the cmake interface library
     - cpptools
   * - github_project_name          
     - name of the project on github
     - cpptools
   * - python_bindings              
     - should python bindings be included
     - Yes
   * - python_package_name          
     - name of the python package
     - cpptools
   * - github_user_name             
     - authors github user name
     - JohnDoe
   * - azure_user_name              
     - authors user name on microsoft azure
     - JohnDoe
   * - open_source_license          
     - which license shall be used
     - MIT LICENCE
   * - summary                      
     - a short summary of the project
     - cpptools is a modern C++ Library
   * - description                  
     - a short description of the project
     - cpptools is a modern C++ Library   



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

    $ conda env create -f cpp_cookiecutter-dev-requiremnts.yml

This will create a fresh conda environments with all dependencies to use the cookiecutter and 
to build the documentation of this project.