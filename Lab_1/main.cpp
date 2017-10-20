#include <stdio.h>

int main() {
    float f;
    scanf("%f", &f);

    unsigned int* ptr = (unsigned int*)&f;

    int sign = *ptr >> 31;
    int mantisa = (*ptr & 0x007FFFFF);
    int exponent = ((*ptr & 0x7f800000) >> 23) - 127;
    
    char s_sign = '+';
    if (sign) {
        s_sign = '-';
    }
    
    if ((mantisa == 0) && (exponent == -127)) {
        if (sign) {
            printf("-0");
        }
        else {
            printf("+0");
        }
        return 0;
    }

    if ((mantisa == 0) && (exponent == 128)) {
        if (sign) {
            printf("-INF");
        } else {
            printf("+INF");
        }
        return 0;
    }

    if ((mantisa != 0) && (exponent == -127)) {
        printf("%c0.", s_sign);
    
    	char s[23];
    	int i = 1;
    	while (i != 24) {
            s[23 - i] = mantisa & 1 ? '1' : '0';
            mantisa >>= 1;
            i++;
    	}
    	for (int i = 0; i < 23; ++i) {
            printf("%c", s[i]);
    	}

    	printf("_2 * 2^{%d}", exponent + 1);
    } else {
        printf("%c1.", s_sign);
    
    	char s[23];
    	int i = 1;
    	while (i != 24) {
            s[23 - i] = mantisa & 1 ? '1' : '0';
            mantisa >>= 1;
            i++;
    	}
    	for (int i = 0; i < 23; ++i) {
            printf("%c", s[i]);
    	}

    	printf("_2 * 2^{%d}", exponent);
    }
    return 0;
}

