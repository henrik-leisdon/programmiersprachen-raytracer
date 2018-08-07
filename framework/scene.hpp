#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <memory>

#include "camera.hpp"
#include "material.hpp"
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "light.hpp"



class Scene
{
    public:
        void read_SDF(std::string const& path, Scene& scene);
  

  		void addLights(Light const& light);
  
  		Color getPixelColor(Ray const& ray);

        shared_ptr<Material> find_material(std::string matName, Scene& sc);

        std::map <std::string,std::shared_ptr< Material>> material_map;
        std::map <std::string,std::shared_ptr< Light>> light_map;   //shape map or one map for every object (box,sphere...)??   
  		std::map <std::string,std::shared_ptr< Box>> box_map;
  		std::map <std::string,std::shared_ptr< Sphere>> sphere_map;

};