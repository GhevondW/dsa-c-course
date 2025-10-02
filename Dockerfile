FROM ubuntu:22.04

# Avoid prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install essential C development tools
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    clang \
    clang-format \
    git \
    gdb \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

# Set clang as default compiler
ENV CC=clang
ENV CXX=clang++

# Create working directory
WORKDIR /workspace

# Default command
CMD ["/bin/bash"]