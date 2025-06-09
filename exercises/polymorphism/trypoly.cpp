#include "Polygons.hpp"
#include <iostream>

int main() {
    // create a Pentagon, call its perimeter method
    Pentagon pentagon = Pentagon(10);
    pentagon.computePerimeter();

    // create a Hexagon, call its perimeter method
    Hexagon hexagon = Hexagon(10);
    hexagon.computePerimeter();

    // create a Hexagon, call the perimeter method through a reference to Polygon
    RegularPolygon &polygon = hexagon;
    polygon.computePerimeter();

    // retry virtual method

}
