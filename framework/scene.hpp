#include <iostream>
#include <fstream>
#include <string>
#include "material.hpp"
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <memory>



struct Scene
{
    std::map <std::string,std::shared_ptr< Material>> material_map;
};

void read_SDF(std::string const& path, Scene& scene)
{
    std::ifstream file(path);
    std::string line;
    
    if(!file.is_open())
    {
        std::cout << "Error. Could not open file";
    }
    else
    {
        std::cout << "was able to read file";
    }

    while(getline(file,line))
    {
        stringstream line_buffer(line);

        std::string i1;
        std::string i2;
        Material mat;

        line_buffer >> i1 >> i2;

        if(i1 == "define")
        {
            if(i2 == "material")
            {
                line_buffer >> i1 >> i2
                >> mat.name_ 
                >> mat.ka_.r 
                >> mat.ka_.g
                >> mat.ka_.b
                >> mat.kd_.r
                >> mat.kd_.g
                >> mat.kd_.b
                >> mat.ks_.r
                >> mat.ks_.g
                >> mat.ks_.b
                >> mat.m_;

                std::shared_ptr<Material>matp = std::make_shared<Material>(mat);
                scene.material_map.insert(std::pair<std::string,std::shared_ptr<Material>> (matp->name_,matp));
            }
        }        

    }
    file.close();

}


std::shared_ptr<Material> find_material(std::string matName, Scene& sc)
{
    if(sc.material_map.find(matName) != sc.material_map.end())
    {
        return sc.material_map.find(matName)->second;
        
    }
    else 
    {
        return nullptr;
    }
}