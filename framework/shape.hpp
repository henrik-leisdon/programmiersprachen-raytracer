#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <memory>
#include <glm/vec3.hpp>
#include <math.h>
#include "color.hpp"
#include <string.h>
#include "ray.hpp"
#include "material.hpp"

class Shape
{
    public:
        Shape();
        Shape(std::string name, std::shared_ptr<Material> const& material);

        ~Shape();

        std::string getName() const;
        std::shared_ptr<Material> getMaterial() const;

        virtual double area() const = 0;
        virtual double volume() const = 0;

        virtual bool intersect( Ray const & ray , float & t , glm::vec3& normvec) = 0; //task 6.3

        virtual std::ostream& print (std::ostream& os) const;


        private:
        std::string name_;
        std::shared_ptr<Material> material_;     

};

std::ostream& operator <<(std::ostream& os, Shape const& s);
#endif