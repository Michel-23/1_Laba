#include <iostream>

void divideRowByDiagonalElement(int** arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i][i] = (arr[i][i] != 0) ? arr[i][i] : 1; // Проверка деления на ноль
        for (int j = 0; j < size; j++) {
            arr[i][j] /= arr[i][i];
        }
    }
}

int main() {
    const int size = 3; // Размер двумерного массива
    int** array = new int*[size];

    //заполнение массива от -10 до 10
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            array[i][j] = rand() % 21 - 10;
        }
    }
    // for (int i = 0; i < size; i++) {
    //     array[i] = new int[size];
    //     for (int j = 0; j < size; j++) {
    //         array[i][j] = i * size + j + 1; // Пример заполнения массива
    //     }
    // }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std:: cout << std::endl;
    
    return 0;
    divideRowByDiagonalElement(array, size);

    // Вывод измененного массива
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Освобождение памяти
    for (int i = 0; i < size; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}