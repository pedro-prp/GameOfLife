#include <stdio.h>
#include <stdlib.h>

typedef enum boolean {false, true} bool;

void drawField(int matrix[50][50]){

    bool newl = true;

    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 50; j++){
            if(matrix[i][j] == 1){
                printf("@");
                // newl = false;
            }else{
                printf("#");
            }
        }
        if(newl)
            printf("\n");
        newl = true;
    }
}

int countNeigh(int **matrix, int a, int b){
    int count = 0;
    for(int i = (a-1); i < (a+1); i ++){
        for(int j = (b-1); j < (b+1); j ++){
            if(j != b && i != a && matrix[i][j] == 1){
                count++;
            }
            // printf("y");
        }
        // printf("x");
    }

    return count;
}

void createLifes(int **matrix){

    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 50; j++){
            if(i != 0 && i != 49 && j != 0 && j != 49){
                if(matrix[i][j] != 1){
                    int neigh = countNeigh(matrix, i, j);
                    if(neigh == 3){
                        matrix[i][j] = 1;
                    }
                }             
            }
        }
    }
}


int main(){

    int **matrix = calloc(50, sizeof(int*));
    for (int i=0; i<50; i++){
        matrix[i] = calloc(50, sizeof(int));
    }

    matrix[24][24] = 1;
    matrix[25][24] = 1;
    matrix[26][24] = 1;
    


    createLifes(matrix);
    drawField(matrix);

    return 0;
}