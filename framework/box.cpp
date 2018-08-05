#include "box.hpp"

//#include <glm/gtx/norm.hpp>

Box::Box():
    Shape(),
    boxMin_({0.0,0.0,0.0}),
    boxMax_({0.0,0.0,0.0})
    {//std::cout << "b child default constructor \n ";
    };

Box::Box(std::string name, glm::vec3 const& boxMin, glm::vec3 const& boxMax, std::shared_ptr<Material> material):
    Shape{name, material},
    boxMin_{boxMin},
    boxMax_{boxMax}
    {//std::cout << "b child copy constructor \n ";
    };

Box::~Box()
{
    //std::cout << "b child deconstructor \n ";
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


bool Box::intersect ( Ray const & ray , float & t )
{
    auto origin = ray.origin;
    auto direction = ray.direction; 
    bool intersect = false;
    auto cam_dist = -1;

    if(direction.x!=0)
    {
        auto t1 = (boxMin_.x-origin.x)/direction.x;  //get t for x min
        auto t2 = (boxMax_.x-origin.x)/direction.x;  //get t for x max

        auto i1 = origin+t1*direction;               //intersection point with x
        auto i2 = origin+t2*direction;

        bool hitp1 = false;                         //hitpoint?
        bool hitp2 = false;
        if(i1.y>boxMin_.y && i1.y<boxMax_.y && i1.z>boxMin_.z && i1.z<boxMax_.z)  //test if the hitpoint is in range from yz level
        {
            hitp1 = true;
        }
        if(i2.y>boxMin_.y && i2.y<boxMax_.y && i2.z>boxMin_.z && i2.z<boxMax_.z)
        {
            hitp2 = true;
        }

        auto distance1 = sqrt(pow(i1.x-origin.x,2.0)+pow(i1.y-origin.y,2.0)+pow(i1.z-origin.z,2.0));
        //sqrt(pow(i1.x-origin.x,2.0)+pow(i1.y-origin.y,2.0)+pow(i1.z-origin.z,2.0)); //distance between hitpoint 1 and origin
        auto distance2 = sqrt(pow(i2.x-origin.x,2.0)+pow(i2.y-origin.y,2.0)+pow(i2.z-origin.z,2.0));
        //sqrt(pow(i2.x-origin.x,2.0)+pow(i2.y-origin.y,2.0)+pow(i2.z-origin.z,2.0)); //distance between hitpoint 2 and origin

        if(hitp1 && hitp2)  //box is infront/behind box
        {
            if(distance1<distance2) //box hits front side before back side of box 
            {
                if(distance1>0 && (distance1<cam_dist || cam_dist<0)) //distance1 vorhanden and camist < 0(so box is infront of cam) or cam dist default
                {
                    cam_dist=distance1;
                }
                else if(distance2>0 && (distance2<cam_dist || cam_dist<0)) //same like dist 1 just with distance2
                {
                    cam_dist=distance2;
                }
            }
            else 
            {
                if(distance2>0 && (distance2<cam_dist || cam_dist<0))
                {
                    cam_dist=distance2;
                }
                else if(distance1>0 && (distance1<cam_dist || cam_dist<0))
                {
                    cam_dist=distance1;
                }
            }    
            intersect = true;
        }
        if(hitp1)  //ray is inside box or hits edge of box
        {
            if(distance1>0 && (distance1<cam_dist || cam_dist<0))
                {
                    cam_dist=distance1;
                }
        }
        if(hitp2 ) //ray is inside box or hits edge of box
        {
             if(distance2>0 && (distance2<cam_dist || cam_dist<0))
                {
                    cam_dist=distance2;
                }
        }
    }

    if(direction.y!=0)
    {
        auto t1 = (boxMin_.y-origin.y)/direction.y;  //get t for x min
        auto t2 = (boxMax_.y-origin.y)/direction.y;  //get t for x max

        auto i1 = origin+t1*direction;               //intersection point with x
        auto i2 = origin+t2*direction;

        bool hitp1 = false;                         //hitpoint?
        bool hitp2 = false;
        if(i1.x>boxMin_.x && i1.x<boxMax_.x && i1.z>boxMin_.z && i1.z<boxMax_.z)  //test if the hitpoint is in range from yz level
        {
            hitp1 = true; //hit
        }
        if(i2.x>boxMin_.x && i2.x<boxMax_.x && i2.z>boxMin_.z && i2.z<boxMax_.z)
        {
            hitp2 = true;
        }

        auto distance1 = sqrt(pow(i1.x-origin.x,2.0)+pow(i1.y-origin.y,2.0)+pow(i1.z-origin.z,2.0)); //distance between hitpoint 1 and origin
        auto distance2 = sqrt(pow(i2.x-origin.x,2.0)+pow(i2.y-origin.y,2.0)+pow(i2.z-origin.z,2.0)); //distance between hitpoint 2 and origin

        if(hitp1 == true && hitp2 == true) //if the ray goes through the box
        {
            if(distance1<distance2) //check distance between camera/origin and hitpoint
            {
                if(distance1>0 && (distance1<cam_dist || cam_dist<0))
                {
                    cam_dist=distance1;
                }
                else if(distance2>0 && (distance2<cam_dist || cam_dist<0))
                {
                    cam_dist=distance2;
                }
            }
            else if(distance2<distance1)
            {
                if(distance2>0 && (distance2<cam_dist || cam_dist<0))
                {
                    cam_dist=distance2;
                }
                else if(distance1>0 && (distance1<cam_dist || cam_dist<0))
                {
                    cam_dist=distance1;
                }
            }    
            intersect = true;
        }
        if(hitp1 == true && hitp2 ==false)
        {
            if(distance1>0 && (distance1<cam_dist || cam_dist<0))
                {
                    cam_dist=distance1;
                }
        }
        if(hitp1 ==false && hitp2 == true)
        {
             if(distance2>0 && (distance2<cam_dist || cam_dist<0))
                {
                    cam_dist=distance2;
                }
        }
    }

    if(direction.z!=0)
    {
        auto t1 = (boxMin_.z-origin.z)/direction.z;  
        auto t2 = (boxMax_.z-origin.z)/direction.z; 

        auto i1 = origin+t1*direction;              
        auto i2 = origin+t2*direction;

        bool hitp1 = false;                         
        bool hitp2 = false;
        if(i1.y>boxMin_.y && i1.y<boxMax_.y && i1.x>boxMin_.x && i1.x<boxMax_.x)  
        {
            hitp1 = true;
        }
        if(i2.y>boxMin_.y && i2.y<boxMax_.y && i2.x>boxMin_.x && i2.x<boxMax_.x)
        {
            hitp2 = true;
        }

        auto distance1 = sqrt(pow(i1.x-origin.x,2.0)+pow(i1.y-origin.y,2.0)+pow(i1.z-origin.z,2.0)); 
        auto distance2 = sqrt(pow(i2.x-origin.x,2.0)+pow(i2.y-origin.y,2.0)+pow(i2.z-origin.z,2.0)); 

        if(hitp1 && hitp2)
        {
            if(distance1<distance2)
            {
                if(distance1>0 && (distance1<cam_dist || cam_dist<0))
                {
                    cam_dist=distance1;
                }
                else if(distance2>0 && (distance2<cam_dist || cam_dist<0))
                {
                    cam_dist=distance2;
                }
            }
            else if(distance2<distance1)
            {
                if(distance2>0 && (distance2<cam_dist || cam_dist<0))
                {
                    cam_dist=distance2;
                }
                else if(distance1>0 && (distance1<cam_dist || cam_dist<0))
                {
                    cam_dist=distance1;
                }
            }    
            intersect = true;
        }
        if(hitp1)
        {
            if(distance1>0 && (distance1<cam_dist || cam_dist<0))
                {
                    cam_dist=distance1;
                }
        }
        if(hitp2)
        {
             if(distance2>0 && (distance2<cam_dist || cam_dist<0))
                {
                    cam_dist=distance2;
                }
        }
    }
    t = cam_dist;
    return intersect;
    
}


std::ostream& Box::print(std::ostream& os) const
{
    os  << "area: " << area() <<"\n"
        << "volume: " << volume() <<"\n" ;
    return os;
}