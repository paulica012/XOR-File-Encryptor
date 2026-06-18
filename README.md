# XOR File Encryptor

A lightweight C++ utility designed to encrypt and decrypt local files using bitwise XOR operations.

Developed to demonstrate fundamental understanding of applied cryptography, memory manipulation, and direct file system I/O streams in C++.

## Technical Details
* **Encryption Method:** Symmetric key encryption using the XOR (`^`) bitwise operator. The same algorithm and key are used for both encryption and decryption.
* **File Handling:** Uses `std::ifstream` and `std::ofstream` in binary mode to prevent data corruption during the encryption of non-text bytes.
* **Language:** C++11 (Standard Library)

## Usage
The program reads a target file byte-by-byte, applies the XOR cipher against a user-defined string key, and outputs the result to a newly generated file. Running the encrypted binary file back through the function with the same key restores the original file content.