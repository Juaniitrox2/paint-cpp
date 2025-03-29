#ifndef VERTEX_SHADER
#define VERTEX_SHADER

const char* vertex_shader_source = R"glsl(#version 150 core

in vec2 position;

void main()
{
    gl_Position = vec4(position, 0.0, 1.0);
}
)glsl";

#endif