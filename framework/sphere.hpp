#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

class Sphere : public Shape
{
    public:
        Sphere();
        Sphere(glm::vec3 const& spMid, double spRadius, std::string name, Color color);

        glm::vec3 getSpMid() const;
        double getSpRadius() const;

        double area() const override;
        double volume() const override;

    private:
        glm::vec3 spMid_;
        double spRadius_;
};


#endif