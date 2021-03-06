#include <renderer.hpp>
#include "scene.hpp"
#include <window.hpp>

#include <GLFW/glfw3.h>
#include <thread>
#include <utility>
#include <cmath>



int main(int argc, char* argv[])
{
  unsigned const image_width = 800;
  unsigned const image_height = 600;
  std::string const filename = "./checkerboard.ppm";

  std::shared_ptr<Scene> szene = std::make_shared<Scene>();
  read_SDF("/home/thetrippleh/Dokumente/Grive/Uni/git/buw_programmiersprachen/programmiersprachen-raytracer/framework/materials.sdf",*szene);
  
  

  Renderer renderer{image_width, image_height, filename};

  renderer.render(*szene, 1);

  //create separate thread to see updates of pixels while rendering
  //std::thread render_thread([&renderer]() {renderer.render(*scene, );});

  Window window{{image_width, image_height}};

  while (!window.should_close()) {
    if (window.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      window.close();
    }
    window.show(renderer.color_buffer());
   
  }

  //"join" threads, i.e. synchronize main thread with render_thread
  //render_thread.join();
  return 0;
}
