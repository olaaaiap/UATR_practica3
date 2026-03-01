#version 330   

uniform sampler2D colorText; //unidad de textura de color
uniform bool useColorText;
uniform vec4 colorRGBA;

in vec2 fTexCoord;

out vec4 fragColor;  

void main()  
{  
    vec4 tColor = vec4(0, 0, 0, 0);
    if(useColorText)
        tColor=texture(colorText, fTexCoord);

    fragColor = colorRGBA+tColor; //asignar color de salida
}  