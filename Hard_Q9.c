#include <stdio.h>

int count_exactly_one_consecutive_pair() {
    int count = 0;

    // There are 2^10 = 1024 subsets of a 10-element set
    for (int mask = 0; mask < (1 << 10); mask++) {
        int pair_count = 0;

        for (int i = 0; i < 9; i++) {
            // check if both i and i+1 are in the subset
            if (((mask >> i) & 1) && ((mask >> (i + 1)) & 1)) {
                pair_count++;
            }
        }

        if (pair_count == 1) {
            count++;
        }
    }

    return count;
}

int main() {
    int result = count_exactly_one_consecutive_pair();
    printf("Number of subsets with exactly one pair of consecutive integers: %d\n", result);
    return 0;
}
