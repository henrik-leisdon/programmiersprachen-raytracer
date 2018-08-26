// -----------------------------------------------------------------------------
// Copyright  : (C) 2014-2017 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#ifndef BUW_RENDERER_HPP
#define BUW_RENDERER_HPP

#include "color.hpp"
#include "hit.hpp"
#include "pixel.hpp"
#include "ppmwriter.hpp"
#include <string>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include "scene.hpp"
#include "ray.hpp"
#include <cmath>


class Renderer
{
public:
  Renderer(unsigned w, unsigned h, std::string const& file);

  void render(Scene& scene, int frame);

  Color calc_reflection(std::shared_ptr<Shape> Object, Ray& ray, Scene& scene);

  Color getPixelColor(std::shared_ptr<Shape> Object, Ray& ray, Scene& scene);

  void write(Pixel const& p);

  inline std::vector<Color> const& color_buffer() const
  {
    return color_buffer_;
  }

  Color shadow(std::shared_ptr<Shape> Object, Ray& ray, Scene& scene);

private:
  unsigned width_;
  unsigned height_;
  std::vector<Color> color_buffer_;
  std::string filename_;
  PpmWriter ppm_;
};

#endif // #ifndef BUW_RENDERER_HPP
