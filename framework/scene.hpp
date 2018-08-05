#include <iostream>
#include <fstream>
#include <string>
#include "material.hpp"
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <memory>
#include "box.hpp"
#include "sphere.hpp"



class Scene
{
    public:
        void read_SDF(std::string const& path, Scene& scene);



        shared_ptr<Material> find_material(std::string matName, Scene& sc);


        std::map <std::string,std::shared_ptr< Material>> material_map;
    //shape map or one map for every object (box,sphere...)??        

}