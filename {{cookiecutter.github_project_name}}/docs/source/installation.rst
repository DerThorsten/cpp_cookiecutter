.. raw:: html

   <style>
   .rst-content .section>img {
       width: 30px;
       margin-bottom: 0;
       margin-top: 0;
       margin-right: 15px;
       margin-left: 15px;
       float: left;
   }
   </style>

Installation
============

Although ``{{cookiecutter.project_name}}`` is a header-only library, we provide standardized means to install it, with package managers or with cmake.

Besides the {{cookiecutter.project_name}} headers, all these methods place the ``cmake`` project configuration file in the right location so that third-party projects can use cmake's ``find_package`` to locate {{cookiecutter.project_name}} headers.



From source with cmake
----------------------

You can also install ``{{cookiecutter.project_name}}`` from source with cmake. 
On Unix platforms, from the source directory:

.. code::

    mkdir build
    cd build
    cmake -DCMAKE_INSTALL_PREFIX=/path/to/prefix ..
    make install

On Windows platforms, from the source directory:

.. code::

    mkdir build
    cd build
    cmake -G "NMake Makefiles" -DCMAKE_INSTALL_PREFIX=/path/to/prefix ..
    nmake
    nmake install

See the section of the documentation on :doc:`build-options`, for more details on how to cmake options.


