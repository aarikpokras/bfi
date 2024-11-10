# bfi
A simple BrainF interpreter written in C

## Compiling and Using
Clone the repo:
```console
$ git clone https://github.com/aarikpokras/bfi.git
```
In the bfi directory, make the build directory and run:
```console
$ cmake -Bbuild
```
Then enter the build directory and run:
```console
$ make
```
The binary should then be in that directory.

Put the name of the file in the argument, e.g.
```console
$ ./bfi main.bf
```
