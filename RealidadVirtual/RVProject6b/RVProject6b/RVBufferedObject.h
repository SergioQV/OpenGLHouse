#ifndef RV_BUFFERED_OBJECT_H

#define RV_BUFFERED_OBJECT_H

#include <glew.h>

#define VERTEX_DATA     0
#define NORMAL_DATA     1
#define TEXTURE_DATA    2
#define INDEX_DATA      3

//
// CLASE: RVBufferedObject
//
// DESCRIPCIÓN: Clase abstracta que representa un objeto descrito mediante
//              buffer arrays
// 
class RVBufferedObject {
protected:
	GLushort* indexes;  // Array of indexes 
	GLfloat* vertices;  // Array of vertices
	GLfloat* normals;   // Array of normals
	GLfloat* textures;  // Array of texture coordinates

	GLuint numFaces;     // Number of faces
	GLuint numVertices;  // Number of vertices
	GLuint bufferObjects[4];

public:
	~RVBufferedObject();
	void InitBuffers();
	void Draw();
	void DrawList();
};

#endif