=================================================
Cpp Cookiecutter
=================================================

.. image:: https://img.shields.io/travis/DerThorsten/cpp_cookiecutter.svg
        :target: https://travis-ci.org/DerThorsten/cpp_cookiecutter


Features
--------

Current features include: 
    * modern C++ 14
    * build system with modern CMake 
    * conda recipe included
    * travis included
    * unit tests with cpp doctest
    * benchmark code with google benchmark
    * docs with sphinx breathe and readthedocs support
    * google benchmark and cpp doctest are downloaded at cmake-config time via external-projects 
      since these dependencies are just for testing and benchmarking



Todos:
--------

Things which need to be done
    * conda recipes are not net in the cookiecutter
    * Add documentation how to use the cookiecutter




Usage:
--------

Install _cookiecutter 

.. code-block:: shell

    $ pip install cookiecutter


After installing cookiecutter, use the cpp-cookiecutter:

.. code-block:: shell

    $ cookiecutter https://github.com/DerThorsten/cpp_cookiecutter



.. _cookiecutter: https://github.com/audreyr/cookiecutter