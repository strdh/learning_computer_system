#include <stdio.h>

void swap1(int *a, int *b);
void swap2(int *a, int *b);
void print_arr(int arr[], int n);
void reverse_arr1(int arr[]);
void reverse_arr2(int arr[]);

int main() {
  return 0;
}

void swap1(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void swap2(int *a, int *b) {
  *b = *a ^ *b;
  *a = *a ^ *b;
  *b = *a ^ *b;
}

void print_arr(int arr[], int n) {
  for (int i = 0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
