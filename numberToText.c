#include <stdio.h>

#define MAX_LEN_NUMBER_AS_TEXT 50
#define POW_OF_TEN_0 1
#define POW_OF_TEN_1 10
#define POW_OF_TEN_2 100

int pickCiffer(int aNumber, int powOf10);  // picks one ciffer out of a given number
void printNumberAsText(int aNumber);  // prints the given number as text to stdout
void convertNumberToText(int aNumber, char* result);  // converts the given number to digit texts into the given result variable

int main() {
    int number;
    printf("Please enter a number between 0 and 999:");
    scanf("%d", &number);
    printNumberAsText(number);
}

void printNumberAsText(int aNumber) {
    char ciffersToPrint[MAX_LEN_NUMBER_AS_TEXT];
    convertNumberToText(aNumber, ciffersToPrint);
    printf("\n%s", ciffersToPrint);
}

void convertNumberToText(int aNumber, char* result) {
  const char* CIFFERS_AS_TEXT[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIFE", "SIX", "SEVEN", "EIGHT", "NINE"};
  if (aNumber >= 100) {
    sprintf(result, "%s %s %s", CIFFERS_AS_TEXT[pickCiffer(aNumber, POW_OF_TEN_2)], CIFFERS_AS_TEXT[pickCiffer(aNumber, POW_OF_TEN_1)], CIFFERS_AS_TEXT[pickCiffer(aNumber, POW_OF_TEN_0)]);
  } else if (aNumber >= 10) {
    sprintf(result, "%s %s", CIFFERS_AS_TEXT[pickCiffer(aNumber, POW_OF_TEN_1)], CIFFERS_AS_TEXT[pickCiffer(aNumber, POW_OF_TEN_0)]);
  } else {
    sprintf(result, "%s", CIFFERS_AS_TEXT[pickCiffer(aNumber, POW_OF_TEN_0)]);
  }
}

int pickCiffer(int aNumber, int powOf10) {  // for example: 528, 10 --> returns 2
  int result = aNumber % (10 * powOf10);  // in this example: 28 (cuts the bigger ciffers)
  result -= result % powOf10;  // in this example: 20 (replaces the smaller ciffers by zero)
  return result / powOf10;  // in this example: 2 (cuts the zeros away to get the seeked ciffer)
}
