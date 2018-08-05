#include "light.hpp"


Light::Light():
    name_("light_Default"),
    pos_({0.0,0.0,0.0}),
    clr_({0.0,0.0,0.0}),
    brightness_(10)
    {};

Light::Light(std::string name, glm::vec3 const& pos, Color const& clr, int brightness):
    name_{name},
    pos_{pos},
    clr_{clr},
    brightness_{brightness}
    {};

Light::~Light()
{};

std::string Light::getName()
        {
            return name_;
}
glm::vec3 Light::getPos()
{
    return pos_;
}

Color Light::getClr()
{
    return clr_;
}

int Light::getBrightness()
{
    return brightness_;
}