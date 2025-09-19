#ifndef EF_F
#define EF_F

#include <SFML/Graphics.hpp>
#include "constants.h"
#include <iostream>
void selectEffect(){
      // we remove the red color from old selected piece //
    for (sf::RectangleShape& sq : board){
        sq.setOutlineThickness(0.f);
    }

    // if there is a selected piece we change its border color to red
    if(!selectedP.name.empty())
    {
     for (sf::RectangleShape& sq : board ){


     if((sq.getPosition().x)/100 == selectedP.x && (sq.getPosition().y)/100 == selectedP.y){
         sq.setOutlineThickness(5.f);
         sq.setOutlineColor(sf::Color::Red);
       }
    }



    }
}






#endif
