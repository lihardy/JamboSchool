//
// Created by 詹成波 on 2023/12/27.
//

#ifndef JAMBOSCHOOL_CHESSPIECE_H
#define JAMBOSCHOOL_CHESSPIECE_H


#include <string>

// 枚举类型，表示棋子颜色
enum Color { WHITE, BLACK };

// 基类：ChessPiece
class ChessPiece {
protected:
    Color color; // 棋子颜色
    std::string name; // 棋子名称
    int x, y; // 棋子在棋盘上的位置

public:
    ChessPiece(Color color, const std::string& name, int x, int y);
    virtual void move(int newX, int newY) = 0; // 抽象移动方法
    std::string getInfo() const; // 获取棋子信息
    void flipColor(); // 翻转棋子颜色
    virtual ~ChessPiece(); // 虚析构函数
};

// Pawn子类
class Pawn : public ChessPiece {
public:

    // Pawn 不能反转颜色，所以不需要重写flipColor方法
    Pawn(Color color, int x, int y);
    void move(int newX, int newY) override; // 实现Pawn的移动逻辑
};

// Queen子类
class Queen : public ChessPiece {
public:
    Queen(Color color, int x, int y);
    void move(int newX, int newY) override;
};

#endif //JAMBOSCHOOL_CHESSPIECE_H
