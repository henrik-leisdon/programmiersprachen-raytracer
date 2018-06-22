#include "sphere.hpp"

Sphere::Sphere():
    Shape(),
    spMid_({0.0,0.0,0.0}),
    spRadius_{0.0}
    {};

Sphere::Sphere(glm::vec3 const& spMid, double spRadius, std::string name, Color color):
    Shape(name, color),
    spMid_{spMid},
    spRadius_{spRadius}
    {};


glm::vec3 Sphere::getSpMid() const
{
    return spMid_;
}

double Sphere::getSpRadius() const
{
    return spRadius_;
}

double Sphere::area() const
{
    return 4*M_PI*spRadius_*spRadius_;
}
double Sphere::volume() const
{
    return(4/3)*M_PI*spRadius_*spRadius_*spRadius_;
}