#ifndef HH_H
#define HH_H


#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#define BOARD_WIDTH 800
#define BOARD_HEIGHT 800
#define BOARD_SIZE 100

// this stores the name of the clicked piece;
struct pieceTrack{
  int x;
  int y;
  std::string name;
};

struct Piece{
    sf::Sprite S;
    std::string Ttype;
};
struct boardC{
  Piece piece;
};

  std::vector<std::string> whitepieces = {"pawnW","rookW","kingW","knightW","queenW","bishopW"};
  std::vector<std::string> blackpieces = {"pawnB","rookB","kingB","knightB","queenB","bishopB"};
  boardC board2D[8][8];
  pieceTrack selectedP ={0,0,""};

  bool blackRole = 0;
  bool whiteRole = 1;


#endif