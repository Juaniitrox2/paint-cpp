#include "render.hpp"
#include "glad.h"
#include <iostream>

GLuint Render::createVertexArrayObject() {
    GLuint vertexArray;
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);

    return vertexArray;
}

void Render::renderShaderObject(const char* source, GLenum shaderType, GLuint shaderProgram) {
    GLuint shaderObject = glCreateShader(shaderType);
    glShaderSource(shaderObject, 1, &source, NULL);
    glCompileShader(shaderObject);
    glAttachShader(shaderProgram, shaderObject);
}

GLuint Render::createVertexBufferObject(const std::vector<float>& vertices) {
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    return vertexBuffer;
}

void Render::drawCircle(GLuint VAO, GLuint VBO, const std::vector<float>& vertices, GLenum mode) {
    // add logic
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizei>(vertices.size() * sizeof(float)), vertices.data(), GL_STATIC_DRAW);
    glDrawArrays(mode, 0, static_cast<GLsizei>(vertices.size() / 2));
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
    //glDeleteBuffers(1, &VBO);
}

void Render::altDraw(GLuint VAO, GLuint VBO, GLenum mode) {
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    // Set vertex attribute (position = layout location 0 in shader)
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    
    // Draw (assuming 32 vertices in the circle)
    glDrawArrays(mode, 0, 32);
    
    // Cleanup (optional)
    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}