FROM --platform=linux/amd64 debian:bookworm

RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    wget \
    flex \
    bison \
    texinfo \
    libgmp-dev \
    libmpfr-dev \
    libmpc-dev \
    groff \
    && rm -rf /var/lib/apt/lists/*

# Build GCC4TI from source
RUN git clone --depth=1 --branch next https://github.com/debrouxl/gcc4ti.git /opt/gcc4ti-src

WORKDIR /opt/gcc4ti-src/trunk/tigcc-linux/scripts

# Run the source preparation script
RUN ./updatesrc

WORKDIR /opt/gcc4ti-src/trunk/tigcc-linux/gcc4ti-0.96b11

# Install GCC4TI (uses $TIGCC as install prefix)
ENV TIGCC=/opt/gcc4ti
RUN mkdir -p $TIGCC && scripts/Install

ENV PATH="$TIGCC/bin:$PATH"

WORKDIR /build
