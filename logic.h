#ifndef LOGIC_H
#define LOGIC_H

#include <SFML/Graphics.hpp>
#include <string>
#include <algorithm>



    //roles reverse 
    void roleReverse(){
        if(whiteRole == 1){
            whiteRole = 0;
        }else{
            whiteRole = 1;
        }
        if(blackRole == 1)
        {
            blackRole = 0;
        }else{
            blackRole = 1;
        }
        
    }

    //find an element in a vector //
 auto find_element_in_string(std::vector<std::string>& array,std::string word){
      
      return std::find(array.begin(),array.end(),word);
   }
   // this function checks if a piece is present in specific square 
 std::string isntEmpty(int x,int y){
    
    if(board2D[y][x].piece.Ttype.empty()){
        return "";
    }
    return board2D[y][x].piece.Ttype;
 }


 // rook movement 
 void rookMov(pieceTrack& pieceT,sf::Vector2i mousePos){
    int boardx = mousePos.x/100;
    int boardy = mousePos.y/100;
    
     std::cout<<"jkeje";
    if(pieceT.y == boardy){
        if(boardx >=0 && boardx<8 && boardx!=pieceT.x){
            board2D[boardy][boardx].piece.S  = board2D[pieceT.y][pieceT.x].piece.S;
            board2D[boardy][boardx].piece.S.setPosition(boardx * 100, boardy * 100);
            board2D[boardy][boardx].piece.Ttype = pieceT.name;
            board2D[pieceT.y][pieceT.x].piece.Ttype.clear();
            board2D[pieceT.y][pieceT.x].piece.S = sf::Sprite();

        }
    }else if(pieceT.x == boardx){
        if(boardy >=0 && boardy<8 && boardy!=pieceT.y){
            board2D[boardy][boardx].piece.S  = board2D[pieceT.y][pieceT.x].piece.S;
            board2D[boardy][boardx].piece.S.setPosition(boardx * 100, boardy * 100);
            board2D[boardy][boardx].piece.Ttype = pieceT.name;
            board2D[pieceT.y][pieceT.x].piece.Ttype.clear();
            board2D[pieceT.y][pieceT.x].piece.S = sf::Sprite();
        }
    }
    
  
    
 }



#endif 