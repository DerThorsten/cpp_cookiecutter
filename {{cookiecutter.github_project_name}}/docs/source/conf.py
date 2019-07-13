 #!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import subprocess

on_rtd = os.environ.get('READTHEDOCS') is not None
on_travis = os.environ.get('TRAVIS') is not None
on_ci = on_rtd or on_travis

# if on_ci:
#     subprocess.call('cd ..; doxygen', shell=True)

import sys
import os
import shutil
import fnmatch


import sphinx_rtd_theme


def erase_folder_content(folder):
    for file_object in os.listdir(folder):
        file_object_path = os.path.join(folder, file_object)
        if os.path.isfile(file_object_path):
            os.unlink(file_object_path)
        else:
            shutil.rmtree(file_object_path) 

def patch_apidoc(folder):
    for root, dirnames, filenames in os.walk(folder):
        for filename in fnmatch.filter(filenames, '*.rst'):
            fname = os.path.join(root, filename)

            # Read in the file
            with open(fname, 'r') as file :
              filedata = file.read()

            # Replace the target string
            filedata = filedata.replace('   :members:', '   :members:\n   :imported-members:')

            # Write the file out again
            with open(fname, 'w') as file:
              file.write(filedata)

# build everything
package_name = "{{cookiecutter.python_package_name}}"
this_dir = os.path.dirname(__file__)
py_mod_path  = os.path.join(this_dir, '../../python/module')

if on_ci:

    cmake_defs = "-DDOWNLOAD_DOCTEST=OFF -DBUILD_PYTHON=ON  -DBUILD_TEST=OFF  -DBUILD_EXAMPLES=OFF -DDOWNLOAD_GOOGLE_BENCHMARK=OFF -DBUILD_BENCHMARK=OFF"
    cmake_py_ver = "-DPYTHON_EXECUTABLE=%s"%(str(sys.executable),)
    subprocess.call('cd ../.. && cmake . %s %s && make -j2'%(cmake_defs, cmake_py_ver),          shell=True)

    # append python path to contain module from build dir
    import sys
    import os
    this_dir = os.path.dirname(__file__)
    py_mod_path  = os.path.join(this_dir, '../../python/module')
    package_dir = os.path.join(py_mod_path, package_name)
    sys.path.append(py_mod_path)


    # apidoc
    # todo, erase old apidoc result

    apidoc_out_folder =  os.path.join(this_dir, 'pyapi')
    template_dir =  os.path.join(this_dir, '_template')
    erase_folder_content(apidoc_out_folder)
    arglist = ['sphinx-apidoc','-o',apidoc_out_folder,package_dir,'-P']
    print(arglist)
    subprocess.call(arglist, shell=False)


    # patch apidoc (the conda version does not support -t / --templatedir opt)
    patch_apidoc(apidoc_out_folder)




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
extensions = ['breathe','exhale','sphinx.ext.todo', 'sphinx.ext.viewcode', 'sphinx.ext.autodoc','sphinx.ext.napoleon']
breathe_projects = { '{{cookiecutter.project_name}}': '../xml/' }



exhale_args = {
    # These arguments are required
    "containmentFolder":     "./api",
    "rootFileName":          "{{cookiecutter.project_name}}_api.rst",
    "rootFileTitle":         "{{cookiecutter.project_name}} API",
    "doxygenStripFromPath":  "..",
    # Suggested optional arguments
    "createTreeView":        True,
    # TIP: if using the sphinx-bootstrap-theme, you need
    # "treeViewIsBootstrap": True,
    "exhaleExecutesDoxygen": True,
    "exhaleDoxygenStdin":    "INPUT = ../../include"
}

# Tell sphinx what the primary language being documented is.
primary_domain = 'cpp'

# Tell sphinx what the pygments highlight language should be.
highlight_language = 'cpp'


breathe_default_project = '{{cookiecutter.project_name}}'

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