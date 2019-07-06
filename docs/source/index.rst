Introduction
------------

{{cookiecutter.description}}

`cookiecutter.project_name` provides:


- an API following the idioms of the **C++ standard library**.


{% if cookiecutter.open_source_license != 'Not open source' -%}
Licensing
---------
This software is licensed under the {{cookiecutter.open_source_license}} license. See the LICENSE.txt file for details.
{% endif %}


.. toctree::
   :caption: INSTALLATION
   :maxdepth: 2

   installation
   changelog

.. toctree::
   :caption: USAGE
   :maxdepth: 2

   basic_usage

.. toctree::
   :caption: API REFERENCE
   :maxdepth: 2
   
   api/{{cookiecutter.project_name}}.rst

.. toctree::
   :caption: DEVELOPER ZONE
   :maxdepth: 2

   compilers
   build-options
   developer/xtensor_internals
   external-structures
   releasing

.. toctree::
   :caption: MISCELLANEOUS

   related


.. _NumPy: http://www.numpy.org
.. _Buffer Protocol: https://docs.python.org/3/c-api/buffer.html
.. _libdynd: http://libdynd.org
.. _xtensor-python: https://github.com/QuantStack/xtensor-python
