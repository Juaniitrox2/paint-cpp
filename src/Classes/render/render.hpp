#pragma once
#include "glad.h"
#include <vector>

class Render {
    public:

        static GLuint createVertexArrayObject();
        static GLuint createVertexBufferObject(const std::vector<float>& vertices);

        static void altDraw(GLuint VAO, GLuint VBO, GLenum mode);
        static void drawCircle(GLuint VAO, GLuint VBO, const std::vector<float>& vertices, GLenum mode);
        static void renderShaderObject(const char* source, GLenum shaderType, GLuint shaderProgram);
};