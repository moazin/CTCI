/*
    Rotating an Image that is given as a two dimensional array in C. 
    It's easy to do by using Linear Algebra's rotational matrix. 
    Rotation matrix only works on coordinates based on a cartesian system and the image must of be centered on it. Coordinates of the form (-1, 1)
    Thus we must convert the addresses in our two-dimensional format (0,0) (0,1) to such addresses. 
    The function `transformPoint` does exactly this.
    The funciton `reverseTransformPoint` does the opposite.
    We first transform the coordinates then call the function `rotatePoint` to rotate it by using the rotation matrix
    The function `printMatrix` is used to print the whole array
    The function `createMatrix` is used to allocate the array on runtime.
    The function `freeMatrix` is used to free the memory previously allocated
    The function `rotateMatrix` just calls `rotatePoint` on each point in the matrix
*/

#include <stdio.h>
#include <stdlib.h>

void transformPoint(int r, int c, int size, int *x, int *y);
void reverseTransformPoint(int X, int Y, int size, int *r, int *c);
void rotatePoint(int x, int y, int size, int *X, int *Y);
void printMatrix(int **matrix, int size);
int** createMatrix(int N);
void freeMatrix(int **matrix, int size);
void rotateMatrix(int **matrix, int **newMatrix, int size);

int main(void)
{
    printf("Size: ");
    int size;
    scanf("%d", &size);
    int** matrix = createMatrix(size);
    int** newMatrix = createMatrix(size);
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
           int tmp;
           printf("(%d, %d) <-- ", i+1, j+1); 
           scanf("%d", &tmp);
           matrix[i][j] = tmp;
        }
        printf("\n");
    }
    printf("------- Your Matrix ----------\n");
    printMatrix(matrix, size);
    printf("------- Rotated Matrix -------\n");
    rotateMatrix(matrix, newMatrix, size);
    printMatrix(newMatrix, size);
    return 0;
}

void rotateMatrix(int **matrix, int **newMatrix, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
           int r, c;
           rotatePoint(i, j, size, &r, &c);
           newMatrix[r][c] = matrix[i][j];
        }
    }
}

int** createMatrix(int N)
{
    int **matrix = (int**) malloc(N * sizeof(int*));
    for(int i = 0; i < N; i++)
    {  
        int *tmp = (int*) malloc(N * sizeof(int));
        *(matrix+i) = tmp;
    }
    return matrix;
}

void freeMatrix(int **matrix, int N)
{
    for(int i = 0; i < N; i++)
    {
        free(*(matrix+i));
    }
}

void printMatrix(int** matrix, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d, ", *(*(matrix+i)+j));
        }
        printf("\n");
    }
}

void rotatePoint(int r, int c, int size, int *R, int *C)
{
    int x, y, tmpX, tmpY;
    transformPoint(r, c, size, &x, &y);
    tmpX = x;
    x = -1 * y;
    y = tmpX;
    reverseTransformPoint(x, y, size, R, C);
}

void transformPoint(int r, int c, int size, int *x, int *y)
{
    float pivot = ((int)size-1.0) / 2.0;
    int isEven = size%2 == 0;
    float X, Y;
    X = ((float)c - pivot);
    Y = ((float)r - pivot);
    if (isEven){
       if (X < 0)
            X -= 0.5;
       else if(X > 0)
            X += 0.5;
       if (Y < 0)
            Y -= 0.5;
       else if(Y > 0)
            Y += 0.5;
    }
    *x = X;
    *y = (-1)*((int)Y);
}

void reverseTransformPoint(int X, int Y, int size, int *r, int *c)
{
    float pivot = ((int)size-1.0) / 2.0;
    int isEven = size%2 == 0;
    float x, y;
    x = (float)X;
    y = (float)Y;
    y = y * -1;
    if (isEven){
       if (x < 0)
            x += 0.5;
       else if(x > 0)
            x -= 0.5;
       if (y < 0)
            y += 0.5;
       else if(y > 0)
            y -= 0.5;
    }
    *r = y + pivot;
    *c = x + pivot;
}
