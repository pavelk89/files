#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Открытие файла для чтения
    std::ifstream inputFile("input.txt");
    
    // Проверка, успешно ли открыт файл для чтения
    if (inputFile.is_open()) {
        std::string wordToFind;
        std::cout << "Введите слово для поиска: ";
        std::cin >> wordToFind;
        
        std::string line;
        int lineNumber = 1;
        
        // Чтение строк из файла
        while (std::getline(inputFile, line)) {
            // Поиск слова в текущей строке
            size_t found = line.find(wordToFind);
            if (found != std::string::npos) {
                // Если слово найдено, выводим строку и ее номер
                std::cout << "Найдено в строке " << lineNumber << ": " << line << std::endl;
            }
            lineNumber++;
        }
        
        // Закрытие файла
        inputFile.close();
    } else {
        // Вывод сообщения об ошибке, если файл не удалось открыть
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
    }

    return 0; // Возврат нуля, обозначающего успешное завершение программы
}
