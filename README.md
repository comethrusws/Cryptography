# Cryptography Lab Practicals

This repository contains all lab practicals implemented during my 5th semester Cryptography course. The implementations cover a wide range of cryptographic algorithms from classical ciphers to modern asymmetric algorithms.

## Repository Structure

### Lab 1: Substitution Ciphers
- `Lab1_1CeaserCipher.c` - Implementation of the Caesar Cipher
- `Lab1_2PolyalphabeticCipher.c` - Implementation of the Polyalphabetic (Vigenère) Cipher
- `Lab1_3Play_fairMatrixCipher.c` - Implementation of the Playfair Cipher
- `Lab1_4HillCipher.c` - Implementation of the Hill Cipher

### Lab 2: Transposition Techniques
- `Lab2_1Row_Transpose_Cipher.c` - Implementation of the Row Transposition Cipher
- `Lab2_2Rail_Fence_Cipher.c` - Implementation of the Rail Fence Cipher

### Lab 3: Modular Arithmetic
- `Lab3_1Euclidean_Algorithm.c` - Implementation of the Euclidean Algorithm for GCD
- `Lab3_2Relatively_Prime.c` - Program to check if two numbers are relatively prime
- `Lab3_3Extended_Euclidean_Algorithm.c` - Implementation of the Extended Euclidean Algorithm

### Lab 4: Asymmetric Ciphers
- `Lab4_2Checking_Prime_using_traditional_method.c` - Program to check if a number is prime
- `Lab4_3Millers_Algorithm.c` - Implementation of Miller's Algorithm for primality testing
- `Lab4_4Diffie-Helman_Key_Exchange.c` - Implementation of the Diffie-Hellman Key Exchange
- `Lab4_5RSA_Algorithm.c` - Implementation of the RSA Algorithm
- `Lab4_6ElGamal_Cryptographic_System.c` - Implementation of the ElGamal Cryptosystem

## Compilation Instructions

Most programs can be compiled using:
```bash
gcc -Wall program_name.c -o output_name
```

For programs using math functions (sqrt, floor, pow, etc.), use:
```bash
gcc -Wall program_name.c -o output_name -lm
```

This applies particularly to:
- Lab4_2Checking_Prime_using_traditional_method.c (using sqrt)
- Lab4_3Millers_Algorithm.c 
- Lab4_4Diffie-Helman_Key_Exchange.c
- Lab4_5RSA_Algorithm.c
- Lab4_6ElGamal_Cryptographic_System.c

## Usage

Run the compiled programs:
```bash
./output_name
```

Follow the prompts to input the required parameters for each algorithm.

## Notes

- Most implementations use basic C libraries: stdio.h, stdlib.h, string.h, math.h
- The code focuses on demonstrating the cryptographic concepts rather than production-level security
- Some algorithms use fixed parameters for demonstration purposes
