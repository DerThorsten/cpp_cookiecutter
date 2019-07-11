Introduction
------------

{{cookiecutter.description}}


{% if cookiecutter.open_source_license != 'Not open source' -%}
Licensing
---------
This software is licensed under the {{cookiecutter.open_source_license}} license. See the LICENSE.txt file for details.
{% endif %}



.. toctree::
   :caption: Basics
   :maxdepth: 2

   features
   basic_usage

.. toctree::
   :caption: Folder Structure
   :maxdepth: 2

   folder_structure

.. toctree::
   :caption: Components
   :maxdepth: 2

   unit_tests
   benchmark
   python
   examples
   conda_recipe

.. toctree::
   :caption: Examples
   :maxdepth: 2

   examples.rst

.. toctree::
   :caption: Api Reference
   :maxdepth: 2
   
   api/{{cookiecutter.project_name}}.rst



.. _NumPy: http://www.numpy.org
.. _Buffer Protocol: https://docs.python.org/3/c-api/buffer.html
.. _libdynd: http://libdynd.org
.. _xtensor-python: https://github.com/QuantStack/xtensor-python
