#include <iostream>

void printMatrix(int **matrix, int size);
void displayUpperTriangular(int **matrix, int size);
void displayAboveBelowDiagonal(int **matrix, int size);
void deleteMatrix(int **matrix, int size);

int main()
{
    int n, i, j;
    std::cout << "Enter the size of the square matrix: ";
    std::cin >> n;

    int **mat = new int*[n];
    for (i=0; i<n; ++i)
    {
        mat[i] = new int[n];
    }
    
    std::cout << "Enter matrix elements:" << std::endl;
    for (i=0; i<n; ++i)
    {
        for (j=0; j<n; ++j)
        {
            std::cin >> mat[i][j];
        }
    }
    
    std::cout << "Matrix:" << std::endl;
    for (i=0; i<n; ++i)
    {
        for (j=0; j<n; ++j)
        {
            std::cout << mat[i][j] << " ";
        }
    }

    displayUpperTriangular(mat, n);
    displayAboveBelowDiagonal(mat, n);

    for (i=0; i<n; ++i)
    {
        delete[] mat[i];
    }
    delete[] mat;

    return 0;
}

void displayUpperTriangular(int **matrix, int size)
{
    std::cout << "Upper Triangular Matrix:" << std::endl;
    for (int i=0; i<size; ++i)
    {
        for (int j=0; j<size; ++j)
        {
            if (j >= i)
            {
                std::cout << matrix[i][j] << " ";
            }
            else
            {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}

void displayAboveBelowDiagonal(int **matrix, int size)
{
    std::cout << "Elements above and below the main diagonal:" << std::endl;
    for (int i=0; i<size; ++i)
    {
        for (int j=0; j<size; ++j)
        {
            if (j>i)
            {
                std::cout << matrix[i][j] << " ";
            }
            else if (j<i)
            {
                std::cout << matrix[i][j] << " ";
            }else
            {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}
