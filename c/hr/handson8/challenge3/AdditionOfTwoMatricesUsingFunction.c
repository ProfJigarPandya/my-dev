i#include <stdio.h>

int main() {

    int m, n;
    scanf("%d %d", &m, &n);
    int matrix1[m][n], matrix2[m][n];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &matrix1[i][j]);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &matrix2[i][j]);
    
    matrix_addition(m, n, matrix1, matrix2);
    print(m, n, matrix1);
    
    return 0;
}
