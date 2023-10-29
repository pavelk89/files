#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Открытие файла для чтения
    std::ifstream inFile("input.txt");
    // Открытие файла для записи
    std::ofstream outFile("output.txt");

    // Проверка, успешно ли открылись файлы для чтения и записи
    if (inFile.is_open() && outFile.is_open()) {
        std::string line;
        // Чтение строки из входного файла
        while (std::getline(inFile, line)) {
            // Поиск подстроки "old_word" в текущей строке
            size_t pos = line.find("old_word");
            // Если подстрока найдена
            if (pos != std::string::npos) {
                // Замена найденной подстроки на "new_word" в текущей строке
                line.replace(pos, 8, "new_word");
            }
            // Запись измененной строки в выходной файл с добавлением символа новой строки
            outFile << line << std::endl;
        }
        // Вывод сообщения о завершении замены в стандартный вывод
        std::cout << "Замена завершена." << std::endl;
        // Закрытие файлов
        inFile.close();
        outFile.close();
    } else {
        // Вывод сообщения об ошибке в стандартный вывод ошибок
        std::cerr << "Не удалось открыть файлы." << std::endl;
    }

    return 0; // Возврат нуля, обозначающего успешное завершение программы
}
