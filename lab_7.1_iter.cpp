#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** r, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** r, const int rowCount, const int colCount);
void Sort(int** r, const int rowCount, const int colCount);
void Change(int** r, const int row1, const int row2, const int colCount);
void Calc(int** r, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    const int Low = 4;
    const int High = 51;

    const int rowCount = 8;
    const int colCount = 5;

    int** r = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        r[i] = new int[colCount];

    Create(r, rowCount, colCount, Low, High);
    cout << "Start matrix^" << endl;
    Print(r, rowCount, colCount);
    Sort(r, rowCount, colCount);
    cout << "Sorted matrix:" << endl;
    Print(r, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(r, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    cout << "Modified matrix:" << endl;
    Print(r, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] r[i];
    delete[] r;

    return 0;
}

void Create(int** r, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            r[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** r, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << r[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int** r, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < rowCount - 1; i0++)
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
            if ((r[i1][0] >  r[i1 + 1][0] )
                ||
                (r[i1][0] == r[i1 + 1][0] && 
                 r[i1][1] <  r[i1 + 1][1] )
                ||
                (r[i1][0] == r[i1 + 1][0] &&
                 r[i1][1] == r[i1 + 1][1] &&
                 r[i1][2] <  r[i1 + 1][2] ))
                Change(r, i1, i1 + 1, colCount);
}

void Change(int** r, const int row1, const int row2, const int colCount)
{
    int tmp;
    for (int j = 0; j < colCount; j++)
    {
        tmp = r[row1][j];
        r[row1][j] = r[row2][j];
        r[row2][j] = tmp;
    }
}

void Calc(int** r, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (!(r[i][j] % 2 == 0) && !(i % 3 == 0 && j % 3 == 0))
            {
                S += r[i][j];
                k++;
                r[i][j] = 0;
            }
}
