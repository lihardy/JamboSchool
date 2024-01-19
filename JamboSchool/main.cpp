#include <iostream>
#include <vector>
#include "ChessBoard.h"

using namespace std;

#define N 8

// 棋盘，用于记录皇后的位置
vector<vector<int>> board(N, vector<int>(N, 0));

// struct 声明棋盘
struct ChessBoard_struct {
    int size ; //声明棋盘
    vector<vector<ChessPiece*>> board; // 棋盘格，存储指向ChessPiece的指针
};

// 检查当前位置是否安全
bool isSafe(int row, int col) {
    int i, j;

    // 检查这一列是否安全
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // 检查左上角斜线是否安全
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // 检查右上角斜线是否安全
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// 递归函数，用于放置皇后
bool solveNQUtil(int row) {
    // 如果所有皇后都放置好了
    if (row >= N)
        return true;

    // 尝试在当前行的每一列中放置皇后
    for (int i = 0; i < N; i++) {
        // 检查是否安全放置皇后
        if (isSafe(row, i)) {
            // 在board[row][i]放置皇后
            board[row][i] = 1;

            // 递归到下一行
            if (solveNQUtil(row + 1))
                return true;

            // 如果放置这个皇后导致后续没有解，则回溯
            board[row][i] = 0; // 回溯
        }
    }

    // 如果当前行无法放置皇后，则无解
    return false;
}

// 解决八皇后问题的函数
bool solveNQ() {
    if (!solveNQUtil(0)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    // 打印解决方案
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    return true;
}

bool solveNQueens(ChessBoard& board, int row) {
    if (row >= board.getSize()) {
        return true; // 解决了问题
    }

    for (int col = 0; col < board.getSize(); ++col) {
        if (board.isSafe(row, col)) {
            board.placePiece(row, col, new Queen(WHITE, row, col));

            if (solveNQueens(board, row + 1)) {
                return true;
            }

            // 回溯：移除皇后
            board.placePiece(row, col, nullptr);
        }
    }

    return false;
}

int main() {
    ChessBoard board(8); // 创建一个8x8的棋盘
    if (solveNQueens(board, 0)) {
        board.printBoard(); // 打印解决方案
    } else {
        std::cout << "No solution found" << std::endl;
    }
    return 0;
}

// 主函数
//int main() {
//    solveNQ();
//    return 0;
//}
