#!/usr/bin/env python
import os
import os.path
import shutil

PROJECT_NAME = "{{cookiecutter.github_project_name}}"
HOOK_DIR = os.path.realpath(os.path.curdir)
PROJECT_DIRECTORY = os.path.join(HOOK_DIR,'..',PROJECT_NAME)


LICENCE  = "{{cookiecutter.open_source_license}}"
NOT_OPEN_SOURCE =  LICENCE  == "Not open source"


# from https://github.com/audreyr/cookiecutter/issues/723
def delete_resource(resource):
    if os.path.isfile(resource):
        print("removing file: {}".format(resource))
        os.remove(resource)
    elif os.path.isdir(resource):
        print("removing directory: {}".format(resource))
        shutil.rmtree(resource)



if __name__ == '__main__':
    build_python_binding = ("{{cookiecutter.python_bindings}}" == 'yes')
    use_xtensor = ("{{cookiecutter.use_xtensor}}" == 'yes')

    if not build_python_binding:
        py_dir = os.path.join(PROJECT_DIRECTORY, 'python')
        delete_resource(py_dir)

    if NOT_OPEN_SOURCE:
        licence_file = os.path.join(PROJECT_DIRECTORY, 'LICENCE.txt')
        delete_resource(licence_file)

    py_main_file = os.path.join(PROJECT_DIRECTORY, 'python/src/main.cpp')
    py_main_xt_file = os.path.join(PROJECT_DIRECTORY, 'python/src/main_xt.cpp')
    py_main_no_xt_file = os.path.join(PROJECT_DIRECTORY, 'python/src/main_no_xt.cpp')
    
    if os.path.isfile(py_main_file):
        delete_resource(py_main_file)

    if use_xtensor:
        os.rename(py_main_xt_file, py_main_file)
        delete_resource(py_main_no_xt_file)
    else:
        os.rename(py_main_no_xt_file, py_main_file)
        delete_resource(py_main_xt_file)

