
#include <iostream>
using namespace std;
const int ROWS = 3;
const int COLUMNS = 4;



int main()
{
    int board[ROWS][COLUMNS] = { {1, 2, 3, 4}, { 5, 6, 7, 8 }, { 9 , 2 , 5 , 8} };
    int currentTotal = 0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << board[i][j] << " ";

        }
        cout << endl;
    }


    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {


            if (board[i][j] % 2 == 0) {
                currentTotal = currentTotal + board[i][j];
                cout << board[i][j] << " Se encuentra en: " << i << " " << j << endl;
            }

        }

    }


    cout << "La suma total de todos los pares es: " << currentTotal;
}

