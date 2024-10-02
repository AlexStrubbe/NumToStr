#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Converts an integer number to its string representation in English.
 *
 * This function converts a non-negative integer to a string where each digit is
 * represented by its English word. For example, the number `123` would be
 * converted to `"one two three "`. The resulting string is dynamically
 * allocated and assigned to the pointer `c`.
 *
 * @param num The integer number to be converted.
 * @param c A pointer to a character pointer that will point to the resulting
 * string.
 *
 * @note The resulting string is dynamically allocated and should be freed by
 * the caller when no longer needed.
 */
void NumToStr(int num, char **c) {
  int i;
  int digits = 0;
  char buffer[1024] = {0};

  const char *numbers[] = {"zero ", "one ", "two ",   "three ", "four ",
                           "five ", "six ", "seven ", "eight ", "nine "};

  /** Handle the special case where num is zero */
  if (num == 0) {
    *c = (char *)malloc(strlen(numbers[0]) + 1);
    if (*c == NULL) {
      perror("Failed to allocate memory");
      exit(EXIT_FAILURE);
    }
    strcpy(*c, numbers[0]);
    return;
  }

  /** Count the number of digits in the number */
  int temp = num;
  while (temp > 0) {
    digits++;
    temp /= 10;
  }

  /** Allocate memory to store the digits in reverse order */
  temp = num;
  int *order = (int *)malloc(digits * sizeof(int));
  if (order == NULL) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
  }

  /** Store each digit of the number in reverse order */
  for (i = 0; i < digits; i++) {
    order[i] = temp % 10;
    temp /= 10;
  }

  /** Build the resulting string by concatenating the English words for each
   * digit */
  for (i = digits - 1; i >= 0; i--) {
    strcat(buffer, numbers[order[i]]);
  }

  /** Allocate memory for the final result and copy the string */
  *c = (char *)malloc(strlen(buffer) + 1);
  if (*c == NULL) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
  }
  strcpy(*c, buffer);

  /** Free the temporary memory used for storing digits */
  free(order);
}
