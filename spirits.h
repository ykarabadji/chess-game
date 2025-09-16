#ifndef HI_H
#define HI_H 

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

  
    sf::Texture rookW;
    sf::Texture rookB;
    sf::Texture pawnW;
    sf::Texture pawnB;
    sf::Texture kingW;
    sf::Texture kingB;
    sf::Texture bishopW;
    sf::Texture bishopB;
    sf::Texture queenW;
    sf::Texture queenB;
    sf::Texture knightW;
    sf::Texture knightB;

    std::string blackrook = "pieces-png/black-rook.png";
    std::string whiterook = "pieces-png/white-rook.png";
    std::string blackpawn = "pieces-png/black-pawn.png";
    std::string whitepawn = "pieces-png/white-pawn.png";
    std::string blackking = "pieces-png/black-king.png";
    std::string whiteking = "pieces-png/white-king.png";
    std::string blackbishop ="pieces-png/black-bishop.png" ;
    std::string whitebishop = "pieces-png/white-bishop.png";
    std::string whitequeen = "pieces-png/white-queen.png";
    std::string blackqueen = "pieces-png/black-queen.png";
    std::string blackknight = "pieces-png/black-knight.png";
    std::string whiteknight  = "pieces-png/white-knight.png";



        
   

                

 void initPieces() {
    
    if (!rookW.loadFromFile(whiterook)){
        std::cout << " we are dommed ";
        return ;
    };
    rookB.loadFromFile(blackrook);
    pawnW.loadFromFile(whitepawn);
    pawnB.loadFromFile(blackpawn);
    kingW.loadFromFile(whiteking);
    kingB.loadFromFile(blackking);
    bishopW.loadFromFile(whitebishop);
    bishopB.loadFromFile(blackbishop);
    queenW.loadFromFile(whitequeen);
    queenB.loadFromFile(blackqueen);
    knightW.loadFromFile(whiteknight);
    knightB.loadFromFile(blackknight);


    // --- Black major pieces (row 0) ---
    board2D[0][0].piece.S.setTexture(rookB);
    board2D[0][0].piece.Ttype = "rookB";
    board2D[0][7].piece.S.setTexture(rookB);
    board2D[0][7].piece.Ttype = "rookB";
    // Knights
    board2D[0][1].piece.S.setTexture(knightB);
    board2D[0][1].piece.Ttype = "knightB";
    board2D[0][6].piece.S.setTexture(knightB);
    board2D[0][6].piece.Ttype = "knightB";
    // Bishops
    board2D[0][2].piece.S.setTexture(bishopB);
    board2D[0][2].piece.Ttype = "bishopB";
    board2D[0][5].piece.S.setTexture(bishopB);
    board2D[0][5].piece.Ttype = "bishopB";
    // Queen
    board2D[0][3].piece.S.setTexture(queenB);
    board2D[0][3].piece.Ttype = "queenB";
    // King
    board2D[0][4].piece.S.setTexture(kingB);
    board2D[0][4].piece.Ttype = "kingB";
    for (int j = 0; j < 8; j++) {
        board2D[1][j].piece.S.setTexture(pawnB);
        board2D[1][j].piece.Ttype = "pawnB";
    }                            
    for (int j = 0; j < 8; j++) {
        board2D[6][j].piece.S.setTexture(pawnW);
        board2D[6][j].piece.Ttype = "pawnW";
    }
    // --- White major pieces (row 7) ---
    board2D[7][0].piece.S.setTexture(rookW);
    board2D[7][0].piece.Ttype = "rookW";
    board2D[7][7].piece.S.setTexture(rookW);
    board2D[7][7].piece.Ttype = "rookW";
    // Knights
    board2D[7][1].piece.S.setTexture(knightW);
    board2D[7][1].piece.Ttype = "knightW";
    board2D[7][6].piece.S.setTexture(knightW);
    board2D[7][6].piece.Ttype = "knightW";
    // Bishops
    board2D[7][2].piece.S.setTexture(bishopW);
    board2D[7][2].piece.Ttype = "bishopW";
    board2D[7][5].piece.S.setTexture(bishopW);
    board2D[7][5].piece.Ttype = "bishopW";
    // Queen
    board2D[7][3].piece.S.setTexture(queenW);
    board2D[7][3].piece.Ttype = "queenW";
    // King
    board2D[7][4].piece.S.setTexture(kingW);
    board2D[7][4].piece.Ttype = "kingW";


    // --- Set positions for all non-empty squares ---
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (!board2D[i][j].piece.Ttype.empty()) {
                board2D[i][j].piece.S.setPosition(j * BOARD_SIZE, i * BOARD_SIZE);
            }
        }
    }
}


                    
  void draw_pieces(sf::RenderWindow& window){
      for(int  y = 0;y<8;y++){
            for(int x = 0;x<8;x++){
                  board2D[y][x].piece.S.setPosition({(float)x*100,(float)y*100});
                  board2D[y][x].piece.S.setScale(100.0f/128.0f,100.0f/128.0f);
                  if(!board2D[y][x].piece.Ttype.empty())
                  window.draw(board2D[y][x].piece.S);
                  else 
                  continue;
            }
      }
  }

#endif