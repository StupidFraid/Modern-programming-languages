#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void encryptFile(const std::string &inputFileName, const std::string &outputFileName, const std::string &key) {
    std::ifstream inputFile(inputFileName, std::ios::binary);
    std::ofstream outputFile(outputFileName, std::ios::binary);
    if (!inputFile || !outputFile) {
        std::cerr << "Ошибка открытия файла\n";
        exit(EXIT_FAILURE);
    }

    size_t keyLength = key.size();
    size_t keyIndex = 0;
    char ch;

    while (inputFile.get(ch)) {
        outputFile.put(ch ^ key[keyIndex]);
        keyIndex = (keyIndex + 1) % keyLength;
    }
}

bool compareFiles(const std::string &file1, const std::string &file2) {
    std::ifstream f1(file1, std::ios::binary);
    std::ifstream f2(file2, std::ios::binary);

    if (!f1 || !f2) {
        std::cerr << "Ошибка открытия файла для проверки\n";
        return false;
    }

    std::istreambuf_iterator<char> begin1(f1), begin2(f2), end;
    return std::equal(begin1, end, begin2);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Использование: " << argv[0] << " <input file> <output file> <key>\n";
        return EXIT_FAILURE;
    }

    std::string inputFileName = argv[1];
    std::string outputFileName = argv[2];
    std::string key = argv[3];

    encryptFile(inputFileName, outputFileName, key);

    // Проверка правильности: повторное шифрование для получения исходного файла
    std::string decryptedFileName = "decrypted_output.txt";
    encryptFile(outputFileName, decryptedFileName, key);

    // Сравнение исходного файла и расшифрованного файла
    if (compareFiles(inputFileName, decryptedFileName)) {
        std::cout << "Проверка пройдена: файл успешно зашифрован и расшифрован.\n";
    } else {
        std::cout << "Проверка не пройдена: расшифрованный файл отличается от исходного.\n";
    }

    return EXIT_SUCCESS;
}
