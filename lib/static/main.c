#include "algo.h"
#include <stdio.h>

int main() {
    int left = 8;
    int right = 5;
    printf("%d add %d is %d\n", left, right, add(left, right));  
    printf("%d sub %d is %d\n", left, right, sub(left, right));  
    return 0;
}
