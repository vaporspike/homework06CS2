
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
: Graphic(s, w, h) {

}

Rectangle::~Rectangle(){

}

void Rectangle::draw() const{
	for (int i = 0; i < height; i++) {
		for (int j = 0;j < width; j++) {
			cout << symbol;
		}
		cout << endl;
	}
}

#endif

