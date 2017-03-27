#include <bits/stdc++.h>
#include "bitmap_image.hpp"

using namespace std;

#define u unsigned

class Figure {
public:
    virtual void genShape
        (bitmap_image& image, u x1 = 0, u y1 = 0, u x2 = 0
        , u y2 = 0, u x3 = 0, u y3 = 0) {}
    // треугольник задается 3мя вершинами
    // круг задается центром и радиусом
    // прямоугольник задается нижней левой и верхней правой вершинами
};
class Triangle : public Figure {
public:
    void genShape
        (bitmap_image& image, u x1 = 0, u y1 = 0, u x2 = 0
        , u y2 = 0, u x3 = 0, u y3 = 0) {
            image_drawer draw(image);
            draw.pen_width(3);
            draw.pen_color(255, 0, 0);
            draw.triangle(x1, y1, x2, y2, x3, y3);
        }

};
class Circle : public Figure {
public:
	void genShape
        (bitmap_image& image, u x1 = 0, u y1 = 0, u x2 = 0
        , u y2 = 0, u x3 = 0, u y3 = 0) {
            image_drawer draw(image);
            draw.pen_width(1);
            draw.pen_color(0, 0, 255);
            u r = x2;
            draw.circle(x1, y1, r);
        }
};
class Rectangle : public Figure {
public:
	void genShape
        (bitmap_image& image, u x1 = 0, u y1 = 0, u x2 = 0
        , u y2 = 0, u x3 = 0, u y3 = 0) {
            image_drawer draw(image);
            draw.pen_width(2);
            draw.pen_color(0, 255, 0);
            draw.rectangle(x1, y1, x2, y2);
        }
};
int main()
{
        bitmap_image image(500, 500);
	Figure* a[3];
	a[0] = new Triangle;
	a[1] = new Circle;
	a[2] = new Rectangle;
	a[0]->genShape(image, 0, 0, 40, 40, 120, 67);
	a[1]->genShape(image, 370, 370, 40);
	a[2]->genShape(image, 254, 43, 400, 400);
        image.save_image("output.bmp");
        return 0;
}
