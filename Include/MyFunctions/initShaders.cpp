#include <Headers.hpp>
#include <initShaders.hpp>
#include <fstream>
#include <sstream>
#include <iostream>

enum shader
{
	Vertex,
	Fragment
};


void shaderLog(GLuint shader, int type)
{
	int success;
	char infoLog[512];

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(shader, sizeof(infoLog), NULL, infoLog);
		switch(type)
		{
			case Vertex:
			{
				std::cout << "Vertex: " << infoLog << std::endl;
				break;
			}
			case Fragment:
			{
				std::cout << "Fragment: " << infoLog << std::endl;
				break;
			}
		}
	}
}

void programLog(GLuint program)
{
	int success;
	char infoLog[512];

	glGetShaderiv(program, GL_LINK_STATUS, &success);
	if(!success)
	{	
		glGetProgramInfoLog(program, sizeof(infoLog), NULL, infoLog);
		std::cout << "Program: " << infoLog << std::endl;
	}
}

GLuint initShaders(const char *vertexPath, const char *fragmentPath)
{

	// GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// std::string vertexShaderString;
	// std::ifstream vertexShaderFile;
	// std::stringstream vertexShaderStream;
	// vertexShaderFile.open(vertexPath);
	// vertexShaderStream << vertexShaderFile.rdbuf();
	// vertexShaderString = vertexShaderStream.str();
	// const GLchar *vertexShaderCode = vertexShaderString.c_str();
	// glShaderSource(vertexShader, 1, &vertexShaderCode, NULL);
	// glCompileShader(vertexShader);
	// shaderLog(vertexShader, Vertex);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	std::string fragmentShaderString;
	std::ifstream fragmentShaderFile;
	std::stringstream fragmentShaderStream;
	fragmentShaderFile.open(fragmentPath);
	fragmentShaderStream << fragmentShaderFile.rdbuf();
	fragmentShaderString = fragmentShaderStream.str();
	const GLchar *fragmentShaderCode = fragmentShaderString.c_str();
	glShaderSource(fragmentShader, 1, &fragmentShaderCode, NULL);
	glCompileShader(fragmentShader);
	shaderLog(fragmentShader, Fragment);


	GLuint program = glCreateProgram();
	programLog(program);

	//glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	
	glLinkProgram(program);

	return program;
}