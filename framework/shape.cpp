#include "shape.hpp"

Shape::Shape():
    name_{"noObject"},
    color_{0.0,0.0,0.0}
    {std::cout << "base constructor \n ";};

Shape::Shape(std::string name, Color const& color):
    name_{name},
    color_{color}
    {std::cout << "base copy constructor \n ";};

Shape::~Shape()
{
    std::cout << "base deconstructor \n ";
};

std::string Shape::getName() const
{
    return name_;
}

Color Shape::getColor() const
{
    return color_;
}

std::ostream& Shape::print(std::ostream& os) const
{
    os << "name: " << name_ << "\n"
       << "color: " << color_ <<"\n";
    return os;
}

std::ostream& operator <<(std::ostream& os, Shape const& s)
{
    return s.print(os);
}