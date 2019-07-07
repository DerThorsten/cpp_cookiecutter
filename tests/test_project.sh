#!/bin/bash


TEMPLATE_FOLDER=$1
SOURCE=$2

echo $TEMPLATE_FOLDER
echo $SOURCE=

echo "create cpp_cookiecutter-dev-requirements conda env"
conda env create -f cpp_cookiecutter-dev-requirements.yml || exit 1

echo "activate cpp_cookiecutter-dev-requirements conda env"
$SOURCE activate cpp_cookiecutter-dev-requirements || exit 1

echo "take one step back"
cd .. || exit 1
ls || exit 1

echo "render coookiecutter template"
cookiecutter $TEMPLATE_FOLDER --overwrite-if-exists --no-input || exit 1

echo "go into cpp tools"
cd cpptools || exit 1

echo "create cpptools-dev-requirements conda env"
conda env create -f cpptools-dev-requirements.yml || exit 1

echo "activate cpptools-dev-requirements conda env"
$SOURCE activate cpptools-dev-requirements || exit 1

echo "create build dir"
mkdir build || exit 1

echo "go into build dir"
cd build || exit 1

echo "run cmake"
cmake .. || exit 1

echo "build project"
make -j2 || exit 1

echo "run cpp tests"
make cpp-test || exit 1

echo "run python tests"
make python-test || exit 1


echo "run example"
cd examples || exit 1
./hello_world || exit 1
cd .. || exit 1

echo "run benchmark"
cd benchmark || exit 1
./benchmark_cpptools || exit 1
cd .. || exit 1


echo "Completed test script successfully"