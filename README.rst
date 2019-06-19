=================================================
Cpp Cookiecutter
=================================================


.. image:: https://travis-ci.org/DerThorsten/cpp_cookiecutter.svg?branch=master
    :target: https://travis-ci.org/DerThorsten/cpp_cookiecutter

.. image:: https://circleci.com/gh/DerThorsten/cpp_cookiecutter/tree/master.svg?style=svg
    :target: https://circleci.com/gh/DerThorsten/cpp_cookiecutter/tree/master

.. image:: https://dev.azure.com/derthorstenbeier/cpp_cookiecutter/_apis/build/status/derthorsten.cpp_cookiecutter
    :target: (https://dev.azure.com/derthorstenbeier/cpp_cookiecutter_build/latest?definitionId=1



Features
--------

Current features include: 
    * modern C++ 14
    * build system with modernized yet not modern CMake  (this is a major todo)
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
    * conda recipes are not well integrated yet
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
