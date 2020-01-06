
#include "stdafx.h"
#include <glew.h>
#include "RVBufferedObject.h"

RVBufferedObject::~RVBufferedObject()
{
	if(vertices != NULL) delete[] vertices;
	if(normals != NULL) delete[] normals;
	if(textures != NULL) delete[] textures;
	if(indexes != NULL) delete[] indexes;

	// Delete buffer objects
	glDeleteBuffers(4, bufferObjects);
}

void RVBufferedObject::InitBuffers()
{
	// Create the buffer objects
	glGenBuffers(4, bufferObjects);

	// Copy data to video memory
	// Vertex data
	glBindBuffer(GL_ARRAY_BUFFER, bufferObjects[VERTEX_DATA]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*numVertices * 3, vertices, GL_STATIC_DRAW);

	// Normal data
	glBindBuffer(GL_ARRAY_BUFFER, bufferObjects[NORMAL_DATA]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * numVertices * 3, normals, GL_STATIC_DRAW);

	// Texture coordinates
	glBindBuffer(GL_ARRAY_BUFFER, bufferObjects[TEXTURE_DATA]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * numVertices * 2, textures, GL_STATIC_DRAW);

	// Indexes
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferObjects[INDEX_DATA]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort)*numFaces*3, indexes, GL_STATIC_DRAW);

	delete[] vertices;
	delete[] normals;
	delete[] textures;
	delete[] indexes;

	vertices = NULL;
	normals = NULL;
	textures = NULL;
	indexes = NULL;
}

void RVBufferedObject::DrawList()
{
	GLuint iFace, iPoint;
	glBegin(GL_TRIANGLES);
	for (iFace = 0; iFace < numFaces; iFace++)  // Each new triangle starts here
	{
		for (iPoint = 0; iPoint < 3; iPoint++) // Each vertex specified here
		{
			int index = indexes[iFace * 3 + iPoint];
			// Lookup the texture value
			glTexCoord2fv(&textures[index]);

			// Lookup the normal value
			glNormal3fv(&normals[index]);

			// Lookup the vertex value
			glVertex3fv(&vertices[index]);
		}
	}
	glEnd();
}

void RVBufferedObject::Draw() 
{
	// Here's where the data is now
	glBindBuffer(GL_ARRAY_BUFFER, bufferObjects[VERTEX_DATA]);
	glVertexPointer(3, GL_FLOAT, 0, 0);

	// Normal data
	glBindBuffer(GL_ARRAY_BUFFER, bufferObjects[NORMAL_DATA]);
	glNormalPointer(GL_FLOAT, 0, 0);

	// Texture coordinates
	glBindBuffer(GL_ARRAY_BUFFER, bufferObjects[TEXTURE_DATA]);
	glTexCoordPointer(2, GL_FLOAT, 0, 0);

	// Indexes
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferObjects[INDEX_DATA]);
	glDrawElements(GL_TRIANGLES, numFaces*3, GL_UNSIGNED_SHORT, 0);
}

