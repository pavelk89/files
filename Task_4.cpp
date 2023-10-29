#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Открытие файла для чтения
    std::ifstream sourceFile("source.txt");
    // Открытие файла для записи
    std::ofstream destinationFile("destination.txt");

    // Проверка, успешно ли открылись файлы для чтения и записи
    if (sourceFile.is_open() && destinationFile.is_open()) {
        std::string line;
        // Чтение строки из исходного файла
        while (std::getline(sourceFile, line)) {
            // Запись строки в файл-назначение с добавлением символа новой строки
            destinationFile << line << std::endl;
        }
        // Вывод сообщения о завершении копирования в стандартный вывод
        std::cout << "Копирование завершено." << std::endl;
        // Закрытие файлов
        sourceFile.close();
        destinationFile.close();
    } else {
        // Вывод сообщения об ошибке в стандартный вывод ошибок
        std::cerr << "Не удалось открыть файлы." << std::endl;
    }

    return 0; // Возврат нуля, обозначающего успешное завершение программы
}
