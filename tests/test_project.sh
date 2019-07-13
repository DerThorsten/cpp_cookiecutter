#!/bin/bash


TEMPLATE_FOLDER=$1
SOURCE=$2

echo "------------------------------------------------------------"
echo "template folder dir: $TEMPLATE_FOLDER"
echo "conda source command: $SOURCE activate"
echo "------------------------------------------------------------"


echo "------------------------------------------------------------"
echo "create cpp_cookiecutter-dev-requirements conda env"
echo "------------------------------------------------------------"
conda env create -f cpp_cookiecutter-dev-requirements.yml || exit 1

echo "------------------------------------------------------------"
echo "activate cpp_cookiecutter-dev-requirements conda env"
echo "------------------------------------------------------------"
$SOURCE activate cpp_cookiecutter-dev-requirements || exit 1

echo "------------------------------------------------------------"
echo "take one step back"
echo "------------------------------------------------------------"
cd .. || exit 1

echo "------------------------------------------------------------"
echo "render coookiecutter template"
echo "------------------------------------------------------------"
cookiecutter $TEMPLATE_FOLDER --overwrite-if-exists --no-input || exit 1

echo "------------------------------------------------------------"
echo "go into cpp tools"
echo "------------------------------------------------------------"
cd cpptools || exit 1

echo "------------------------------------------------------------"
echo "create cpptools-dev-requirements conda env"
echo "------------------------------------------------------------"
conda env create -f cpptools-dev-requirements.yml || exit 1

echo "------------------------------------------------------------"
echo "activate cpptools-dev-requirements conda env"
echo "------------------------------------------------------------"
$SOURCE activate cpptools-dev-requirements || exit 1

echo "------------------------------------------------------------"
echo "create build dir"
echo "------------------------------------------------------------"
mkdir build || exit 1

echo "------------------------------------------------------------"
echo "go into build dir"
echo "------------------------------------------------------------"
cd build || exit 1

echo "------------------------------------------------------------"
echo "run cmake"
echo "------------------------------------------------------------"
cmake .. -DSPHINX_EXECUTABLE=$(locate sphinx-build -n 1)|| exit 1

echo "------------------------------------------------------------"
echo "build project"
echo "------------------------------------------------------------"
make -j2 || exit 1

echo "------------------------------------------------------------"
echo "run cpp tests"
echo "------------------------------------------------------------"
make cpp-test || exit 1

echo "------------------------------------------------------------"
echo "run python tests"
echo "------------------------------------------------------------"
make python-test || exit 1


echo "------------------------------------------------------------"
echo "run example"
echo "------------------------------------------------------------"
cd examples || exit 1
./hello_world || exit 1
cd .. || exit 1

echo "------------------------------------------------------------"
echo "run benchmark"
echo "------------------------------------------------------------"
cd benchmark || exit 1
./benchmark_cpptools || exit 1
cd .. || exit 1


echo "------------------------------------------------------------"
echo "build docs"
echo "------------------------------------------------------------"
make docs


echo "------------------------------------------------------------"
echo "Completed test script successfully"
echo "------------------------------------------------------------"
