#include "scene.hpp"


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
        std::string i3;
        std::string i4;
        Material mat;
        Box box;
        Sphere sphere;
        Light light;

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
                    line_buffer >> i1 >> i2 >> i3
                    >>box.getName
                    >>box.getBoxMin
                    >>box.getBoxMax
                    >>box.getMaterial; 
                  
                	std::shared_ptr<Box>boxp = std::make_shared<Box>(box);
                  scene.box_map.insert(std::pair<std::string,std::shared_ptr<Box>> (boxp->getName,boxp));
                }
                if(i3 == "sphere") //read sphere datas
                {
                    line_buffer >> i1 >> i2 >> i3
                    >>sphere.getName
                    >>sphere.getSpMid
                    >>sphere.getSpRadius
                    >>sphere.getMaterial;
                  
                  std::shared_ptr<Sphere>spherep = std::make_shared<Sphere>(sphere);
                  scene.sphere_map.insert(std::pair<std::string,std::shared_ptr<Sphere>> (spherep->getName,spherep));
                }
            
            }
            if(i2 == "light")
            {
                line_buffer >> i1 >> i2 
                >>light.getName
                >>light.getPos
                >>light.getClr
                >>light.getBrightness;

                std::shared_ptr<Light>lightp = std::make_shared<Light>(light);
                scene.light_map.insert(std::pair<std::string,std::shared_ptr<Light>> (lightp->getName,lightp));
           
            }
        }        

    }
    file.close();

}
Color getPixelColor(Ray const& ray, Scene& scene)
{
    for(std::map<std::string, std::shared_ptr<Box>>::iterator it = scene.box_map.begin();it!=scene.box_map.end(); ++it)
    {
        if(it->first)
    }
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