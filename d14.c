#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int matrix[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0)) {
                printf("Not an Identity Matrix");
                return 0;
            }
        }
    }

    printf("Identity Matrix");

    return 0;
}