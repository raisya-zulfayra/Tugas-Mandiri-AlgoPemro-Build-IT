#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int compare(const void *a, const void *b) {
    long long diff = *(const long long *)a - *(const long long *)b;
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

int main() {
    long long n;
    
    if (scanf("%lld", &n) != 1) return 0;

    long long *a = (long long *)malloc(n * sizeof(long long));
    if (a == NULL) {
        return 1;
    }

    for (long long i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    qsort(a, n, sizeof(long long), compare);

    long long total_pairs = n * (n - 1) / 2;
    long long invalid_pairs = 0;
    long long count = 1;

    for (long long i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            count++;
        } else {
            invalid_pairs += count * (count - 1) / 2;
            count = 1;
        }
    }
   
    invalid_pairs += count * (count - 1) / 2;

    long long valid_pairs = total_pairs - invalid_pairs;
   
    long long ans = valid_pairs % 1000000007;

    printf("%lld\n", ans);

    free(a);
    
    return 0;
}