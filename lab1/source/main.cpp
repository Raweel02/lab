#define GLM_ENABLE_EXPERIMENTAL
#define GLM_SWIZZLE
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

int main()
{
	//Q1
	glm::ivec3 p(1, 4, -5);
	glm::ivec3 v(5, 1, 4);
	p = p + v;
	std::cout << glm::to_string(p) << std::endl << std::endl;
	//Q2
	glm::ivec3 v1(1, 0, 0);
	glm::ivec3 v2(0, 1, 0);
	std::cout << glm::to_string(v1 + v2) << std::endl << std::endl;
	//Q3
	glm::vec3 v3(0.0f, 1.0f, 0.0f);
	std::cout << glm::to_string(v3) << " length: " << glm::length(v3) << std::endl;
	v3 *= 2.0f;
	std::cout << glm::to_string(v3) << " length: " << glm::length(v3) << std::endl << std::endl;
	//Q4
	glm::ivec3 p1(8, 2, 5);
	glm::ivec3 p2(1, -1, 4);
	glm::ivec3 v4 = p2 - p1;
	std::cout << glm::to_string(v4) << std::endl << std::endl;
	//Q5
	glm::vec3 v5(1.0f, 3.0f, 4.0f);
	glm::vec3 normalized_v5 = glm::normalize(v5);
	std::cout << glm::to_string(normalized_v5) << std::endl << std::endl;
	//Q6
	glm::ivec3 v6(1, -1, 4);
	glm::ivec4 v6_4d(v6, 0);
	std::cout << glm::to_string(v6_4d) << std::endl;
	return 0;
}