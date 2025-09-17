#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

int main()
{
	glm::vec3 v(1, 2, -1);
	glm::vec3 c(0, 1, 0);
	glm::vec3 b = c * glm::dot(v, c);
	glm::vec3 a = v - b;
	std::cout << "a = " << glm::to_string(a) << std::endl << "b = " << glm::to_string(b) << std::endl;
	return 0;
}