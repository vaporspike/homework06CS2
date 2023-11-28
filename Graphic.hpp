#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include <string>
using namespace std;

class Graphic {
    protected:
        char symbol;
        int width, height;

    public:
        Graphic(char, int, int);
        virtual ~Graphic();
        char getSymbol() const;
        int getWidth() const;
        int getHeight() const;
        void setSymbol(char);
        virtual void setWidth(int);
        virtual void setHeight(int);
        virtual void draw() const = 0;

        class IllegalDimension {
            private:
                string msg;

            public:
                IllegalDimension(string = "");
                string what() const;
        };
};

#endif
