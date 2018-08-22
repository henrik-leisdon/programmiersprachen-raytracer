// -----------------------------------------------------------------------------
// Copyright  : (C) 2014-2017 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#include "renderer.hpp"



Renderer::Renderer(unsigned w, unsigned h, std::string const& file)
  : width_(w)
  , height_(h)
  , color_buffer_(w*h, Color(0.0, 0.0, 0.0))
  , filename_(file)
  , ppm_(width_, height_)
{}

void Renderer::render(Scene& scene, int frame)
{
  std::size_t const checker_pattern_size = 20;
  Scene scene1;
  
  
  for (int y=0; y < height_; ++y) {
    for (int x = 0; x < width_; ++x) {
      Pixel p(x,y);
      


      glm::vec3 origin{300.0f, 150.0f ,0.0f};
      glm::vec3 direction{x-origin.x,y-origin.y, -100.0f};
      Ray ray{origin,direction};
      
      
      
      p.color = getPixelColor(ray, scene, direction.z);
      
      p.color = Color(0.5,0.5,0.5);      

      write(p);
    }
  }

  ppm_.save(filename_);
}

Color Renderer::getPixelColor(Ray const& ray, Scene& scene, float dist)
{   
    std::vector<std::shared_ptr<Shape>> intersected;
 
    for (auto i : scene.shape_vec)
    {       
        if(i->intersect(ray, dist) == true)
        {
          intersected.push_back(i);
          return Color(1,1,1);
          //return i->getMaterial()->ks_;
            
        }
        else
        {
          return Color(0.5,0.5,0.5);
        }
      }
    
  
}

void Renderer::write(Pixel const& p)
{
  // flip pixels, because of opengl glDrawPixels
  size_t buf_pos = (width_*p.y + p.x);
  if (buf_pos >= color_buffer_.size() || (int)buf_pos < 0) {
    std::cerr << "Fatal Error Renderer::write(Pixel p) : "
      << "pixel out of ppm_ : "
      << (int)p.x << "," << (int)p.y
      << std::endl;
  } else {
    color_buffer_[buf_pos] = p.color;
  }

  ppm_.write(p);
}








      /*if ( ((x/checker_pattern_size)%2) != ((y/checker_pattern_size)%2)) {
        p.color = Color(1.0, 1.0, 1.0);//float(x)/height_*2);
      } else {
        p.color = Color(0.0, 0.0, 0.0); //float(y)/width_*2);*
      }*/
