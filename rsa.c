#include <sys/random.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <inttypes.h>

// ssize_t getrandom(void *buf, size_t buflen, unsigned int flags);

// int number = buf[0] | buf[1] << 8;

uint64_t random_number() {
  char* buf = malloc(5);
  getrandom(buf, 4, 0);
  uint64_t number = buf[0] | buf[1] << 8 | buf[2] << 16 | buf[3] << 24;
  free(buf);
  return abs(number);
}

bool is_prime(uint64_t p) {
  uint64_t limit = sqrt(p);
  for (long k = limit; k > 1; --k) {
    if (p % k == 0) {
      return false;
    }
  }
  return true;
}

uint64_t random_prime() {
  uint64_t x = random_number();
  while(!is_prime(x)) {
    x = random_number();
  }
  return x;
}

uint64_t random_relative_prime(uint64_t n) {
  return 0;
}


int main(int argc, char** argv) {
  uint64_t p = random_prime();
  uint64_t q = random_prime();
  
  uint64_t random_d = random_relative_prime((p-1) * (q-1));
  // 
  printf("%d, %d\n", p, is_prime(p));
}
