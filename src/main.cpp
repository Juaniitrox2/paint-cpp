#include <iostream>
#include "glad.h"
#include <string>
#include <GLFW/glfw3.h>


int main(){
    GLFWwindow* window;

    if (!glfwInit()){
        return -1;
    }

    int width = 680;
    int height = 480; 

    window = glfwCreateWindow(width, height, "Paint Dih", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Could not load opengl"<< std::endl;
        glfwTerminate();
        return -1;
    }

    glClearColor(0.25f , 0.5f, 0.75f, 1.0f);

    while (!glfwWindowShouldClose(window)){
        glfwPollEvents();
        
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}