FROM debian:10 as builder

RUN apt update && apt install -y clang make

WORKDIR /build
COPY . .

RUN adduser player && chown -R player /build
#
USER player


RUN make re
CMD ./player

