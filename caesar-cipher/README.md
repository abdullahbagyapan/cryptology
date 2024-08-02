# Caesar Cipher

In cryptography, a **Caesar cipher**, also known as **Caesar's cipher**, the **shift cipher**, **Caesar's code**, or **Caesar shift**, is one of the simplest and most widely known encryption techniques. It is a type of **substitution cipher** in which each letter in the plaintext is replaced by a letter some fixed number of positions down the alphabet. For example, with a left shift of 3, D would be replaced by A, E would become B, and so on. The method is named after Julius Caesar, who used it in his private correspondence.

## Examples

For instance, here is a Caesar cipher using a left rotation of three places, equivalent to a right shift of 23 (the shift parameter is used as the key): 

```
Plaintext:  THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
Ciphertext: QEB NRFZH YOLTK CLU GRJMP LSBO QEB IXWV ALD
```

## How to Build & Execute

### Build

To compile the source code we need to create a Makefile to automate the process. Makefiles allow us to compile source files fit into one easy to use file. 

```
make
```

### Execute

Makefile automaticly compile and extract executable and compiled object files to `build` directory.

```
./build/main
```

## TODO'S

There are some `TODO`'s in this project.

1. Missing lower case letters implementation for encryption/decryption. (file: `src/cipher.c`, line: `34`)

2. Missing mapping of lower and capitialize letter for any alphabet (currently support English alphabet). (file: `src/cipher.c`, line: `18`)

## Contribution

We welcome contributions from the community! If you’d like to contribute to this project, please follow the guidelines below.

### How to Contribute

1. Fork the Repository
2. Clone Your Fork
3. Create a Branch
4. Make Changes
5. Test Your Changes
6. Commit Your Changes
7. Push Your Changes
8. Submit a Pull Request

**Thank you for contributing!**

Feel free to adjust the instructions according to your project's specific needs and contribution workflow.

## Referenses

-  https://en.wikipedia.org/wiki/Caesar_cipher