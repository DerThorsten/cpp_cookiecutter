#include <iostream>

#include "{{cookiecutter.cpp_root_folder_name}}/{{cookiecutter.package_name}}.hpp"
#include "{{cookiecutter.cpp_root_folder_name}}/{{cookiecutter.package_name}}_config.hpp"

int main(int argc, char *argv[]){
    std::cout<<"{{cookiecutter.cpp_macro_prefix}}_VERSION_MAJOR "<<{{cookiecutter.cpp_macro_prefix}}_VERSION_MAJOR<<"\n";
    std::cout<<"{{cookiecutter.cpp_macro_prefix}}_VERSION_MINOR "<<{{cookiecutter.cpp_macro_prefix}}_VERSION_MINOR<<"\n";
    std::cout<<"{{cookiecutter.cpp_macro_prefix}}_VERSION_PATCH "<<{{cookiecutter.cpp_macro_prefix}}_VERSION_PATCH<<"\n";
}