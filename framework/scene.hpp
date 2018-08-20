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
//#include "light.hpp"



class Scene
{
    public:

        std::map <std::string,std::shared_ptr< Material>> material_map;
        //std::map <std::string,std::shared_ptr< Light>> light_map;   //shape map or one map for every object (box,sphere...)??   
  		std::map <std::string,std::shared_ptr< Shape>> shape_map;

};

    static void read_SDF(std::string const& path, Scene& scene)
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
        std::string i3;
        std::string i4;
        Material mat;
        Box box;
        Sphere sphere;
        //Light light;

        line_buffer >> i1 >> i2 >>i3 >> i4;

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
          	
          	//template map for reading objects into the scene

            if(i2 == "shape") //get shape datas
            {
                if(i3 == "box") //read box data
                {
                    std::string boxname;
                    int boxminx, boxminy, boxminz;
                    int boxmaxx, boxmaxy, boxmaxz;
                    std::string boxmat;

                    line_buffer >> i1 >> i2 >> i3
                    >> boxname
                    >>boxminx  >>boxminy >>boxminz
                    >>boxmaxx  >>boxmaxy >>boxmaxz
                    >>boxmat; 
                  
                	std::shared_ptr<Box>boxp = std::make_shared<Box>(box);
                  scene.shape_map.insert(std::pair<std::string,std::shared_ptr<Box>> (boxname ,boxp));
                }
                if(i3 == "sphere") //read sphere datas
                {
                    std::string spherename, spheremat;
                    int spcenterx, spcentery, spcenterz, spradius;

                    line_buffer >> i1 >> i2 >> i3
                    >>spherename
                    >>spcenterx >>spcentery >>spcenterz
                    >>spradius
                    >>spheremat;
                  
                  std::shared_ptr<Sphere>spherep = std::make_shared<Sphere>(sphere);
                  scene.shape_map.insert(std::pair<std::string,std::shared_ptr<Sphere>> (spherename,spherep));
                }
            
            }
            /*if(i2 == "light")
            {
                std::string lightname;
                int lightposx, lightposy, lightposz, lcolr, lcolg, lcolb, brightness;



                line_buffer >> i1 >> i2 
                >>lightname
                >>lightposx >>lightposy >>lightposz
                >>lcolr >>lcolg >>lcolb
                >>brightness;

                std::shared_ptr<Light>lightp = std::make_shared<Light>(light);
                scene.light_map.insert(std::pair<std::string,std::shared_ptr<Light>> (lightname,lightp));
           
            }*/
        }        

    }
    file.close();

}
  
  		

        shared_ptr<Material> find_material(std::string matName, Scene& sc);


#endif