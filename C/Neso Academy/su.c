#include <stdio.h>

#pragma pack(1)

struct {
  double a; // 8 bytes
  union {
    char b[4]; // 4 bytes
    double c;  // 8 bytes
    int d;     // 4 bytes
  } e;         // 8 bytes
  char f[4];   // 4 bytes
} s;           // 20 bytes

union {
  double a; // 8 bytes
  struct {
    char b[4]; // 4 bytes
    double c;  // 8 bytes
    int d;     // 4 bytes
  } e;         // 16 bytes
  char f[4];   // 4 bytes
} u;           // 16 bytes

int main(void) {
  printf("%ld %ld", sizeof(s), sizeof(u));
  return 0;
}
