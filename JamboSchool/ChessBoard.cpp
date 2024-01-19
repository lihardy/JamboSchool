//
// Created by 詹成波 on 2023/12/27.
//

#include "ChessBoard.h"
#include "iostream"


ChessBoard::ChessBoard(int size) : size(size) {
    board.resize(size, std::vector<ChessPiece*>(size, nullptr));
}

ChessBoard::~ChessBoard() {
    for (auto& row : board) {
        for (auto& piece : row) {
            delete piece;
        }
    }
}

void ChessBoard::placePiece(int x, int y, ChessPiece* piece) {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        delete board[x][y]; // 删除旧的棋子
        board[x][y] = piece; // 放置新的棋子
    }
}

ChessPiece* ChessBoard::getPiece(int x, int y) const {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        return board[x][y];
    }
    return nullptr;
}

void ChessBoard::printBoard() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == nullptr) {
                std::cout << ". ";
            } else {
                std::cout << board[i][j]->getInfo() << " ";
            }
        }
        std::cout << std::endl;
    }
}

bool ChessBoard::isSafe(int row, int col) const {
    for (int i = 0; i < row; ++i) {
        // 检查列
        if (board[i][col] != nullptr)
            return false;

        // 检查对角线
        int diagLeft = col - row + i;
        int diagRight = col + row - i;
        if (diagLeft >= 0 && board[i][diagLeft] != nullptr)
            return false;
        if (diagRight < size && board[i][diagRight] != nullptr)
            return false;
    }
    return true;
}