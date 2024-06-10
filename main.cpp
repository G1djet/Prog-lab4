/**
 * @file main.cpp
 * @brief Поиск второго по величине элемента в матрице и его местоположения
 *
 * Данная программа считывает размерность матрицы, элементы матрицы и находит
 * второй по величине элемент матрицы, а также его местоположение (номер строки и столбца).
 */

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Главная функция программы
 *
 * Основные шаги программы:
 * 1. Ввод размерности матрицы.
 * 2. Ввод элементов матрицы.
 * 3. Поиск второго по величине элемента матрицы и его местоположения.
 * 4. Вывод второго по величине элемента и его местоположения.
 *
 * @return Возвращает 0 при успешном завершении программы.
 */
int main() {
    int rows, cols;
    std::cout << "Введите количество строк и столбцов матрицы: ";
    std::cin >> rows >> cols;

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

    std::cout << "Введите элементы матрицы по строкам:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int max1 = INT_MIN, max2 = INT_MIN;
    int max1_row, max1_col, max2_row, max2_col;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > max1) {
                max2 = max1;
                max2_row = max1_row;
                max2_col = max1_col;
                max1 = matrix[i][j];
                max1_row = i;
                max1_col = j;
            } 
            else if (matrix[i][j] > max2 && matrix[i][j] != max1) {
                max2 = matrix[i][j];
                max2_row = i;
                max2_col = j;
            }
        }
    }

    std::cout << "Второй по величине элемент матрицы: " << max2 << std::endl;
    std::cout << "Его местоположение: строка " << max2_row + 1 << ", столбец " << max2_col + 1 << std::endl;

    return 0;
}