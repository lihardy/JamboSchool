//
// Created by 詹成波 on 2023/12/27.
//
#include "iostream"
#include "ChessPiece.h"

// 基类构造函数
ChessPiece::ChessPiece(Color color, const std::string& name, int x, int y)
        : color(color), name(name), x(x), y(y) {}

// 基类虚析构函数
ChessPiece::~ChessPiece() {}

// 获取棋子信息
std::string ChessPiece::getInfo() const {
    return (color == WHITE ? "White " : "Black ") + name + " at " + std::to_string(x) + ", " + std::to_string(y);
}

// Pawn类的构造函数
Pawn::Pawn(Color color, int x, int y) : ChessPiece(color, "Pawn", x, y) {}

// Pawn类的移动方法
void Pawn::move(int newX, int newY) {
    // 这里可以加入逻辑来检查移动是否有效
    x = newX;
    y = newY;
    std::cout << "Pawn moved to " << x << ", " << y << std::endl;
}

// Queen类的构造函数
Queen::Queen(Color color, int x, int y) : ChessPiece(color, "Queen", x, y) {}

// Queen类的移动方法
void Queen::move(int newX, int newY) {
    // 这里可以加入逻辑来检查移动是否有效
    // 皇后可以移动到棋盘上的任何位置，只要不是被其他棋子阻挡
    x = newX;
    y = newY;
    std::cout << "Queen moved to " << x << ", " << y << std::endl;
}
