#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief Переставляет цифры числа для получения максимального значения.
 * @param num Исходное число.
 * @return Максимальное число, составленное из цифр исходного числа.
 */
int max_number(int num) {
  char digits[10];
  sprintf(digits, "%d", num);
  int len = strlen(digits);

  // Сортировка цифр в порядке убывания
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (digits[i] < digits[j]) {
        char temp = digits[i];
        digits[i] = digits[j];
        digits[j] = temp;
      }
    }
  }
  return atoi(digits);
}

/**
 * @brief Генерирует массив случайных чисел.
 * @param size Размер массива.
 * @return Указатель на массив.
 */
int *generate_random_array(int size) {
  int *arr = malloc(size * sizeof(int));
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 1000; // Числа от 0 до 999
  }
  return arr;
}

