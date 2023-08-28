#include <iostream>

const int MAX_SIZE = 100;

void display3Tuple(int array[][MAX_SIZE], int rows, int columns);

int main()
{
    int r, c, i, j;

    std::cout << "Enter size of the sparse matrix:\n(no of rows followed by no of columns:)" << std::endl;
    std::cin >> r >> c;

    int mat[MAX_SIZE][MAX_SIZE];

    std::cout << "Enter the elements of the Sparse Matrix now: " << std::endl;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            std::cin >> mat[i][j];
        }
    }

    display3Tuple(mat, r, c);

    return 0;
}

void display3Tuple(int matrix[][MAX_SIZE], int rows, int columns)
{
    int tup3_mat[MAX_SIZE * MAX_SIZE][3];
    int i, j, row_count=1, col_count=0, nonzero = 0;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            if (matrix[i][j] != 0)
            {
                tup3_mat[row_count][0] = i;
                tup3_mat[row_count][1] = j;
                tup3_mat[row_count][2] = matrix[i][j];

                nonzero++;
                ++row_count;
                ++col_count;
            }
        }
    }

    tup3_mat[0][0] = row_count - 1;
    tup3_mat[0][1] = col_count + 1;
    tup3_mat[0][2] = nonzero;

    std::cout << "Three Tuple Form: " << std::endl << std::endl;
    for (i = 0; i < row_count; i++)
    {
        for (j = 0; j < 3; j++)
        {
            std::cout << tup3_mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
