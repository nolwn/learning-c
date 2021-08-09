# Learning C

I'm learning C by reading books including the classic The C Programming Language. These are exercises that I am using to get things to actually go into my brain.

## Building

I don't want to maintain a bunch of tiny repos, so this repo will have a bunch of simple programs in it. To build one, use make followed by the name of the program (each program has a folder in src which bears its name).

The makefile does not build programs with the debug flag by default. To build programs for debugging, set the environment variable `CFLAGS` to `-g`.

## Libs

Common functions I'm writing for these projects. Although the standard library has some of these functions, simple implementations of them are discussed in the K&R so I am writing them as a learning exercise. libs will automatically be built if needed when you make a program. To build them yourself, use `make libs`.

## Calculator

The calculator is a Reverse Polish int calculator (as in, it only operates on integers). It could easily be modified to add floats.

To add two numbers, for instance 5 and 9, run `calculator 5 9 +`. Multiplication, division and subtractions are also supported by changing the operator to `x`, `/`, or `-`, respectively. To subtract two numbers and then multiply the result, for instance 134 - 34 * 3, run `calculator 134 34 3 - *`. For more about the weird glory that is Reverse Polish notation, check out the wikipedia page: https://en.wikipedia.org/wiki/Reverse_Polish_notation.

Note: I wanted multiplication to be `*` but that isn't as easy to pass as an argument. You would have to either pass it as `"*"` or `\*` which isn't as nice. So `x` it is!

To build, use `make calculator`.