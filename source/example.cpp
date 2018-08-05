#include "fensterchen.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "box.hpp"

int main(int argc, char* argv[])
{
  Window win{glm::ivec2{800,800}};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    auto t = win.get_time();
    auto m = win.mouse_position();

    win.update();
  }

  return 0;
}



   /* glm::vec3 min1{-1.0,-1.0,-2.0};
    glm::vec3 max1{1.0,1.0,-3.0};
    Color clr{1.0,0.0,0.0};
    std::shared_ptr<Material> mat = std::make_shared<Material>("red",clr,clr,clr,32);
    Box box2{"anotherRedBox",min1,max1,mat};*/