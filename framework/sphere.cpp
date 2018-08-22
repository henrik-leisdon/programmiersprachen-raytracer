#include "sphere.hpp"

#include <glm/gtx/intersect.hpp>

Sphere::Sphere():
    Shape(),
    spMid_({0.0,0.0,0.0}),
<<<<<<< HEAD
    spRadius_{0.0}
    {
        //std::cout << "sp child default constructor \n ";
        };
=======
    spRadius_{100.0}
    {};
>>>>>>> 1bf949107478095a556e433929787c711cd32dcf

Sphere::Sphere(glm::vec3 const& spMid, double spRadius, std::string name, std::shared_ptr<Material> material):
    Shape(name, material),
    spMid_{spMid},
    spRadius_{spRadius}
    {};

Sphere::~Sphere()
<<<<<<< HEAD
{

}
=======
{}
>>>>>>> 1bf949107478095a556e433929787c711cd32dcf


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

bool Sphere::intersect(Ray const& ray, float& t)  //float&
{
    return glm::intersectRaySphere(ray.origin,ray.direction, spMid_, spRadius_*spRadius_,t);
        
}