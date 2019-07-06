#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os

import sys
import os
import sphinx_rtd_theme




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

extensions = []

templates_path = ['_template']
source_suffix = '.rst'
master_doc = 'index'
project = 'cpp_cookiecutter'
copyright = '2019 , Thorsten Beier'
author = 'Thorsten Beier'


exclude_patterns = []
highlight_language = 'python'
pygments_style = 'sphinx'
todo_include_todos = False
htmlhelp_basename = 'cpp_cookiecutter_doc'