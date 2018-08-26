#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include <memory>
#include "shape.hpp"
#include "ray.hpp"

class Box : public Shape
{
    public:
        Box();
        Box(std::string name, glm::vec3 const& boxMin, glm::vec3 const& boxMax, std::shared_ptr<Material> material);
        ~Box();

        glm::vec3 getBoxMin();
        glm::vec3 getBoxMax();

        double area() const override;
        double volume() const override;

        glm::vec3 calcNormal(glm::vec3 boxMin, glm::vec3 boxMax);

        bool intersect( Ray const & ray , float & t , glm::vec3& normvec) override; //override pure virtual intersect function from shape 

        std::ostream& print(std::ostream& os) const override;



    private:
        glm::vec3 boxMin_;
        glm::vec3 boxMax_;



};


#endif