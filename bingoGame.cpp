#include <bits/stdc++.h>
using namespace std;
void manual_shuffle(vector<int> &arr, int t)
{
    int n = arr.size();
    srand(time(0));
    if (t == 0)
    {
        for (int i = n - 1; i > 0; i--)
        {
            int j = rand() % (i + 1);
            swap(arr[i], arr[j]);
        }
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            int j = rand() % (i + 1);
            swap(arr[i], arr[j]);
        }
    }
}

void AddNumbers(vector<int> &numbers)
{
    for (int i = 0; i < 9; i++)
    {
        numbers.push_back(i);
    }
}

void AddNumbersInMatrix(vector<vector<int>> &board, vector<int> number)
{
    int idx = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = number[idx++];
        }
    }
}

void printBoard(vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

pair<int, int> checkBoard(vector<vector<int>> &board, int num)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == num)
            {
                board[i][j] = -1;
                return make_pair(i, j);
            }
        }
    }

    return make_pair(-1, -1);
}

bool checkWinner(vector<vector<int>> &board, pair<int, int> pr)
{
    int i = pr.first;
    int j = pr.second;
    if (i == 0 && j == 0 && ((board[i][j + 1] == -1 && board[i][j + 2] == -1) || (board[i + 1][j] == -1 && board[i + 2][j] == -1) || (board[i + 1][j + 1] == -1 && board[i + 2][j + 2] == -1)))
        return true;
    else if (i == 0 && j == 1 && ((board[i][j + 1] == -1 && board[i][j - 1] == -1) || (board[i + 1][j] == -1 && board[i + 2][j] == -1)))
        return true;
    else if (i == 0 && j == 2 && ((board[i][j - 1] == -1 && board[i][j - 2] == -1) || (board[i + 1][j] == -1 && board[i + 2][j] == -1) || (board[i + 1][j + 1] == -1 && board[i + 2][j + 2] == -1)))
        return true;
    else if (i == 1 && j == 0 && ((board[i - 1][j] == -1 && board[i + 1][j] == -1) || (board[i][j + 1] == -1 && board[i][j + 2] == -1)))
        return true;
    else if (i == 1 && j == 1 && ((board[i - 1][j] == -1 && board[i + 1][j] == -1) || (board[i][j + 1] == -1 && board[i][j - 1] == -1)))
        return true;
    else if (i == 1 && j == 2 && ((board[i - 1][j] == -1 && board[i + 1][j] == -1) || (board[i][j - 1] == -1 && board[i][j - 2] == -1)))
        return true;
    else if (i == 2 && j == 0 && ((board[i - 1][j] == -1 && board[i - 2][j] == -1) || (board[i][j + 1] == -1 && board[i][j + 2] == -1) || (board[i - 1][j + 1] == -1 && board[i - 2][j + 2] == -1)))
        return true;
    else if (i == 2 && j == 1 && ((board[i - 1][j] == -1 && board[i - 2][j] == -1) || (board[i][j + 1] == -1 && board[i][j - 1] == -1)))
        return true;
    else if (i == 2 && j == 2 && ((board[i - 1][j] == -1 && board[i - 2][j] == -1) || (board[i + 1][j] == -1 && board[i + 2][j] == -1) || (board[i][j - 1] == -1 && board[i][j - 2] == -1)))
        return true;

    return false;
}

string bingoGame(string player1, string player2, vector<vector<int>> board1, vector<vector<int>> board2)
{
    while (true)
    {
        cin.ignore();
        cout << player1 << "! Please press Enter to generate a number:";
        cin.get();
        int num1 = rand() % 9;
        cout << "Generated number is: " << num1 << endl;
        cout << player2 << "! Please press Enter to generate a number:";
        cin.get();
        int num2 = rand() % 9;
        cout << "Generated number is: " << num2 << endl;
        pair<int, int> indices1;
        while (make_pair(-1, -1) != indices1)
        {
            num1 = rand() % 9;
            indices1 = checkBoard(board1, num1);
        }
        cout << "Player1 Board" << endl;
        cout << "------------------------------------" << endl;
        printBoard(board1);
        cout << "------------------------------------" << endl;
        if (checkWinner(board1, indices1))
        {
            return player1;
        }
        pair<int, int> indices2;
        while (make_pair(-1, -1) != indices2)
        {
            num2 = rand() % 9;
            indices2 = checkBoard(board2, num2);
        }
        cout << "Player2 Board" << endl;
        cout << "------------------------------------" << endl;
        printBoard(board2);
        cout << "------------------------------------" << endl;
        if (checkWinner(board2, indices2))
        {
            return player2;
        }
    }
    return "";
}

int main()
{
    vector<vector<int>> board1(3, vector<int>(3, 0));
    vector<vector<int>> board2(3, vector<int>(3, 0));
    vector<int> numbers1;
    AddNumbers(numbers1);
    manual_shuffle(numbers1, 0);
    vector<int> numbers2;
    AddNumbers(numbers2);
    manual_shuffle(numbers2, 1);
    AddNumbersInMatrix(board1, numbers1);
    AddNumbersInMatrix(board2, numbers2);
    string player1, player2;
    cout << "Enter Player1 Name: ";
    cin >> player1;
    cout << "Enter Player2 Name: ";
    cin >> player2;
    if (player1 == bingoGame(player1, player2, board1, board2))
    {
        cout << player1 << " !Congrats,You are the Winner.";
    }
    else
    {
        cout << player2 << " !Congrats,You are the Winner.";
    }
    return 0;
}
