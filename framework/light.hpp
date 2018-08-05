#ifndef LIGHT_HPP
#define LIGHT_HPP


#include <iostream>
#include <string>
#include "color.hpp"
#include <vec3.hpp>

class Light
{
    public:
        Light();
        Light(std::string name,glm::vec3 const& pos,Color const& clr,int brightness);

        ~Light();

        std::string getName();
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