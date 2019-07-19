FROM continuumio/anaconda3:5.0.1

# install sys requirements
RUN apt-get update
RUN apt-get install -y build-essential git

# clone in repo
RUN git clone https://github.com/{{cookiecutter.github_user_name}}/{{cookiecutter.github_project_name}}

# update conda
RUN conda update --yes conda

# go into repo
RUN cd {{cookiecutter.github_project_name}} && conda env create -f {{cookiecutter.package_name}}-dev-requirements.yml

# activate
RUN echo "source activate {{cookiecutter.package_name}}-dev-requirements" > ~/.bash
ENV PATH /opt/conda/envs/{{cookiecutter.package_name}}-dev-requirements/bin:$PATH

# activate
#RUN conda activate {{cookiecutter.github_project_name}}-dev-requirements

# make build dir
RUN cd {{cookiecutter.github_project_name}} && mkdir build

# run cmake
RUN  cd {{cookiecutter.github_project_name}}/build && \
    cmake .. -DCMAKE_INSTALL_PREFIX=$(conda info --base)/envs/{{cookiecutter.github_project_name}}-dev-requirements

# build and install project
RUN cd {{cookiecutter.github_project_name}}/build && \
    make -j2 install 



##########################################
# BINDER
##########################################
RUN pip install --no-cache-dir notebook==5.*

ARG NB_USER=jovyan
ARG NB_UID=1000
ENV USER ${NB_USER}
ENV NB_UID ${NB_UID}
ENV HOME /home/${NB_USER}

RUN adduser --disabled-password \
    --gecos "Default user" \
    --uid ${NB_UID} \
    ${NB_USER}


# Make sure the contents of our repo are in ${HOME}
COPY . ${HOME}
USER root
RUN chown -R ${NB_UID} ${HOME}
USER ${NB_USER}