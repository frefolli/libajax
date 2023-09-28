CC=gcc
CXX=g++

#CC=clang
#CXX=clang++

INCLUDE=$(shell find include -type f)
SRC=$(shell find src -type f)
EXE=./builddir/main.exe

@all: ${EXE}

${EXE}: ${INCLUDE} ${SRC}
	CC=${CC} CXX=${CXX} meson setup builddir
	ninja -C builddir

run: ${EXE}
	${EXE}

clean:
	ninja -C builddir clean

depclean:
	rm -rf builddir
	rm -rf subprojects/*.git
