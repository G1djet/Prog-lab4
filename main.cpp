/**
 * @file main.cpp
 * @brief Программа, которая находит второй по величине элемент в прямоугольной матрице и его местоположение.
 */

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Главная функция программы.
 * @return 0 в случае успешного завершения.
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
            } else if (matrix[i][j] > max2 && matrix[i][j] != max1) {
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