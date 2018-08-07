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

void Renderer::render()
{
  std::size_t const checker_pattern_size = 20;

  for (int y= 0-(height_/2); y < height_/2; ++y) {
    for (int x = 0 - (width_/2) ; x < (width_/2); ++x) {
      Pixel p(x,y);
      
      Scene scene;
      glm::vec3 origin{0.0f,0.0f,0.0f};
      glm::vec3 direction{x-origin.x,y-origin.y, -100.0f};
      Ray ray{origin,direction};
      scene.getPixelColor(ray);

      

      write(p);
    }
  }

  ppm_.save(filename_);
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
