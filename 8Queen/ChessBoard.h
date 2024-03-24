//
// Created by 詹成波 on 2023/12/27.
//

#ifndef JAMBOSCHOOL_CHESSBOARD_H
#define JAMBOSCHOOL_CHESSBOARD_H

#include <vector>
#include "ChessPiece.h"

class ChessBoard {
private:
    int size; // 棋盘的大小
    std::vector<std::vector<ChessPiece*>> board; // 棋盘格，存储指向ChessPiece的指针

public:
    ChessBoard(int size);
    ~ChessBoard();

    void placePiece(int x, int y, ChessPiece* piece); // 在棋盘上放置一个棋子
    ChessPiece* getPiece(int x, int y) const; // 获取指定位置的棋子
    void printBoard() const; // 打印棋盘
    bool isSafe(int row, int col) const; // 检查当前位置是否安全
    int getSize() const { return size; } // 获取棋盘大小
};

#endif //JAMBOSCHOOL_CHESSBOARD_H
