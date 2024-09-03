all: build run

build:
	@clang main.c -o igr

run:
	@./igr