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
: Graphic(s, w, h) {

}

Triangle::~Triangle(){

}

void Triangle::draw() const {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < i +1; j++) {
			cout << symbol;
		}
		cout << endl;
	}
	cout << endl;
}

void Triangle::setHeight(int h) {
	height = h;
	width = h;
}

void Triangle::setWidth(int w) {
	height = w;
	width = w;
}

#endif
