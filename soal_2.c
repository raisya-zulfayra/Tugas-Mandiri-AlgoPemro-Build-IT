#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() {
    long long a, b, c;
    
    if (scanf("%lld %lld %lld", &a, &b, &c) != 3) {
        return 0;
    }

    long long arr[3] = {a, b, c};

    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (arr[i] > arr[j]) {
                long long temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    long long dist1 = arr[1] - arr[0]; // Jarak x ke y
    long long dist2 = arr[2] - arr[1]; // Jarak y ke z

    long long rounds = (dist1 < dist2) ? dist1 : dist2;

    printf("%lld\n", rounds);

    return 0;
}