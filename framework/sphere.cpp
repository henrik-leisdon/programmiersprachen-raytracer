#include "sphere.hpp"

#include <glm/gtx/intersect.hpp>

Sphere::Sphere():
    Shape(),
    spMid_({0.0,0.0,0.0}),
    spRadius_{0.0}
    {std::cout << "sp child default constructor \n ";};

Sphere::Sphere(glm::vec3 const& spMid, double spRadius, std::string name, Color color):
    Shape(name, color),
    spMid_{spMid},
    spRadius_{spRadius}
    {std::cout << "sp child copy constructor \n ";};

Sphere::~Sphere()
{
    std::cout << "sp child deconstructor \n ";
}


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

std::ostream& Sphere::print(std::ostream& os) const
{
    os  << "area: " << area() <<"\n"
        << "volume: " << volume() <<"\n";

    return os;
}

bool Sphere::intersect(Ray const& ray, float distance) const
{
    return glm::intersectRaySphere(ray.origin,ray.direction, spMid_, spRadius_*spRadius_,distance);
        
}