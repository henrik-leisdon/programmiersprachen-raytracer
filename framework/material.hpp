#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <iostream>
#include <string>
#include "color.hpp"

using namespace std;


struct Material
{
    //Standard constructor
    Material():
        name_(string("material")),
        ka_({0.0f, 0.0f, 0.0f}),
        kd_({0.0f, 0.0f, 0.0f}),
        ks_({0.0f, 0.0f, 0.0f}),
        m_(0.0f),
        {}

    //Costum Constructor
    Material(string const& name, Color const& ka, Color const& kd, Color const& ks, float m) :
        name_(name),
        ka_(ka),
        kd_(kd),
        ks_(ks),
        m_(m),
        {}   

    string name_;
    Color ka_; /* textures return colors, ka, kd, ks are reflection
                coefficients*/ 
    Color kd_;
    Color ks_;
    float m_; /* Phong-exponent needed for the intensity of the specular reflection, 
                specular = direct reflection of the light source*/

    //Streamoperator to print
    ostream& operator << (ostream& ost, Material const& mate){
        ost << "name : " << mate.name_ << '\n';
        ost << "ambient : " << mate.ka_ << '\n';
        ost << "diffuse : " << mate.kd_ << '\n'; 
        ost << "specular : " << mate.ks_ << '\n';
        return ost; 
    }
};


#endif 