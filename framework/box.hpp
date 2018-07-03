#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"

class Box : public Shape
{
    public:
        Box();
        Box(std::string name, glm::vec3 const& boxMin, glm::vec3 const& boxMax, Color color);
        ~Box();

        glm::vec3 getBoxMin();
        glm::vec3 getBoxMax();

        double area() const override;
        double volume() const override;

        bool intersect ( Ray const & ray , float & t ) override; //override pure virtual intersect function from shape 

        std::ostream& print(std::ostream& os) const override;



    private:
        glm::vec3 boxMin_;
        glm::vec3 boxMax_;



};


#endif