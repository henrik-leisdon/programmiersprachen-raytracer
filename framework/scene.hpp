#ifndef SCENE_HPP
#define SCENE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>


#include <sstream>
#include <memory>
#include <glm/vec3.hpp>

#include "camera.hpp"
#include "material.hpp"
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "light.hpp"



class Scene
{
    public:

        std::map <std::string,std::shared_ptr< Material>> material_map;
        std::map <std::string,std::shared_ptr< Light>> light_map;   //shape map or one map for every object (box,sphere...)??   
  		std::map <std::string,std::shared_ptr< Box>> box_map;
  		std::map <std::string,std::shared_ptr< Sphere>> sphere_map;

};

        void read_SDF(std::string const& path, Scene& scene);
  
  		

        shared_ptr<Material> find_material(std::string matName, Scene& sc);


#endif