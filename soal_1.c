#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    long long sum = 0;
    
    for (int i = 0; i < n; i++) {
        long long a;
        scanf("%lld", &a);
        sum += a;
    }

    long long minimum_operations;
    if (sum < 0) {
        minimum_operations = -sum;
    } else {
        minimum_operations = sum;
    }

    printf("%lld\n", minimum_operations);

    return 0;
}
