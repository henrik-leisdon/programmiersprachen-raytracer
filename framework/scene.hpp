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



struct Scene
{

        std::map <std::string, std::shared_ptr< Material>> material_map;
        //std::map <std::string,std::shared_ptr< Light>> light_map;   //shape map or one map for every object (box,sphere...)??   
  		std::vector <std::shared_ptr< Shape>> shape_vec;

};

    shared_ptr<Material> find_material(std::string matName, Scene& sc);






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

        std::string define, shape_mat, obj_col, s1, s6, s8;

        int i2, i3, i4, i5, i7, i9, i10, i11;

        Material mat;

        line_buffer >> define >> shape_mat >> obj_col >> s1 >> i2 >> i3 >> i4 >> i5 >> s6 >> i7 >> s8 >> i9 >> i10 >> i11;

        if(define == "define")
        {
            if(shape_mat == "material")
            {
                
                mat.name_=obj_col; 
                int i1 = atoi(s1.c_str());
                mat.ka_.r=i1;
                mat.ka_.g=i2;
                mat.ka_.b=i3;
                int i6 = atoi(s6.c_str());
                mat.kd_.r=i4;
                mat.kd_.g=i5;
                int i8 = atoi(s8.c_str());
                mat.kd_.b=i6;
                mat.ks_.r=i7;
                mat.ks_.g=i8;
                mat.ks_.b=i9;
                mat.m_=i10;

                std::shared_ptr<Material>matp = std::make_shared<Material>(mat);
                scene.material_map.insert(std::pair<std::string,std::shared_ptr<Material>> (matp->name_,matp));
            
                std::cout << "\n add mat " <<mat.name_;  
            }
          	
        
            if(shape_mat == "shape") //get shape datas

            {
                if( obj_col== "box") //read box data
                {
                    glm::vec3 boxmin = glm::vec3{i2, i3, i4};
                    int i6 = atoi(s6.c_str());
                    glm::vec3 boxmax = glm::vec3{i5, i6, i7};
                    shared_ptr<Material> matbox = scene.material_map.at(s8);
                    Box box_o = Box(s1, boxmin, boxmax, matbox);
                  
                	std::shared_ptr<Box>boxp = std::make_shared<Box>(box_o);
                  scene.shape_vec.push_back(boxp);

                  std::cout << "\n add box " <<s1;
                }
                if(obj_col == "sphere") //read sphere datas
                {
                    shared_ptr<Material> matsphere = scene.material_map.at(s6);
                    glm::vec3 spMid = glm::vec3{i2, i3, i4};
                    Sphere sphere_o = Sphere(spMid,i4,s1,matsphere);
                  
                  std::shared_ptr<Sphere>spherep = std::make_shared<Sphere>(sphere_o);
                  scene.shape_vec.push_back(spherep);

                  std::cout << "\n add sphere " <<s1;
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
    auto size  = scene.shape_vec.size();
    std::cout << "\n vec size: \n" << size;

    }
    file.close();

}
  
  		

        


#endif