#!/bin/bash


echo "Config conda" || exit 1
conda config --set always_yes yes --set changeps1 no || exit 1
echo "Update conda" || exit 1
conda update -q conda || exit 1
echo "create conda env myroot" || exit 1
conda create -n myroot ||exit 1
echo "activate" || exit 1
source $CONDA/bin/activate myroot || exit 1
echo "install cookiecutter" || exit 1
conda install cookiecutter -c conda-forge  || exit 1
echo "install conda-build" || exit 1
conda install conda-build || exit 1
cd .. || exit 1
echo "run cookiecutter"  || exit 1
cookiecutter $(repoDir)  --overwrite-if-exists --no-input || exit 1
cd cpptools || exit 1
echo "Activating conda environment" || exit 1
conda env create -f cpptools-dev-requirements.yml || exit 1
echo "source conda env" || exit 1
source $CONDA/bin/activate cpptools-dev-requirements || exit 1
mkdir build || exit 1
cd build || exit 1
echo "cmake" || exit 1
cmake .. || exit 1
echo "make" || exit 1
make -j2 || exit 1
make cpp-test || exit 1
make python-test || exit 1
echo "Completed script successfully" || exit 1