#include <iostream>
#include <glad.h>
#include <vector>
#include <GLFW/glfw3.h>
#include "window.hpp"
#include "../color/color.hpp"
#include "Classes/render/render.hpp"
using namespace std;

Window::Window() {}
Window::Window(unsigned int width, unsigned int height, std::string name) {
    if (width <= 0 || height <= 0) {
        throw invalid_argument("Las dimensiones pasadas son inválidas, deben uint > 0");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE );
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //
    this->width = width;
    this->height = height;
    this->visible = false;
    this->name = name;

    this->pixel_buffer = new float[this->width * this->height * 3];
    this->window_object = glfwCreateWindow(this->width, this->height, name.c_str(), NULL, NULL);

    fill_n(pixel_buffer, width * height * 3, 0.0f);
    
    if (!this->window_object) {
        cout << "Error loading window" << endl;
        
        glfwTerminate();
    }
    
    this->focus();
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        cout << "Could not load opengl"<< endl;
        glfwTerminate();
        return;
    }

    this->VAO = Render::createVertexArrayObject();

    this->initShaders();
}

void Window::setPixelColor(int x, int y, Color* color) {
    if (x >= this->width || x < 0 || y >= this->height || y < 0) {
        return;
    }

    int flippedY = this->height - 1 - y;

    unsigned int pixelLocation = (flippedY * this->width * 3) + (x * 3);
    this->pixel_buffer[pixelLocation + 0] = color->r;
    this->pixel_buffer[pixelLocation + 1] = color->g;
    this->pixel_buffer[pixelLocation + 2] = color->b;
}

void Window::setAreaColor(int pos_x, int pos_y, int size_x, int size_y, Color* color) {
    for (int y = pos_y; y <= pos_y + size_y; y++) {
        for (int x = pos_x; x <= pos_x + size_x; x++) {
            this->setPixelColor(x, y, color);
        }
    }
}

void Window::focus() {
    glfwMakeContextCurrent(this->window_object);
}

void Window::setVisibility(bool state) {
    if (!this->window_object) return;

    if (state) {
        glfwShowWindow(this->window_object);
    } else {
        if (this->isFocused()) {
            glfwMakeContextCurrent(NULL);
        }

        glfwHideWindow(this->window_object);
    }

    this->visible = state;
}

void Window::setBackgroundColor(Color* new_color) {

}

void Window::update() {
    if (glfwWindowShouldClose(this->window_object)) {
        glfwMakeContextCurrent(NULL);
        glfwDestroyWindow(this->window_object);
        return;
    }

    glClear(GL_COLOR_BUFFER_BIT);
    
    glUseProgram(this->shaderProgram);  // Bind shader before drawing
    GLint windowSizeLoc = glGetUniformLocation(this->shaderProgram, "windowSize");
    glUniform2f(windowSizeLoc, this->width, this->height);

    for (const auto& buffer : this->rendered_buffers) {
        GLuint VBO = Render::createVertexBufferObject(buffer);
        
        Render::drawCircle(this->VAO, VBO, buffer, GL_TRIANGLE_FAN);
    }
    
    glfwPollEvents();
    glfwSwapBuffers(this->window_object);
}

void Window::addBufferToRender(const std::vector<float>& vertices) {
    this->rendered_buffers.push_back(vertices);
}

bool Window::isFocused() {
    return (glfwGetCurrentContext() == this->window_object);
}

bool Window::isVisible() {
    return this->visible;
}

GLFWwindow* Window::getGLWindow() {
    return this->window_object;
}

Window::~Window() {
    if (this->window_object) {
        if (this->isFocused()) {
            glfwMakeContextCurrent(NULL);
        }

        glfwDestroyWindow(this->window_object);
    }

    glDeleteVertexArrays(1, &VAO);

    delete pixel_buffer;
}

void Window::initShaders() {
    const char* vertexSource = R"glsl(
        #version 150 core
        uniform vec2 windowSize;
        in vec2 position;

        void main() {
            vec2 normalizedPos = (position/windowSize)*2.0 - 1.0;
            gl_Position = vec4(normalizedPos, 0.0, 1.0);
        }
    )glsl";

    const char* fragmentSource = R"glsl(
        #version 150 core
        out vec4 outColor;
        void main() {
            outColor = vec4(1.0, 1.0, 1.0, 1.0);
        }
    )glsl";

    // Create and compile vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    checkShaderCompileStatus(vertexShader, "Vertex");

    // Create and compile fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    checkShaderCompileStatus(fragmentShader, "Fragment");

    // Create shader program
    this->shaderProgram = glCreateProgram();
    glAttachShader(this->shaderProgram, vertexShader);
    glAttachShader(this->shaderProgram, fragmentShader);
    glLinkProgram(this->shaderProgram);

    // Check linking status
    GLint success;
    glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(this->shaderProgram, 512, NULL, infoLog);
        std::cerr << "Shader link error:\n" << infoLog << std::endl;
    }

    // Clean up shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    glUseProgram(this->shaderProgram);

    GLint posAttrib = glGetAttribLocation(this->shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
}

void Window::checkShaderCompileStatus(GLuint shader, const std::string& type) {
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << type << " shader compilation failed:\n" << infoLog << std::endl;
    }
}