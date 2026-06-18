#include <iostream>
#include <fstream>
#include <string>

bool processFile(const std::string& inputFile, const std::string& outputFile, const std::string& key) {
    std::ifstream inFile(inputFile, std::ios::binary);
    std::ofstream outFile(outputFile, std::ios::binary);

    if (!inFile || !outFile) {
        return false;
    }

    char ch;
    size_t keyIndex = 0;
    const size_t keyLength = key.length();

    while (inFile.get(ch)) {
        outFile.put(ch ^ key[keyIndex]);
        keyIndex = (keyIndex + 1) % keyLength;
    }

    return true;
}

int main() {
    const std::string key = "fii2026";

    std::ofstream testFile("target_file.txt");
    if (testFile) {
        testFile << "System configuration and root parameters.";
        testFile.close();
    }

    if (!processFile("target_file.txt", "payload.bin", key)) {
        std::cerr << "Error: Encryption failed.\n";
        return 1;
    }

    if (!processFile("payload.bin", "recovered.txt", key)) {
        std::cerr << "Error: Decryption failed.\n";
        return 1;
    }

    return 0;
}