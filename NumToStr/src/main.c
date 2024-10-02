#include <stdio.h>

#include "functions.h"

/**
 * @brief Main function to demonstrate the usage of NumToStr.
 *
 * This function demonstrates how to use the NumToStr function to convert an
 * integer to its English word representation. It converts the number
 * `1234567890` to a string and prints the result.
 *
 * @return An integer indicating the exit status of the program. Returns 0 on
 * successful execution.
 */
int main() {
  char *result;

  /** Convert the number 1234567890 to its English word representation */
  NumToStr(1234567890, &result);

  /** Print the resulting string */
  printf("%s\n", result);

  /** Free the dynamically allocated memory */
  free(result);

  return 0; /**< Return 0 to indicate successful execution */
}
