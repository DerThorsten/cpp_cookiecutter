#pragma once
#ifndef {{ cookiecutter.cpp_macro_prefix }}_{{cookiecutter.package_name|upper}}_HPP
#define {{ cookiecutter.cpp_macro_prefix }}_{{cookiecutter.package_name|upper}}_HPP

#include <cstdint>
#include <iostream>

namespace {{ cookiecutter.cpp_namespace }} {
    
    class MyClass
    {
    public:
        MyClass(const uint64_t size)
        : m_size(size)
        {

        }
        
        void hello_world()
        {
            std::cout<<"Hello World!\n";
        }
    private:
        uint64_t m_size;
    };

} // end namespace {{cookiecutter.cpp_namespace}}


#endif // {{ cookiecutter.cpp_macro_prefix }}_{{cookiecutter.package_name|upper}}_HPP