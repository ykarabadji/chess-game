#include <iostream>
#include <cstdlib>
#include <vector>
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "spirits.h"
#include "logic.h"
static std::vector<sf::RectangleShape> board;
static int board_control_color = 0;//it controls and manages board color 

void board_init(sf::RectangleShape square){
    for(float x=0;x<BOARD_WIDTH;x+=100){
        for(float  y=0;y<BOARD_HEIGHT;y+=100){
                square.setSize(sf::Vector2f({BOARD_SIZE,BOARD_SIZE}));
                square.setPosition({x,y});
            if(board_control_color == 0 ){
                square.setFillColor(sf::Color::White);
                board_control_color = 1;

             }else
             {
                square.setFillColor(sf::Color(64,64,64));
                board_control_color = 0;
             }
            board.push_back(square);
        }
        if(board_control_color == 1){
            board_control_color = 0;
        }else
        {
            board_control_color = 1;
        }
    }
}




int main(){
    sf::RectangleShape square;
    sf::RenderWindow window(sf::VideoMode({800,800}),"chessgame");
    //init of board squares
    board_init(square);
    //first init of board pieces
    initPieces();
    while(window.isOpen())
    {   
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                window.close();

            }
              // getting position of pressed button
            if(event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                int x = mousePos.x/100;
                int y = mousePos.y/100;
                std::string clickedpiece = isntEmpty(x,y);
                std::cout<<clickedpiece<<'\n';
                std::cout<<"x:"<< x<<'\n';
                std::cout<<"y:"<< y << '\n';
              
                
                if(selectedP.name.empty()){
                         selectedP.name = clickedpiece;
                         selectedP.x = x;
                         selectedP.y = y;
                    std::cout<<"selected first piece: " << selectedP.name<<'\n';
                }else{
                    if( find_element_in_string(whitepieces,selectedP.name)!=whitepieces.end() && find_element_in_string(whitepieces,clickedpiece)!=whitepieces.end()){
                         selectedP.name = clickedpiece;
                         selectedP.x = x;
                         selectedP.y = y; 
                         std::cout<<" new selected  piece: " << selectedP.name<<'\n';

                    }else if(find_element_in_string(blackpieces,selectedP.name)!=blackpieces.end() && find_element_in_string(blackpieces,clickedpiece)!=blackpieces.end()){
                         selectedP.name = clickedpiece;
                         selectedP.x = x;
                         selectedP.y = y; 
                         std::cout<<"new selected piece: " << selectedP.name <<'\n';
                    }else{
                        std::cout<<"else movement entered";

                        if((selectedP.name == "rookW" && whiteRole == 1 )||(selectedP.name == "rookB" && blackRole == 1)){
                           rookMov(selectedP,mousePos);
                           roleReverse();
                         }
                         selectedP.name = "";
                         std::cout<<"black role: "<<blackRole;
                         std::cout<<"white role:" << whiteRole;
                         
                         }


                   

             
                
                

            }

        }}
           
           // the core of our program //
window.clear();

           // we draw the board squares //
for (sf::RectangleShape sq : board ){
    window.draw(sq);}
           

            
            
draw_pieces(window);
            
           
          

 window.display();
 // end of window.isOpen() // 
  }


  return EXIT_SUCCESS;


}
