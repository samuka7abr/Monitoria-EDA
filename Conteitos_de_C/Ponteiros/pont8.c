// Arrays Multidimensionais

/*
    Apesar de terem mais de uma dimensão, 
    na memória os dados são armazenados 
    linearmente. 
    int mat[5][5];
    0,0     1,0      2,0    3,0     4,0     4,4        
*/

/*
    Pode-se então percorrer as várias 
    dimensões do array como se existisse 
    apenas uma dimensão. 
*/

#include <stdio.h>

int main(){
    int mat[2][2] = {{1,2},{3,4}};
    int i,j;

    // USANDO ARRAY
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            printf("%d\n", mat[i][j]);
        }
    }

    // USANDO PONTEIRO
    int *p = &mat[0][0]; // int *p = mat;
    for (i = 0; i < 4; i++){
        printf("%d\n", *(p+i));
    }

    return 0;
}