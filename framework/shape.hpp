#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <glm/vec3.hpp>
#include <math.h>
#include "color.hpp"
#include <string.h>

class Shape
{
    public:
        Shape();
        Shape(std::string name, Color const& color);

        std::string getName() const;
        Color getColor() const;

        virtual double area() const = 0;
        virtual double volume() const = 0;



        private:
        std::string name_;
        Color color_;      

};

#endif