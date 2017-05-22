#version 400 core

in vec2 oTexCoord;

out vec4 color;

uniform sampler2D ourTexture;

void main()
{
    color = texture(ourTexture, oTexCoord);
} 