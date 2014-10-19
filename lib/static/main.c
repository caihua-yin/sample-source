#include "algo.h"
#include <stdio.h>
#include <unistd.h>

int main() {
    int left = 8;
    int right = 5;
    while (1) {
        printf("%d add %d is %d\n", left, right, add(left, right));  
        printf("%d sub %d is %d\n", left, right, sub(left, right));
        sleep(1);
    }
    return 0;
}
