
#include <iostream>
#include "p0_starter.h"

using namespace scudb;
using namespace std;

int main(int argc, char** argv)
{
    RowMatrix<int> matA {4,4};
    RowMatrix<int> matB {4,4};

    vector<int> vec;
    for (int i = 0; i < 16; ++i)
    {
        vec.push_back(i);
    }

    matA.FillFrom(vec);
    matB.FillFrom(vec);

    cout << "Mat A" << endl;
    for (int i = 0; i < matA.GetRowCount(); ++i)
    {
        for (int j = 0; j < matA.GetColumnCount(); ++j)
        {
            cout << matA.GetElement(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Mat B" << endl;
    for (int i = 0; i < matB.GetRowCount(); ++i)
    {
        for (int j = 0; j < matB.GetColumnCount(); ++j)
        {
            cout << matB.GetElement(i, j) << " ";
        }
        cout << endl;
    }

    RowMatrixOperations<int> operation;

    unique_ptr<RowMatrix<int>> result1(new RowMatrix<int> {4, 4});
    result1 = operation.Add(&matA, &matB);
    cout << "Add Result" << endl;
    for (int i = 0; i < result1->GetRowCount(); ++i)
    {
        for (int j = 0; j < result1->GetColumnCount(); ++j)
        {
            cout << result1->GetElement(i, j) << " ";
        }
        cout << endl;
    }

    unique_ptr<RowMatrix<int>> result2(new RowMatrix<int> {4, 4});
    result2 = operation.Multiply(&matA, &matB);
    cout << "Mul Result" << endl;
    for (int i = 0; i < result2->GetRowCount(); ++i)
    {
        for (int j = 0; j < result2->GetColumnCount(); ++j)
        {
            cout << result2->GetElement(i, j) << " ";
        }
        cout << endl;
    }

    unique_ptr<RowMatrix<int>> result3(new RowMatrix<int> {4, 4});
    result3 = operation.GEMM(&matA, &matB, &matA);
    cout << "GEMM Result" << endl;
    for (int i = 0; i < result3->GetRowCount(); ++i)
    {
        for (int j = 0; j < result3->GetColumnCount(); ++j)
        {
            cout << result3->GetElement(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}
