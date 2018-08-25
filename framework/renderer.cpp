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
     // double d = (width_ / 2) / tan(51.5 / 2 * M_PI / 180);
      
      float distance = 100;
      glm::vec3 origin{400.0f, 300.0f ,0.0f};
      glm::vec3 direction{x-origin.x,y-origin.y, -100.0f};
      //direction = direction + glm::vec3{ x - (0.5 * width_),y - (0.5 * height_),d};
      Ray ray{origin,glm::normalize(direction)};
      
      if ( ((x/checker_pattern_size)%2) != ((y/checker_pattern_size)%2)) {
        p.color = Color(1.0, 1.0, 1.0);//float(x)/height_*2);
      } else {
        p.color = Color(0.0, 0.0, 0.0); //float(y)/width_*2);*
      }

      float cam_dist = 20000;
      shared_ptr<Shape> nearest_obj;
      
      for(auto i : scene.shape_vec)
      {
        
        if(i->intersect(ray, distance))
        {
          
          if(cam_dist>distance)
          {
            cam_dist = distance;
            i = nearest_obj;
            Hit hitp(true, cam_dist,  ;
          }
          p.color = i->getMaterial()->ka_;
        }
      }



      //p.color = getPixelColor(nearest_obj, ray, scene);
      

      write(p);
    }
  }

  ppm_.save(filename_);
}

Color Renderer::getPixelColor(std::shared_ptr<Shape> nearest_obj, Ray& ray, Scene& scene)
{   
    
    
}

/*Color Renderer::shadow(std::shared_ptr<Shape> Object, Ray& ray, Scene& scene){
    color.r += mat.kd_.r * (*it).ld_.r * (glm::dot(camHit.normvec_, lightRay.direction) + mat.ks_.r * r_v_);
    color.g += mat.kd_.g * (*it).ld_.g * (glm::dot(camHit.normvec_, lightRay.direction) + mat.ks_.g * r_v_);
    color.b += mat.kd_.b * (*it).ld_.b * (glm::dot(camHit.normvec_, lightRay.direction) + mat.ks_.b * r_v_);
            
}*/


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
