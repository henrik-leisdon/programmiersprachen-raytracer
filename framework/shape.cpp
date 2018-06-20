#include "framework/shape.hpp"

Shape::Shape():
    name_{"noObject"},
    color_{0.0,0.0,0.0}
    {};

Shape::Shape(std::string name, Color const& color):
    name_{name},
    color_{color}
    {};

std::string Shape::getName() const
{
    return name_;
}

Color Shape::getColor() const
{
    return color_;
}