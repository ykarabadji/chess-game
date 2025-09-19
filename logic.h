#ifndef LOGIC_H
#define LOGIC_H

#include <SFML/Graphics.hpp>
#include <string>
#include <algorithm>
#include <cmath>
   //next step is building validMoves function verification // 


 void getKingsPos(){
    for(int y = 0;y<=NSQUARES;y++){
        for(int x = 0;x<=NSQUARES;x++)
        {
            if(board2D[y][x].piece.Ttype == "kingW")
            {
                kingWPos = {y,x};

            }else if(board2D[y][x].piece.Ttype == "kingB")
            {
                kingBPos = {y,x};
            }
        }
    }
 }
 bool squareIsEmpty(sf::Vector2i mousePos);
 // is there a piece on the way of bishop to his distination ??
 bool pieceThewayBishop(sf::Vector2i mousePos){
    sf::Vector2i search;
    int boardx = mousePos.x/100;
    int boardy = mousePos.y/100;

    if(boardx > selectedP.x && boardy < selectedP.y)// upper right
    {
       int x = selectedP.x +1;
       int y = selectedP.y -1;
       if(x == boardx && y == boardy)
         return false;
       do
       {
         search = {x*100,y*100};
         if(squareIsEmpty(search) == false)
         {
            std::cout<<"there is one piece in the way of bishop"<<'\n';
            return true;
         }
         x++;
         y--;
       }while(x<boardx && y>boardy);//end
    }else if(boardx < selectedP.x && boardy > selectedP.y )// down - left
    {
       int x = selectedP.x -1;
       int y = selectedP.y + 1;
       if(x == boardx && y == boardy)
         return false;
       do
       {
        search = {x*100,y*100};
        if(squareIsEmpty(search) == false)
         {
            std::cout<<"there is one piece in the way of bishop"<<'\n';
            return true;
         }
        x--;
        y++;
       }while(x>boardx && y<boardy);
       
    }else if(boardx > selectedP.x && boardy > selectedP.y)//  down - right
    {
       int x = selectedP.x +1;
       int y = selectedP.y +1;
       if(x == boardx && y == boardy)
         return false;
       do
       {
        search = {x*100,y*100};
        if(squareIsEmpty(search) == false)
         {
            std::cout<<"there is one piece in the way of bishop"<<'\n';
            return true;
         }
        x++;
        y++;
       }while(x<boardx && y<boardy);
    }else if(boardx < selectedP.x && boardy < selectedP.y)// upper left
    {
       int x = selectedP.x - 1;
       int y = selectedP.y - 1;
       if(x == boardx && y == boardy)
         return false;
       do
       {

        // actions //
        search = {x*100,y*100};
        if(squareIsEmpty(search) == false)
         {
            std::cout<<"there is one piece in the way of bishop"<<'\n';
            return true;
         }
        
        y--;
        x--;
       }while(x>boardx && y>boardy);
    }

    return false;

 }
 bool pieceThewayRook(sf::Vector2i mousePos){
    sf::Vector2i search;
    int boardx = mousePos.x/100;
    int boardy = mousePos.y/100;
    // i did added in some loop 1 and substracted it in others because we cant start from the selected piece pos it will return directly
    if(boardy  < selectedP.y && boardx == selectedP.x){
             for(int y = selectedP.y-1;y>boardy;y--){
                search = {boardx*100,y*100};
                std::cout<<"the pieces that it is in the way is :"<<"x:"<<search.x<<"y:"<<search.y<<'\n';
                if(squareIsEmpty(search) == false){
                   std::cout<<"the square isnt empty:--> and the piece that is inside is -->" << board2D[search.y/100][search.x/100].piece.Ttype;
                   return true;
                }
             }
    }else if(boardy > selectedP.y && boardx == selectedP.x){
             for(int y = selectedP.y+1;y<boardy;y++){
                search = {boardx*100,y*100};
                std::cout<<"the pieces that it is in the way is :"<<"x:"<<search.x<<"y:"<<search.y<<'\n';
                if(squareIsEmpty(search) == false){
                   return true;
                }
             }
    }else if(boardx > selectedP.x && boardy == selectedP.y){
              for(int x = selectedP.x+1;x<boardx;x++){
                search = {x*100,boardy*100};
                std::cout<<"the pieces that it is in the way is :"<<"x:"<<search.x<<"y:"<<search.y<<'\n';
                if(squareIsEmpty(search) == false){
                   return true;
                }
             }
    }else if(boardx < selectedP.x && boardy == selectedP.y){
              for(int x = selectedP.x-1;x>boardx;x--){
                search = {x*100,boardy*100};
                std::cout<<"the pieces that it is in the way is :"<<"x:"<<search.x<<"y:"<<search.y<<'\n';
                if(squareIsEmpty(search) == false){
                   return true;
                }
             }
    }
    return false;
 }
 bool squareIsEmpty(sf::Vector2i mousePos){
     int boardx = mousePos.x/100;
     int boardy = mousePos.y/100;
     if(!board2D[boardy][boardx].piece.Ttype.empty()){
        return false;
     }
     return true;
 }

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
     if(pieceThewayRook(mousePos)){
                std::cout<<"there is a piece in the way of the rook";
                return;
            }
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
        if( abs(boardy - selectedP.y) <3 && (abs(selectedP.y - NSQUARES) == 1 || abs(selectedP.y - NSQUARES) == 6) && squareIsEmpty(mousePos)){

             transferPiecePos(selectedP,boardx,boardy);

        }else if(abs(boardy - selectedP.y) == 1 && squareIsEmpty(mousePos)){

             std::cout<< " we are here baordy - mousePos.y";

             transferPiecePos(selectedP,boardx,boardy);

         }
     }else if(abs(boardy - selectedP.y) == 1 && abs(boardx - selectedP.x) == 1 &&  !squareIsEmpty(mousePos)){

            transferPiecePos(selectedP,boardx,boardy);
     }else{
         std::cout<< "pawn returned without moving "<<'\n';
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

 void bishopMov(pieceTrack& selectedP,sf::Vector2i mousePos)
 {
    int boardx = mousePos.x/100;
    int boardy = mousePos.y/100;
    if(pieceThewayBishop(mousePos)){
        std::cout<<"bishop returned because of a piece on its way";
        return;
    }
    int ray2X = abs(boardx - selectedP.x);
    std::cout<< "the ray2x is :"<<ray2X;
    int distanceY= abs(boardy - selectedP.y);
    std::cout<< "the distance y is :" << distanceY;
    double ray1Y = sqrt((ray2X*ray2X) + (distanceY*distanceY));
    std::cout<< "ray1 distance: "<<ray1Y;
    float rays_division = ray2X/ray1Y;
    int angle = std::acos(rays_division)*(180.0/M_PI);//transforme to radian
    std::cout<< "the value of the angle is"<<angle;
    if(angle == 45.0f){
        transferPiecePos(selectedP,boardx,boardy);
    }else{
        std::cout<<"bishop returned without moving"<<'\n';
    }
 }


 void queenMov(pieceTrack& selectedP,sf::Vector2i mousePos)
 {  

    if(pieceThewayBishop(mousePos) || pieceThewayRook(mousePos)){
        std::cout<<" queen tried to move but piece was in his way" << '\n';
        return;
    }
    //here i can just remove this code and include in its place rookmov() and bishop moves()
    rookMov(selectedP,mousePos);
    // if rookMov returned 
    bishopMov(selectedP,mousePos);

    //if the posiiton selected is corrected   for a queen mov either one of them work //
 }

 // is the king targeted //

 bool checkTheKing(){
       for(int y = 0;y<=NSQUARES;y++){
        for(int x = 0;x<=NSQUARES;x++)
        {
            
        }
    }
 }




#endif
