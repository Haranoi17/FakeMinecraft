#include <Headers.hpp>
#include <initShaders.hpp>
#include <fstream>
#include <sstream>

GLuint initShaders(const char *vertexPath, const char *fragmentPath)
{

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vertexShaderString;
	std::string fragmentShaderString;

	std::ifstream vertexShaderFile;
	std::ifstream fragmentShaderFile;

	std::stringstream vertexShaderStream;
	std::stringstream fragmentShaderStream;
	
	vertexShaderFile.open(vertexPath);
	fragmentShaderFile.open(fragmentPath);

	vertexShaderStream << vertexShaderFile.rdbuf();
	fragmentShaderStream << fragmentShaderFile.rdbuf();

	vertexShaderString = vertexShaderStream.str();
	fragmentShaderString = fragmentShaderStream.str();

	const GLchar *vertexShaderCode = vertexShaderString.c_str();
	const GLchar *fragmentShaderCode = fragmentShaderString.c_str();

	glShaderSource(vertexShader, 1, &vertexShaderCode, NULL);
	glShaderSource(fragmentShader, 1, &fragmentShaderCode, NULL);

	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	GLuint program = glCreateProgram();

	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	
	glLinkProgram(program);

	return program;
}