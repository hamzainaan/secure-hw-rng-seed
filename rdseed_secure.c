#include <stdio.h>
#include <immintrin.h>

#define MAX_RETRIES 10

#if defined(__x86_64__) || defined(_M_X64)
    #define IS_64BIT 1
    typedef unsigned long long U64;
#else
    #define IS_64BIT 0
    typedef unsigned int U64;
#endif

static inline int getNonDeterministicSeed(U64 *seed) {
    for (int i = 0; i < MAX_RETRIES; ++i) {
#if IS_64BIT
        if (_rdseed64_step(seed)) {
            return 1;
        }
#else
        if (_rdseed32_step(seed)) {
            return 1;
        }
#endif
    }
    return 0;
}

int main() {
    U64 seed;
    if (getNonDeterministicSeed(&seed)) {
#if IS_64BIT
        printf("64-bit seed: %llu\n", seed);
#else
        printf("32-bit seed: %u\n", seed);
#endif
    } else {
        printf("Failed to obtain seed. Try again!\n");
    }
    return 0;
}