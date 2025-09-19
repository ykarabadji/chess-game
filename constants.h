#ifndef HH_H
#define HH_H


#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
static std::vector<sf::RectangleShape> board;
static int board_control_color = 0;//it controls and manages board color
#define BOARD_WIDTH 800
#define BOARD_HEIGHT 800
#define BOARD_SIZE 100
#define NSQUARES 7

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
  std::vector<sf::Vector2i> pawnOldPos;
  sf::Vector2i kingWPos;
  sf::Vector2i kingBPos;
  boardC board2D[8][8];
  pieceTrack selectedP ={0,0,""};

  bool blackRole = 0;
  bool whiteRole = 1;


#endif
