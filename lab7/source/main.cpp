#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/string_cast.hpp>

int main()
{
	glm::vec4 modelP(4, 5, 3, 1);
	glm::vec3 scaleVec(1, 1, 1);
	glm::vec3 transVec(0, 0, 0);
	float xrot = 0, yrot = 0, zrot = 0;
	glm::mat4 scaleMat = glm::scale(glm::mat4(1), scaleVec);
	glm::mat4 transMat = glm::translate(glm::mat4(1), transVec);
	glm::mat4 xrotMat = glm::rotate(glm::mat4(1), glm::radians(xrot), glm::vec3(1, 0, 0));
	glm::mat4 yrotMat = glm::rotate(glm::mat4(1), glm::radians(yrot), glm::vec3(0, 1, 0));
	glm::mat4 zrotMat = glm::rotate(glm::mat4(1), glm::radians(zrot), glm::vec3(0, 0, 1));
	glm::mat4 modelMat = transMat * scaleMat * xrotMat * zrotMat * yrotMat;
	glm::vec4 worldP = modelMat * modelP;
	
	//std::cout << to_string(modelMat) << std::endl;
	//std::cout << to_string(worldP) << std::endl << std::endl;

	glm::vec3 camPos(5, 5, 5);
	glm::vec3 look(0, 0, 0);
	glm::vec3 up(0, 1, 0);

	glm::mat4 testViewMat = { {0.67f, -0.5f, 0.55f, 0},{0, 0.74f, 0.67f, 0},{-0.74f, -0.45f, 0.49f,0},{0,0,-32.69,1} };
	glm::mat4 invViewMat = glm::inverse(testViewMat);
	camPos = invViewMat[3];

	glm::mat4 viewMat = lookAt(camPos, look, up);
	std::cout << "Original View" << std::endl << to_string(testViewMat) << std::endl;
	std::cout << "My View" << std::endl << to_string(viewMat) << std::endl;

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