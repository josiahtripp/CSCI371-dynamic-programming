/*
        Brute Force Method
*/
#include <stdio.h>
#include <string.h>

int main(){

    int n;
    scanf("%d", &n);// How many test cases?

    for(int i = 0; i < n; i++){// For each test case

        unsigned long long a, b, total = 0;
        scanf("%llu%llu", &a, &b);

        for(register unsigned long long j = a; j <= b; j++){// For all numbers in range [a, b]

            static char int_str[20];// Holding string
            int_str[0] = '\0';

            sprintf(int_str, "%llu", j);

            static int str_len;
            str_len = strlen(int_str);

            for(register int k = 0; k < str_len; k++){// For each digit in the number
                total += int_str[k] - 48; // Find digit value usiong ASCII offset
            }
        }
        printf("%llu\n", total);
    }

    return 0;
}