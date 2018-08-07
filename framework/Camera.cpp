#include "camera.hpp"

using namespace std;

Camera::Camera():
    name_("StandardCam"),
    dist_(0.0f),
    angle_(0.0f),
    pos_({0.0f, 0.0f, 0.0f}), //in the center 
    dir_({0.0f, 0.0f, -1.0f}), //negative z axis
    up_({0.0f, 1.0f, 0.0f})
    {};

//for adjusting the camera at angle
Camera::Camera(string const& name, float fov, glm::vec3 const& pos):
    name_(name),
    angle_(fov),
    dist_(0.0f),
    pos_(pos),
    dir_({0.0f, 0.0f, -1.0f}),
    up_({0.0f, 1.0f, 0.0f})
    {
        float radius = (angle_ * M_PI/360);
        dist_ = 0.5/(tan(radius));
        
    };

Camera::~Camera(){

};

// to do -- create Ray and matrix

string Camera::getName() const{
    return name_;
}    

glm::vec3 Camera::getPos() const{
    return pos_;
}

float Camera::getAngle() const{
    return angle_;
}

float Camera::getDist() const{
    return dist_;
}
