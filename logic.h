#ifndef LOGIC_H
#define LOGIC_H

#include <SFML/Graphics.hpp>
#include <string>
#include <algorithm>
#include <cmath>
   //next step is building validMoves function verification // 

   
  /*bool validMoves(){

  }*/
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
 // mecanism to transfer the piece //
 void transferPiecePos(pieceTrack& selectedP,int boardx,int boardy){
     
            board2D[boardy][boardx].piece.S  = board2D[selectedP.y][selectedP.x].piece.S;
            board2D[boardy][boardx].piece.S.setPosition(boardx * 100, boardy * 100);
            board2D[boardy][boardx].piece.Ttype = selectedP.name;
            board2D[selectedP.y][selectedP.x].piece.Ttype.clear();
            board2D[selectedP.y][selectedP.x].piece.S = sf::Sprite();
            // change roles;
            roleReverse();
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
 void rookMov(pieceTrack& selectedP,sf::Vector2i mousePos){
    int boardx = mousePos.x/100;
    int boardy = mousePos.y/100;
    
     std::cout<<"jkeje";
    if(selectedP.y == boardy){
        if(boardx >=0 && boardx<8 && boardx!=selectedP.x){
            transferPiecePos(selectedP,boardx,boardy);


        }
    }else if(selectedP.x == boardx){
        if(boardy >=0 && boardy<8 && boardy!=selectedP.y){
            transferPiecePos(selectedP,boardx,boardy);

        }
    }
    
  
    
 }

 void pawnMov(pieceTrack& selectedP,sf::Vector2i mousePos)
 {
     int boardx = mousePos.x/100;
     int boardy = mousePos.y/100;
     std::cout<< " result of substraction is -->" << abs(boardy - selectedP.y);
     if(boardx == selectedP.x)
     {
         // here it can move 2 squares
        if( abs(boardy - selectedP.y) <=3 && (abs(selectedP.y - NSQUARES) == 1 || abs(selectedP.y - NSQUARES) == 6)){
             transferPiecePos(selectedP,boardx,boardy);

        }else if(abs(boardy - selectedP.y) == 1){
             std::cout<< " we are here baordy - mousePos.y";
             transferPiecePos(selectedP,boardx,boardy);

        }
     }
 }

 void knightMov(pieceTrack& selectedP,sf::Vector2i mousePos)
 {
     int boardx = mousePos.x/100;
     int boardy = mousePos.y/100;
     std::cout<< "x: "<<boardx<<"y: " << boardy <<'\n';
     if(abs(boardy - selectedP.y) == 2 || abs(boardy - selectedP.y) == 1){
         if(abs(boardx - selectedP.x) == 1 || abs(boardx - selectedP.x) == 2)
         {
              std::cout<<"helooo";
              transferPiecePos(selectedP,boardx,boardy);

         }

     }else
     {
         std::cout<<"the rook movement is returned";
         return;

     }
 }

 void kingMov(pieceTrack& selectedP,sf::Vector2i mousePos)
 {
      int boardx = mousePos.x/100;
      int boardy = mousePos.y/100;

      if(boardx == selectedP.x && abs(boardy - selectedP.y) == 1){
            transferPiecePos(selectedP,boardx,boardy);

        }else if(boardy == selectedP.y && abs(boardx - selectedP.x) == 1){
            transferPiecePos(selectedP,boardx,boardy);
        }else if(abs(boardy - selectedP.y) == 1 && abs(boardx - selectedP.x) == 1){
            transferPiecePos(selectedP,boardx,boardy);
        }else{
            std::cout<<"king returned without moving"<<'\n';
        }
 }




#endif
