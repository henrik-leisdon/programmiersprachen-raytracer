#include "shape.hpp"

Shape::Shape():
    name_{"no_Object"}
    //material_{0.0,0.0,0.0}
    {
        std::cout << "base constructor \n ";
    };

Shape::Shape(std::string name, std::shared_ptr<Material> const& material):
    name_{name},
    material_{material}
    {
        std::cout << "base copy constructor \n ";
    };

Shape::~Shape()
{
    std::cout << "base deconstructor \n ";
};

std::string Shape::getName() const
{
    return name_;
}

std::shared_ptr<Material> Shape::getMaterial() const
{
    return material_;
}

std::ostream& Shape::print(std::ostream& os) const
{
    os << "name: " << name_ << "\n"
       << "material: " << *material_ <<"\n";
    return os;
}

std::ostream& operator <<(std::ostream& os, Shape const& s)
{
    return s.print(os);
}