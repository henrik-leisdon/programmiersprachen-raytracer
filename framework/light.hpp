#ifndef LIGHT_HPP
#define LIGHT_HPP


#include <iostream>
#include <string>
#include "color.hpp"
#include <glm/vec3.hpp>
#include "ray.hpp"

class Light
{
    public:
        Light(); //Default constructor
        Light(std::string name,glm::vec3 const& pos,Color const& clr,int brightness); //copy constructor

        ~Light(); //deconstructor

        std::string getName(); //getter
        glm::vec3 getPos();
        Color getClr();
        int getBrightness();



    private:
        std::string name_;
        glm::vec3 pos_;
        Color clr_;
        int brightness_;

};

#endif