cmake_minimum_required(VERSION 3.26)
project(JamboSchool)

set(CMAKE_CXX_STANDARD 17)

add_executable(JamboSchool main.cpp
        ChessPiece.cpp
        ChessPiece.h
        ChessBoard.cpp
        ChessBoard.h
)
