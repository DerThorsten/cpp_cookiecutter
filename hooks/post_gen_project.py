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

    if not build_python_binding:
        py_dir = os.path.join(PROJECT_DIRECTORY, 'python')
        delete_resource(py_dir)

    if NOT_OPEN_SOURCE:
        licence_file = os.path.join(PROJECT_DIRECTORY, 'LICENCE.txt')
        delete_resource(licence_file)
