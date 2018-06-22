#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "../framework/sphere.hpp"
#include "../framework/box.hpp"
#include "../framework/color.hpp"

TEST_CASE("aufgabe 2 test")
{
  SECTION("radius test")
  {
    glm::vec3 mid{0.0,0.0,0.0};
    double rad{2.0};
    Color clr{0.0f,0.0f,0.0f};

    Sphere sp{mid,rad,"test",clr};
    REQUIRE(sp.area() == Approx(50.2655));
    REQUIRE(sp.getSpRadius() == 2.0);
    
    }
}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
