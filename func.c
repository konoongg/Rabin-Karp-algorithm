#include "func.h"
#include <stdlib.h>
#include <stdio.h>

const char RUS_BYTE = 92;
const char RUS_BYTE_E = 80;
const char RUS_BYTE_F = 96;

int HashEq(int hashPattern, int hashExcerpt, int cCount, int simCounter, int* pattern, int* excerpt, int* times) {
    if (hashPattern == hashExcerpt) {
        if (*times == 0) {
            printf("%d ", hashPattern);
            *times += 1;
        }
        for (int i = 0; i < cCount; ++i) {

            printf("%d ", i + simCounter + 1);
            if (pattern[(i + simCounter % cCount) % cCount] != excerpt[i]) {
                return 0;
            }
        }
        return 0;
    }
    return 0;
}

int HandleRus(int c) {
    if (c == RUS_BYTE) {
        if (getchar() == -1) {
            return -1;
        }

        // в этих тестах нет, но я на всякий, чтобы с последними русскими буквами работало
        int rusAlf = getchar();
        c = (int)getchar();
        if (rusAlf == 'E') {
            c += RUS_BYTE_E;
        }
        else {
            c += RUS_BYTE_F;
        }
    }
    return c;
}

