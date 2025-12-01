#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/string_cast.hpp>

int main()
{
	glm::vec3 camPos(5, 5, 5);
	glm::vec3 look(0, 0, 0);
	glm::vec3 up(0, 1, 0);
	std::cout << glm::to_string(lookAt(camPos, look, up)) << std::endl;
	return 0;
}

glm::mat4 lookAt(glm::vec3 campos, glm::vec3 look, glm::vec3 up)
{
	glm::mat4 tr = glm::translate(glm::mat4(1), -campos);
	glm::vec3 z = glm::normalize(look - campos);
	glm::vec3 x = glm::normalize(up * z);
	glm::vec3 y = glm::normalize(z * x);
	glm::vec4 c1(x[0], y[0], z[0], 0);
	glm::vec4 c2(x[1], y[1], z[1], 0);
	glm::vec4 c3(x[2], y[2], z[2], 0);
	glm::vec4 c4(0, 0, 0, 1);
	glm::mat4 ro(c1, c2, c3, c4);
	return ro*tr;
}