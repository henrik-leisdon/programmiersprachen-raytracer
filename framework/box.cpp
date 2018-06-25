#include "box.hpp"

Box::Box():
    Shape(),
    boxMin_({0.0,0.0,0.0}),
    boxMax_({0.0,0.0,0.0})
    {std::cout << "b child default constructor \n ";};

Box::Box(std::string name, glm::vec3 const& boxMin, glm::vec3 const& boxMax, Color color):
    Shape{name,color},
    boxMin_{boxMin},
    boxMax_{boxMax}
    {std::cout << "b child copy constructor \n ";};

Box::~Box()
{
    std::cout << "b child deconstructor \n ";
};

glm::vec3 Box::getBoxMin()
{
    return boxMin_;
}

glm::vec3 Box::getBoxMax()
{
    return boxMax_;
}

double Box::area() const
{
    double lenght{boxMax_.x-boxMin_.x};
    double height{boxMax_.y-boxMin_.y};
    double width{boxMax_.z-boxMin_.z};

    return 2*lenght*height+2*lenght*width+2*height*width;
}

double Box::volume() const
{
    return (boxMax_.x-boxMin_.x)*(boxMax_.y-boxMin_.y)*(boxMax_.z-boxMin_.z);
}


std::ostream& Box::print(std::ostream& os) const
{
    os  << "area: " << area() <<"\n"
        << "volume: " << volume() <<"\n" ;
    return os;
}