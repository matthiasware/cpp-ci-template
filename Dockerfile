FROM ubuntu:16.04
MAINTAINER matthiasware

# for add-apt-repository
RUN apt-get update && apt-get install -y software-properties-common

# for g++ and gcc
RUN add-apt-repository ppa:ubuntu-toolchain-r/test

# install packages
RUN apt-get update && apt-get install -y \
	build-essential\
	gcc-7 \
	g++-7 \
	git \
	curl \
	wget

# cerate links
RUN ln -sf /usr/bin/g++-7 /usr/bin/g++
RUN ln -s /usr/bin/gcc-7 /usr/bingcc

# install cmake
RUN cd /usr/local/src \
	&& wget https://cmake.org/files/v3.12/cmake-3.12.0.tar.gz \
	&& tar xvf cmake-3.12.0.tar.gz \
	&& cd cmake-3.12.0 \
	&& ./bootstrap \
	&& make \
	&& make install \
	&& rm -rf /usr/local/src/cmake*

# install doctest
RUN cd /usr/local/src \
	&& git clone https://github.com/onqtam/doctest.git \
	&& cd doctest \
	&& mkdir build \
	&& cd build \
	&& cmake .. \
	&& make \
	&& make test \
	&& make install \
	&& rm -rf /usr/local/src/doctest

CMD ["/bin/bash"]