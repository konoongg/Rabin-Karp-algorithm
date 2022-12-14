#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "func.h"

int main() {
    int excerpt[16];
    int c;
    int cCount = 0;
    int hashExcerpt = 0;
    while ((c = (int)getchar()) != '\n') {
        c = HandleRus(c);
        hashExcerpt += (int)c % 3 * (int)pow(3, cCount);
        excerpt[cCount] = c;
        ++cCount;
    }
    int* pattern = (int*)malloc(cCount * sizeof(int));
    int hashPattern = 0;
    for (int i = 0; i < cCount; ++i) {
        c = (int)getchar();
        if (c == -1) {
            printf("0");
            free(pattern);
            return 0;
        }
        c = HandleRus(c);
        hashPattern += (int)c % 3 * (int)pow(3, i);
        pattern[i] = c;
    }
    int maxPow = (int)pow(3, cCount - 1);
    int simCounter = 0;
    int times = 0;
    while ((c = (int)getchar()) != EOF ) {
        c = HandleRus(c);
        HashEq(hashPattern, hashExcerpt, cCount, simCounter, pattern, excerpt, &times);
        hashPattern -= pattern[simCounter % cCount] % 3;
        hashPattern /= 3;
        hashPattern += (int)c % 3 * maxPow;
        pattern[simCounter % cCount] = c;
        ++simCounter;
    }
    HashEq(hashPattern, hashExcerpt, cCount, simCounter, pattern, excerpt, &times);
    if (times == 0) {
        printf("0");
    }
    free(pattern);
    return 0;
}


