#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import subprocess

on_rtd = os.environ.get('READTHEDOCS', None) == 'True'

if on_rtd:
    subprocess.call('cd ..; doxygen', shell=True)

import sys
import os
import sphinx_rtd_theme



if on_rtd:

    cmake_defs = "-DDOWNLOAD_DOCTEST=OFF -DBUILD_TEST=OFF  -DBUILD_EXAMPLES=OFF -DDOWNLOAD_GOOGLE_BENCHMARK=OFF -DBUILD_BENCHMARK=OFF"
    cmake_py_ver = "-DPYTHON_EXECUTABLE=%s"%(str(sys.executable),)
    subprocess.call('cd ../.. && cmake . %s %s && make -j2 && make install'%(cmake_defs, cmake_py_ver),          shell=True)

    import sys
    import os
    sys.path.append(os.path.join(os.path.dirname(__file__), '../../python'))


html_theme = "sphinx_rtd_theme"
#html_theme = "classic"
html_theme_path = [
    sphinx_rtd_theme.get_html_theme_path(),
    'mytheme',
    '.'
]


# html_theme_options = {
#   "codebgcolor": 'black'
# }


#html_static_path = ['_static']

extensions = ['breathe']
breathe_projects = { '{{cookiecutter.project_name}}': '../xml' }
templates_path = ['_template']
source_suffix = '.rst'
master_doc = 'index'
project = '{{cookiecutter.project_name}}'
copyright = ' {% now 'local', '%Y' %} , {{cookiecutter.full_name}}'
author = '{{cookiecutter.full_name}}'


exclude_patterns = []
highlight_language = 'c++'
pygments_style = 'sphinx'
todo_include_todos = False
htmlhelp_basename = '{{cookiecutter.project_name}}_doc'