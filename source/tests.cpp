#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "../framework/sphere.hpp"
#include "../framework/box.hpp"
#include "../framework/color.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

TEST_CASE("aufgabe 2 test")
{
  SECTION("radius test")
  {
    glm::vec3 max{3.0,2.0,1.0};
    glm::vec3 mid{0.0,0.0,0.0};
    double rad{2.0};
    Color clr{0.0f,0.0f,0.0f};

    Box box1{};
    Box box2{"box",mid,max,clr};

    Sphere sp{mid,rad,"sp1",clr};

    REQUIRE(box2.area() == Approx(22.0));
    REQUIRE(box2.volume() == Approx(6.0));
    REQUIRE(sp.area() == Approx(50.2655));
    REQUIRE(sp.volume() == Approx(25.1327));
    REQUIRE(sp.getSpRadius() == 2.0);
    std::cout <<"----------------------------\n";
    std::cout <<sp;
    std::cout <<box2 <<"\n" <<"\n";
    std::cout <<box1;
    std::cout << "----------------------------\n";
    }
}



TEST_CASE("intersect_ray_sphere", "[intersect]")
{
	// Ray
glm::vec3 ray_origin{0.0f, 0.0f, 0.0f};
// ray direction has to be normalized !
// you can use:
// v = glm::normalize(some_vector)
glm::vec3 v = glm::normalize(ray_origin);
glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};
// Sphere
glm::vec3 sphere_center{0.0f ,0.0f, 5.0f};
float sphere_radius{1.0f};
float distance = 0.0f;
auto result = glm::intersectRaySphere(ray_origin, ray_direction,sphere_center, sphere_radius * sphere_radius, // squared radius !!!
distance);
REQUIRE(distance == Approx(4.0f));


}

TEST_CASE("deconstuctor")





int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
