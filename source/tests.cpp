
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include <memory>
#include "../framework/sphere.hpp"
#include "../framework/box.hpp"
#include "../framework/color.hpp"
#include "../framework/scene.hpp"
#include "../framework/material.hpp"


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

/*TEST_CASE("aufgabe 2 test")
{
 
 
    glm::vec3 max{3.0,2.0,1.0};
    glm::vec3 mid{0.0,0.0,0.0};
    double rad{2.0};
    Color clr{0.0f,0.0f,0.0f};
    std::shared_ptr<Material> material =std::make_shared<Material>("red",clr,clr,clr,1);

    Box box1{};
    Box box2{"box",mid,max,material};

    Sphere sp{mid,rad,"sp1",material};

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
    REQUIRE(distance == Approx(4.0f)); //normalisiere

    //custom sp:

    glm::vec3 mid(0.0,0.0,5.0);
    double rad(1.0);
    Color clr(1.0f,0.0f,0.0f);
    std::shared_ptr<Material> material =std::make_shared<Material>("red",clr,clr,clr,1);

    Sphere sp{mid,rad,"sp1",material};

    float dist = 0.0f;
    REQUIRE(!sp.intersect(Ray{},distance));
    REQUIRE(distance == Approx(-4.0f));

    glm::vec3 mid2{0.0,0.0,-5.0};
    double rad2(1.0);
    Sphere sp2{mid2,rad,"sp2",material};

    REQUIRE(sp2.intersect(Ray{},distance));


}

/*TEST_CASE("de/constuctor")
{
  std::cout << "===============================\n";
  Color red{255,0,0};
  std::shared_ptr<Material> material =std::make_shared<Material>("red",red,red,red,1);

  glm::vec3 position {0.0,0.0 ,0.0};
  Sphere* s1 = new Sphere{position,1.2f,"sphere0", material};
  Shape* s2 = new Sphere{position,1.2f,"sphere1",material};
  
  s1-> print(std::cout);
  s2-> print(std::cout);

  delete s1;
  delete s2;

}
*/
TEST_CASE("Testing Box")
{
  glm::vec3 min{0.0,1.0,2.0};
  glm::vec3 max{4.0,6.0,7.0};
  Color clr{1.0,0.0,0.0};
  std::shared_ptr<Material> mat = std::make_shared<Material>("red",clr,clr,clr,32);
  Box box{"red-box",min,max,mat};
  
  

  SECTION("constructor")
  {
    std::cout << "Aufgabenblatt 6 Tests: \n \n";  
    REQUIRE(box.getBoxMin().x == 0.0);
    REQUIRE(box.getBoxMin().y == 1.0);
    REQUIRE(box.getBoxMin().z == 2.0);
  
  }

  SECTION("print")
  {
    std::cout << box;
  }

  SECTION("intersect")
  {
    
    
    //no hit:
    float dist = 0.0f;
    REQUIRE(!box.intersect(*new Ray{}, dist));

    //ray cuts front:

      glm::vec3 min1{-1.0,-1.0,-2.0};
      glm::vec3 max1{1.0,1.0,-3.0};
      Box box2{"anotherRedBox",min1,max1,mat};
      glm::vec3 origin2{0.0f,0.0f,0.0f};
      glm::vec3 direction2{0.0f,0.0f,-1.0f};
      Ray ray1{origin2,direction2};

      REQUIRE(box2.intersect(ray1,dist));
      REQUIRE(dist>0);

      //box is behind ray:

      glm::vec3 min2{-1.0,-1.0,2.0};
      glm::vec3 max2{1.0,1.0,3.0};
      Box box3{"RedBox3",min2,max2,mat};
      glm::vec3 origin3{0.0f,0.0f,0.0f};
      glm::vec3 direction3{0.0f,0.0f,-1.0f};
      Ray ray2{origin3,direction3};
      dist = -1;
      REQUIRE(box3.intersect(ray2, dist));

      //ray inside box
      glm::vec3 min3{-3.0,-1.5,-2.0};
      glm::vec3 max3{2.0,2.5,-3.5};
      Box box4{"RedBox4",min3,max3,mat};
      dist = -1;
      
      REQUIRE(box4.intersect(ray1, dist));
      REQUIRE(dist >0);

      Material mat2{"red",clr,clr,clr,32};

      std::cout << "\n" << mat2 <<"\n";
      

  }
}

TEST_CASE("read sdf")
{
  std::shared_ptr<Scene> scene = std::make_shared<Scene>();
  read_SDF("/home/thetrippleh/Dokumente/Grive/Uni/git/buw_programmiersprachen/programmiersprachen-raytracer/framework/materials.sdf",*scene);
  std::cout << "material green: " ;
  if(find_material("green", *scene)==0) 
  std::cout << "green"; 
  std::cout << "\n";


  REQUIRE(find_material("pink",*scene) == nullptr);

}





