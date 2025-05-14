#include <stdio.h>

int main() {
    int count_disjoint = 0;

    for (int A = 0; A < 32; A++) {
        // Loop over all 32 subsets of B
        for (int B = 0; B < 32; B++) {
            // Check if A and B are disjoint using bitwise AND
            if ((A & B) == 0)
                count_disjoint++;
        }
    }

    int total = 32 * 32; 
    int not_disjoint = total - count_disjoint; 
    double prob = (double)not_disjoint / total;

    printf("Disjoint: %d\n", count_disjoint);
    printf("Not disjoint: %d\n", not_disjoint);
    printf("Probability A ∩ B ≠ ∅: %.6f\n", prob);

    return 0;
}


//Subset counter program

#include<stdio.h>
void subset_count(int n)
    {
        int total = 1 << n;
        int count = 0;
        for (int mask = 0; mask < total; mask ++)
            {
                printf("{");
                for(int i = 0; i < n; i++)
                    {
                        if(mask & (1<<i))  
                            {
                                printf("%d", i+1);
                            }
                    }
                    
                    printf("}");
                    printf("\n");
            }
    }
int main()
    {
        int n;
        scanf("%d", &n);
        subset_count(n);
        return 0;
    }
