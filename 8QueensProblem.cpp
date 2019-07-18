#include<iostream>
#include<conio.h>

using namespace std;

/*
 * Only work for Queen if true->Its Queen and id false->Nothing
 * Board() - create empty board
 * Board(int size) - construct a board of length size
 * ~Board() - destructor
 * void createBoard(int size) - construct a board of length size
 * bool isSafe(int row, int column) - true if queen can be safely placed here
 * void place(int row, int column) - place queen here
 * void remove(int row, int column) - remove queen from here
 * string toString() - text display of board
 * void getFirstDiagL(int &row, int& column)(It is only zero base) - Gives first column and row of that diagonal at top left
 * void getFirstDiagR(int &row, int& column)(It is only zero base) - Gives first column and row of that diagonal at top right
 * bool diagonal(int row, int columns)(It is only zero base) - true if queen can be safely diagonally
 */
// Represent chess board
class Board {
public:
    Board() {
        _board = nullptr;
        _size = 0;
    }

    Board(int size) { // () for zeroing all values
        _board = new bool*[size];
        for (int i = 0; i < size; i++)
            _board[i] = new bool[size]();
        _size = size;
    }

    ~Board() {
        delete[] _board;
    }

    void creatBoard(int size) {
        _board = new bool*[size];
        for (int i = 0; i < size; i++)
            _board[i] = new bool[size]();
        _size = size;
    }

    bool isSafe(int row, int column) {
        // Column
        for (int i = 0; i < _size; i++)
            if (_board[i][column - 1])
                return false;

        // Row
        for (int i = 0; i < _size; i++)
            if (_board[row - 1][i])
                return false;

        // Diagonal
        return diagonal(row - 1, column - 1);
    }

    void place(int row, int column) {
        if ((row > 0 && row <= 8)&&(column > 0 && column <= 8))
            _board[row - 1][column - 1] = true;
        else
            throw ":-(";
    }

    void remove(int row, int column) {
        if ((row > 0 && row <= 8)&&(column > 0 && column <= 8))
            _board[row - 1][column - 1] = false;
        else
            throw ":-(";
    }

    string toString() {
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                if (_board[i][j] == false)
                    cout << " - ";
                else
                    cout << " Q ";
            }
            cout << endl << endl;
        }
        cout << "-----------------------------------------------";
        cout << endl;
    }

private:
    bool** _board;
    int _size;
    void getFirstDiagL(int row, int column,int& rows, int& columns) {
        while (row != 0 && column != 0) {
            row -= 1;
            column -= 1;
        }
        rows = row;
        columns = column;
    }

    void getFirstDiagR(int row, int column,int& rows, int& columns) {
        while (row != 0 && column != 7) {
            row -= 1;
            column += 1;
        }
        rows = row;
        columns = column;
    }

    bool diagonal(int row, int columns) {
        int fcol, frow;
        getFirstDiagL(row, columns, frow, fcol);
        while (frow != 8 && fcol != 8) {
            if (_board[frow][fcol])
                return false;
            frow += 1;
            fcol += 1;
        }

        getFirstDiagR(row, columns, frow, fcol);
        while (frow != 8 && fcol != -1) {
            if (_board[frow][fcol])
                return false;
            frow += 1;
            fcol -= 1;
        }
        return true;
    }
};



/*
 * Return type : void
 * Args : Takes board and col
 * Working : Find all possible board that solve 8 Queen Problem
 */
void Queen(Board&);
void Queen(Board&, int); // This is helper function

int main() {
    Board board(8);
    Queen(board);
}

void Queen(Board& board) {
    Queen(board, 1);
}

void Queen(Board& board, int col) {
    if (col == 9)
        board.toString();
    else {
        for (int r = 1; r <=8; r++) {
            if(board.isSafe(r, col)) {
                // choose
                board.place(r, col);
                // Explore
                Queen(board, col + 1);
                //Un-choose
                board.remove(r, col);
            }
        }
    }
}

