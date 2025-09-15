#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

const double DEREES_TO_RADIANS = glm::pi<float>() / 180.0;
const double RADIANS_TO_DEGREES = 180.0 / glm::pi<float>();

int main()
{
	glm::vec3 v(2, -1, 1);
	glm::vec3 u(1, 1, 2);
	float rad = glm::acos(glm::dot(v, u) / (glm::length(u)*glm::length(v)));
	std::cout << rad * RADIANS_TO_DEGREES << std::endl;
	return 0;
}