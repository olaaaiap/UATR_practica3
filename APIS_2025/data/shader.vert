#version 330   
uniform mat4 mMat; 


in vec4 vPos;  
attribute vec2 vTexCoord;

out vec2 fTexCoord;


void main()  
{  
	gl_Position=mMat*vPos;  
	fTexCoord = vTexCoord;
}  