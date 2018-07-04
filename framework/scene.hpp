#include <iostream>
#include <fstream>
#include <string>
#include "material.hpp"

struct Scene
{

};

void read_SDF()
{
    std::string dateizeile;
    std::fstream f;
    f.open("material.sdf");
    while(getline(f,dateizeile))
    {

    }
    f.close();

}