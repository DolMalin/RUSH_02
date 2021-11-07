FROM debian:10 as builder

## Compilation stage :
#
# If you have a language which need a compilation phase
# (C, C++, Go, Rust), compile it here in the
# 'builder stage'.
# Launching `update` command before is a good practice
# and in some cases necessary if you want to install
# or update some packages. (`apt` is the package manager
# of Debian)
#
RUN apt update && apt install -y clang make

## Mandatory copy and workdir
#
WORKDIR /build

COPY . .

## Building commands :
#
# The bots are built here.
# Add your own if you need it.
#
RUN make run
