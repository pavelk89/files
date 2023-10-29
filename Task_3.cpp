#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    // Открытие файла для чтения
    std::ifstream inFile("input.txt");

    // Проверка, успешно ли открылся файл
    if (inFile.is_open()) {
        std::string line;
        int wordCount = 0;

        // Чтение строки из файла
        while (std::getline(inFile, line)) {
            std::istringstream iss(line);
            std::string word;

            // Разделение строки на слова
            while (iss >> word) {
                wordCount++;
            }
        }

        // Вывод количества слов
        std::cout << "Количество слов в файле: " << wordCount << std::endl;

        // Закрытие файла
        inFile.close();
    } else {
        // Вывод сообщения об ошибке, если файл не удалось открыть
        std::cerr << "Не удалось открыть файл." << std::endl;
    }

    return 0; // Возврат нуля, обозначающего успешное завершение программы
}
