
#define GLM_ENABLE_EXPERIMENTAL 
#include "MyGlWindow.h"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

MyGlWindow::MyGlWindow(int w, int h)

//==========================================================================
{
	m_width = w;
	m_height = h;

	setupBuffer();

}




void MyGlWindow::setupBuffer()
{
	GLfloat vertices[] = {
		-1.0, -1.0, 1.0,1,1.0, 0.0, 0.0,
		1.0,-1.0, 1.0,1,0.0, 1.0, 0.0,
		1.0, 1.0, 1.0,1,0.0, 0.0, 1.0,
		-1.0, 1.0, 1.0,1,1.0, 1.0, 1.0,
		-1.0, -1.0,-1.0,1,1.0, 0.0, 0.0,
		1.0,-1.0,-1.0,1,0.0, 1.0, 0.0,
		1.0, 1.0,-1.0,1,0.0, 0.0, 1.0,
		-1.0, 1.0,-1.0,1,1.0, 1.0, 1.0,
	};
	GLfloat cube_vertices[] = {
		// front
		-1.0, -1.0, 1.0,1,
		1.0,-1.0, 1.0,1,
		1.0, 1.0, 1.0,1,
		-1.0, 1.0, 1.0,1,
		// back
		-1.0, -1.0,-1.0,1,
		1.0,-1.0,-1.0,1,
		1.0, 1.0,-1.0,1,
		-1.0, 1.0,-1.0,1,
	};
	GLfloat cube_colors[] = {
		// front colors
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0,
		1.0, 1.0, 1.0,
		// back colors
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0,
		1.0, 1.0, 1.0,
	};
	GLushort cube_elements[] = {
0, 1, 2, 2, 3, 0, 1, 5, 6,
6, 2, 1, 7, 6, 5, 5, 4, 7,
4, 0, 3, 3, 7, 4, 4, 5, 1,
1, 0, 4, 3, 2, 6, 6, 7, 3,
	};


	shaderProgram = std::make_unique<ShaderProgram>();
	
	//load shaders
	shaderProgram->initFromFiles("shaders/simple.vert", "shaders/simple.frag");

	//interleave : dsa

	//하나의 버퍼만을 이용함 : 0  binding index
	GLuint VBO, elementVBO;
	glCreateVertexArrays(1, &vaoHandle);
	glCreateBuffers(1, &VBO);  //Gluint ibo_cube_elements
	glCreateBuffers(1, &elementVBO);
	glNamedBufferData(VBO, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glNamedBufferData(elementVBO, sizeof(cube_elements), cube_elements, GL_STATIC_DRAW);
	glVertexArrayElementBuffer(vaoHandle, elementVBO);
	//0번 index에 sizeof(GLfloat)*7 간격으로 데이터를 가져오도록 설정
	glVertexArrayVertexBuffer(
		vaoHandle,    //vao 
		0, //binding index
		VBO, //buffer
		0, //offset : 바로 시작하기 때문에 0
		sizeof(float) * 7  //stride : // 7는 위치와 색상 포함
	);


	// 위치 속성 설정
	glVertexArrayAttribFormat(
		vaoHandle, //vao
		0,   //attribute index
		4, //data per vertex
		GL_FLOAT,
		GL_FALSE,
		0); //offset : binding index에서부터 상대적인 offset
	glVertexArrayAttribBinding(vaoHandle, 0, 0);  //attribute index, binding index을 연결
	glEnableVertexArrayAttrib(vaoHandle, 0); //enable attribute 0

	// 색상 속성 설정
	glVertexArrayAttribFormat(
		vaoHandle,
		1, //attribute index
		3,  //data per vertex
		GL_FLOAT,
		GL_FALSE,
		sizeof(float) * 4);  //offset : binding index에서부터 상대적인 offset
	glVertexArrayAttribBinding(vaoHandle, 1, 0);  //attribute index, binding index을 연결
	glEnableVertexArrayAttrib(vaoHandle, 1); //enable attribute 1

}

void MyGlWindow::draw(void)
{
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shaderProgram->use(); //call shader
	glBindVertexArray(vaoHandle);
	int size;
	glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
	glDrawElements(GL_TRIANGLES, size / sizeof(GLushort), GL_UNSIGNED_SHORT, 0);

	shaderProgram->disable();


}
