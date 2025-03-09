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
    arr[i] = rand() % 100000; // Числа от 0 до 99999
  }
  return arr;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Использование: %s <размер_массива>\n", argv[0]);
    return 1;
  }

  int size = atoi(argv[1]);
  if (size < 1) {
    printf("Ошибка: неверный размер\n");
    return 1;
  }
  int *arr = generate_random_array(size);

  printf("Исходный массив:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("Максимальные числа:\n");
  for (int i = 0; i < size; i++) {
    printf("%d -> %d\n", arr[i], max_number(arr[i]));
  }

  free(arr);
  return 0;
}