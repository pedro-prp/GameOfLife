#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size = 20;

void drawField(int **matrix){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
           if(matrix[i][j] == 1)
                printf(".");
            else
                printf(" ");
        }
        printf("\n");
        
    }
}

int countNeigh(int **matrix, int a, int b){
    int count = 0;
    for(int i = (a-1); i < (a+2); i ++){
        for(int j = (b-1); j < (b+2); j ++){
            if(matrix[i][j] == 1){
                count++;
            }
        }
    }

    return count;
}

int ** createLifes(int **matrix){

    int **new_matrix = calloc(size, sizeof(int *));
    for(int i = 0; i < size; i++){
        new_matrix[i] = calloc(size, sizeof(int));
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i != 0 && i != (size-1) && j != 0 && j != (size-1)){
                if(matrix[i][j] != 1){
                    int neigh = countNeigh(matrix, i, j);
                    
                    if(neigh == 3){
                        new_matrix[i][j] = 1;
                    }
                }
                else{
                    int neigh = countNeigh(matrix, i, j);
                    
                    if(neigh == 3){
                        new_matrix[i][j] = 1;
                    }
                }             
            }
        }
    }

    return new_matrix;
}

void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}


int main(){

    int **matrix = calloc(size, sizeof(int*));
    for (int i=0; i<size; i++){
        matrix[i] = calloc(size, sizeof(int));
    }

    // matrix[5][5] = 1;
    // matrix[6][5] = 1;
    // matrix[6][7] = 1;
    // matrix[7][5] = 1;
    // matrix[7][6] = 1;
    
    matrix[5][5] = 1;
    matrix[6][5] = 1;
    matrix[7][5] = 1;
    matrix[3][7] = 1;
    matrix[2][7] = 1;
    matrix[1][7] = 1;

    // drawField(matrix);
    

    while(1){

        drawField(matrix);
        matrix = createLifes(matrix);

        usleep(100000);
        clearScreen();
    }

    return 0;
}