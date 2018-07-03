#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <glm/vec3.hpp>
#include <math.h>
#include "color.hpp"
#include <string.h>
#include "ray.hpp"

class Shape
{
    public:
        Shape();
        Shape(std::string name, Color const& color);

        ~Shape();

        std::string getName() const;
        Color getColor() const;

        virtual double area() const = 0;
        virtual double volume() const = 0;

        virtual bool intersect ( Ray const & ray , float & t ) = 0; //task 6.3

        virtual std::ostream& print (std::ostream& os) const;


        private:
        std::string name_;
        Color color_;      

};

std::ostream& operator <<(std::ostream& os, Shape const& s);
#endif