#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Graphic.hpp"
#include <iostream>

class Triangle : public Graphic {
    public:
        Triangle(char, int, int);
        virtual ~Triangle();
        virtual void setWidth(int) override;
        virtual void setHeight(int) override;
        virtual void draw() const override;
};

Triangle::Triangle(char s, int w, int h)
: symbol(s), width(w), height(h){

}

Triangle::~Triangle(){

}
#endif
