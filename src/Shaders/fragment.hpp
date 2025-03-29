#ifndef FRAGMENT_SHADER
#define FRAGMENT_SHADER

const char* fragment_shader_source = R"glsl(
    #version 150 core

    out vec4 outColor;

    void main()
    {
        outColor = vec4(1.0, 1.0, 1.0, 1.0);
    }
)glsl";

#endif