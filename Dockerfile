FROM debian:10 as builder

RUN apt update && apt install -y clang make

WORKDIR /build

COPY . .

RUN make run
CMD ./rush_02

