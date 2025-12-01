#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/mat2x2.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat3x2.hpp>
#include <glm/gtx/string_cast.hpp>

int main()
{
	glm::vec4 v1 = { 1,2,3,4 };
	glm::vec4 v2 = { 5,6,7,8 };
	glm::vec4 v3 = { 9,10,11,12 };
	glm::vec4 v4 = { 13,14,15,16 };
	glm::mat4 m1 = { v1,v2,v3,v4 };
	std::cout << glm::to_string(m1) << std::endl;
	std::cout << m1[0][1] << std::endl;

	glm::mat2 m2 = { 1,0,1,0 };
	std::cout << glm::to_string(m2) << std::endl;

	glm::mat3x2 m3 = { 1,0,1,-1,0,1 };
	std::cout << glm::to_string(m3) << std::endl;

	glm::mat4 m4(1);
	std::cout << glm::to_string(m4) << std::endl;

	glm::mat2 m5 = { 1,0,1,-1 };
	m5 = m5 * 2.0f;
	std::cout << glm::to_string(m5) << std::endl;
	std::cout << std::endl;

	glm::mat3 m6 = { {1,1,-1},{0,2,0},{2,3,1} };
	glm::mat3 m7 = { {1,0,0},{0,-1,1},{0,1,2} };
	glm::mat3 m8 = m6 * m7;
	glm::mat3 m9 = m7 * m6;
	for (int i = 0; i < 3; i++)std::cout << glm::to_string(m8[i]) << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)std::cout << glm::to_string(m9[i]) << std::endl;
	std::cout << std::endl;

	glm::mat2 m10 = { {4,1},{8,3} };
	glm::mat2 im10 = glm::inverse(m10);
	std::cout << glm::to_string(im10) << std::endl;
	std::cout << glm::to_string(m10 * im10) << std::endl;
	std::cout << std::endl;

	glm::vec3 a(1, 2, 3);
	glm::mat3 m11 = { {1,0,0},{2,-1,0},{3,0,1} };
	std::cout << glm::to_string(a * m11) << std::endl;
	std::cout << glm::to_string(m11 * a) << std::endl;
	return 0;
}