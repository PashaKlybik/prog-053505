//
//  main.c
//  3.2.2
//
//  Created by Дима Гузерчук on 23.03.21.
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>
void add_zero_string(int** A, int ** A_0, int height, int height_0, int width){
    int line_with_biggest = 0;
    for (int i = 0; i < height_0; i++) {
        for (int j = 0; j < width; j++) {
            if (i <= line_with_biggest) {
                A_0[i][j] = A[i][j];
            }else if(i == line_with_biggest+1){
                A_0[i][j] = 0;
            }else{
                A_0[i][j] = A[i-1][j];
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int height;
    printf("Enter size of array");
    printf("\n");
    scanf("%d",&height);
    int width = height-1, line_with_biggest = 0, temp = -1,height_0 = height+1;
    int **A = (int **)malloc(height*sizeof(int *));
    for(int i = 0; i < height_0; i++) {
        A[i] = (int *)malloc(width*sizeof(int));
    }
    int **A_0 = (int **)malloc(height_0*sizeof(int *));
    for(int i = 0; i < height_0; i++) {
        A_0[i] = (int *)malloc(width*sizeof(int));
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            A[i][j] = rand()%4;
            if (A[i][j] > temp) {
                line_with_biggest = i;
                temp = A[i][j];
            }
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
    //printf("%d",line_with_biggest);
    add_zero_string(A,A_0,height,height_0,width);
    printf("\nMatrix with zero string:\n");
    for (int i = 0; i < height_0; i++) {
        for (int j = 0; j < width; j++) {
            if (i <= line_with_biggest) {
                A_0[i][j] = A[i][j];
            }else if(i == line_with_biggest+1){
                A_0[i][j] = 0;
            }else{
                A_0[i][j] = A[i-1][j];
            }
        }
    }
    for (int i = 0; i < height_0; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d\t",A_0[i][j]);
        }
        printf("\n");
    }
    printf("\n\nProgram reverse matrix from main diagonal:\n");
    //reverse main diag
    int size = 3, ARRAY[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ARRAY[i][j] = rand()%4;
            printf("%d\t",ARRAY[i][j]);
        }
        printf("\n");
    }
    temp = 0;
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            temp = ARRAY[i][j];
            ARRAY[i][j]= ARRAY[j][i];
            ARRAY[j][i] = temp;
        }
        printf("\n");
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t",ARRAY[i][j]);
        }
        printf("\n");
    }printf("\n\nProgram reverse matrix from secondary diagonal:\n");
    //reverse main diag
    int ARRAY_[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ARRAY_[i][j] = rand()%4;
            printf("%d\t",ARRAY_[i][j]);
        }
        printf("\n");
    }
    temp = 0;
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-(i+1); j++) {
            temp = ARRAY_[i][j];
            ARRAY_[i][j]= ARRAY_[size-j-1][size-i-1];
            ARRAY_[size-j-1][size-i-1] = temp;
        }
        printf("\n");
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t",ARRAY_[i][j]);
        }
        printf("\n");
    }
    
    
    for(int i = 0; i < height; i++) {
        free(A[i]);
    }
    free(A);
    for(int i = 0; i < height_0; i++) {
        free(A_0[i]);
    }
    free(A_0);
    return 0;
}
