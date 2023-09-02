#include <iostream>
#include <cstdlib>

using namespace std;

struct Element
{
    int row, col, value;
};

int main()
{
    int m, n, non_zero;

    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;
    cout << "Enter the number of non-zero elements: ";
    cin >> non_zero;

    Element* thisSparseMatrix = (Element*)malloc(non_zero*sizeof(Element));
    Element* this3Tuple = (Element*)malloc(non_zero*sizeof(Element));

    cout << "Enter the 3-tuple matrix: " << std::endl;
    for (int i = 0; i < non_zero; i++)
    {
        cin >> thisSparseMatrix[i].row >> thisSparseMatrix[i].col >> thisSparseMatrix[i].value;
    }

    int row = 0, col = 0;
    for (int i = 0; i < non_zero; i++)
    {
        row = max(row, thisSparseMatrix[i].row);
        col = max(col, thisSparseMatrix[i].col);
    }
    
    for (int i = 0; i < non_zero; i++)
    {
        this3Tuple[i].row = thisSparseMatrix[i].col;
        this3Tuple[i].col = thisSparseMatrix[i].row;
        this3Tuple[i].value = thisSparseMatrix[i].value;
    }

    cout << "Transposed sparse matrix: " << std::endl;
    for (int i = 0; i < non_zero; i++)
    {
        cout << this3Tuple[i].row << " " << this3Tuple[i].col << " " << this3Tuple[i].value << endl;
    }

    free(thisSparseMatrix);
    free(this3Tuple);

    return 0;
}

