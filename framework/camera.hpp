#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <string>
#include <cmath>
#include <glm/glm.hpp>
#include "ray.hpp"

using namespace std;

class Camera {
    public: 

        Camera(); //Standard constructor 
        //fov = field of view , so basically angle 
        Camera(string const& name, float fov, glm::vec3 const& pos); //Costum constructor 1 
        ~Camera(); //dont know if needed or not.. 

        string getName() const;
        glm::vec3 getPos() const;
        float getAngle() const;
        float getDist() const;

    private:

        string name_;
        glm::vec3 pos_;
        glm::vec3 up_; //needed vectors for orthonormal base 
        glm::vec3 dir_;
        float angle_;
        float dist_; //to pixel canvas (viewing plane )


};

#endif