#include "hit.hpp"

Hit::Hit():
    hit_(false),
    dist_(0.0f),
    inters_({0.0f, 0.0f, 0.0f}),
    normvec_({0.0f, 0.0f, 0.0f}),
    matname_("Material"),
    type_(" "){};

Hit::Hit(bool hit, float distance, glm::vec3 const& intersec, glm::vec3 const& normvec, std::string const& mat, std::string const& type):
    hit_(hit),
    dist_(distance),
    inters_(intersec),
    normvec_(normvec),
    matname_(mat),
    type_(type){};

/*
void Hit::transHit(glm::mat4 const& mat, glm::mat4 const& trans) {
    glm::vec4 inters_4 {inters_, 1.0f};
    glm::vec4 normvec_4 {normvec_, 0.0f};
	glm::vec3 temp(mat * inters_4);
	inters_ = temp;
	glm::vec3 tomp(mat * normvec_4);
	normvec_ = glm::normalize(temp);
}
*/