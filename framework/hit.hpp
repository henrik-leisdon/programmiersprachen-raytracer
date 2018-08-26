#ifndef HIT_HPP
#define HIT_HPP

#include <glm/vec3.hpp>
#include <map>
#include <vector>
#include "ray.hpp"
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>

class Hit {

    public:
        Hit();
        Hit(bool, float, glm::vec3 const&, glm::vec3 const&, std::string const&, std::string const&);

        void transHit(glm::mat4 const&, glm::mat4 const&);

    private:
        bool hit_;
        float dist_;
        glm::vec3 inters_;
        glm::vec3 normvec_;
        std::string matname_;
        std::string type_;    
};

#endif