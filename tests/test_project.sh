#!/bin/bash


TEMPLATE_FOLDER=$0

echo "create cpp_cookiecuytter-dev-requirements conda env"
conda env create -f cpp_cookiecutter-dev-requirements.sh

echo "activate cpp_cookiecuytter-dev-requirements conda env"
conda activate cpp_cookiecutter-dev-requirements

echo "render coookiecutter template"
cookiecutter TEMPLATE_FOLDER --overwrite-if-exists --no-input

echo "go into cpp tools"
cd cpptools

echo "create cpptools-dev-requirements conda env"
conda env create -f cpptools-dev-requirements.yml

echo "activate cpptools-dev-requirements conda env"
source activate cpptools-dev-requirements

echo "create build dir"
mkdir build

echo "go into build dir"
cd build

echo "run cmake"
cmake ..

echo "build project"
make -j2

echo "run cpp tests"
make cpp-test

echo "run python tests"
make python-test


echo "run example"
cd examples
./hello_world
cd ..

echo "run benchmark"
cd benchmark
./benchmark_cpptools
cd ..


echo "Completed test script successfully"