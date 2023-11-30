#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Graphic.hpp"
#include <iostream>

class Rectangle : public Graphic {
    public:
        Rectangle(char, int, int);
        virtual ~Rectangle();
        virtual void draw() const override;
};

Rectangle::Rectangle(char s, int w, int h)
: symbol(s), width(w), height(h){

}

Rectangle::~Rectangle(){

}
#endif
