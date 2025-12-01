#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/gtx/string_cast.hpp>

int main()
{
	glm::vec3 p(2, 1, 1);
	p=glm::translate(glm::mat3(1),glm::vec2(3,2))*glm::scale(glm::mat3(1),glm::vec2(2, 2))*p;
	std::cout << to_string(p) << std::endl;
	return 0;
}