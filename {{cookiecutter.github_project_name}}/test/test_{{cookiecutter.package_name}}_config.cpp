#include <doctest.h>

#include "{{cookiecutter.cpp_root_folder_name}}/{{cookiecutter.package_name}}.hpp"
#include "{{cookiecutter.cpp_root_folder_name}}/{{cookiecutter.package_name}}_config.hpp"



TEST_SUITE_BEGIN("core");

TEST_CASE("check version"){

    #ifndef {{cookiecutter.cpp_macro_prefix}}_VERSION_MAJOR
        #error "{{cookiecutter.cpp_macro_prefix}}_VERSION_MAJOR is undefined"
    #endif
    

    #ifndef {{cookiecutter.cpp_macro_prefix}}_VERSION_MINOR
        #error "{{cookiecutter.cpp_macro_prefix}}_VERSION_MINOR is undefined"
    #endif


    #ifndef {{cookiecutter.cpp_macro_prefix}}_VERSION_PATCH
        #error "{{cookiecutter.cpp_macro_prefix}}_VERSION_PATCH is undefined"
    #endif

    CHECK_GE({{cookiecutter.cpp_macro_prefix}}_VERSION_MAJOR , 0);
    CHECK_GE({{cookiecutter.cpp_macro_prefix}}_VERSION_MINOR , 0);
    CHECK_GE({{cookiecutter.cpp_macro_prefix}}_VERSION_PATCH , 0);
}

TEST_SUITE_END(); // end of testsuite core
