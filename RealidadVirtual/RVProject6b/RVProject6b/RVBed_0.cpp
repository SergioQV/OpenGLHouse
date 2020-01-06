#include "stdafx.h" 
#include <glew.h>
#include "RVBufferedObject.h"
#include "RVBed_0.h"

GLfloat static p_vertices[68][3] = {
	{ 4.607623028f, -1.528282012f, 7.941900414f },
	{ 4.676138372f, -1.528282012f, 7.8439033479999996f },
	{ 4.531127742f, -1.436282012f, 7.8439033479999996f },
	{ 4.531127742f, -1.528282012f, 7.982584193999999f },
	{ -4.314543228f, -1.436282012f, 7.8439033479999996f },
	{ -4.314543228f, -1.528282012f, 7.982584193999999f },
	{ -4.459553858f, -1.528282012f, 7.8439033479999996f },
	{ -4.391038514f, -1.528282012f, 7.941900414f },
	{ 4.676138372f, -1.528281138f, -9.599086662f },
	{ 4.531127742f, -1.436281138f, -9.599086662f },
	{ -4.314543228f, -1.436281138f, -9.599086662f },
	{ -4.459553858f, -1.528281138f, -9.599086662f },
	{ 4.630574268f, -1.528281138f, -9.713111002f },
	{ 4.531127742f, -1.528281138f, -9.768587415999999f },
	{ -4.314543228f, -1.528281138f, -9.768587415999999f },
	{ -4.413989754f, -1.528281138f, -9.713111002f },
	{ 4.607623028f, -1.528282012f, 7.941900414f },
	{ 4.607620912f, -3.464115284f, 7.94190253f },
	{ 4.6761362559999995f, -3.464115284f, 7.8439054640000005f },
	{ 4.676138372f, -1.528282012f, 7.8439033479999996f },
	{ 4.531127742f, -1.528282012f, 7.982584193999999f },
	{ 4.531125626f, -3.464115284f, 7.982586309999999f },
	{ 4.607620912f, -3.464115284f, 7.94190253f },
	{ 4.607623028f, -1.528282012f, 7.941900414f },
	{ -4.314543228f, -1.528282012f, 7.982584193999999f },
	{ -4.314542906f, -3.464115284f, 7.982586309999999f },
	{ 4.531125626f, -3.464115284f, 7.982586309999999f },
	{ 4.531127742f, -1.528282012f, 7.982584193999999f },
	{ -4.459553858f, -1.528282012f, 7.8439033479999996f },
	{ -4.459553168f, -3.464115284f, 7.8439054640000005f },
	{ -4.3910378240000005f, -3.464115284f, 7.94190253f },
	{ -4.391038514f, -1.528282012f, 7.941900414f },
	{ -4.391038514f, -1.528282012f, 7.941900414f },
	{ -4.3910378240000005f, -3.464115284f, 7.94190253f },
	{ -4.314542906f, -3.464115284f, 7.982586309999999f },
	{ -4.314543228f, -1.528282012f, 7.982584193999999f },
	{ 4.6761362559999995f, -3.4641145939999998f, -9.599088042f },
	{ 4.676138372f, -1.528281138f, -9.599086662f },
	{ -4.459553858f, -1.528281138f, -9.599086662f },
	{ -4.459553168f, -3.4641145939999998f, -9.599088042f },
	{ 4.630572152f, -3.4641145939999998f, -9.713111692f },
	{ 4.630574268f, -1.528281138f, -9.713111002f },
	{ 4.630574268f, -1.528281138f, -9.713111002f },
	{ 4.630572152f, -3.4641145939999998f, -9.713111692f },
	{ 4.531125626f, -3.4641145939999998f, -9.768588106f },
	{ 4.531127742f, -1.528281138f, -9.768587415999999f },
	{ -4.314542906f, -3.4641145939999998f, -9.768588106f },
	{ -4.314543228f, -1.528281138f, -9.768587415999999f },
	{ -4.413989064f, -3.4641145939999998f, -9.713111692f },
	{ -4.413989754f, -1.528281138f, -9.713111002f },
	{ -4.413989754f, -1.528281138f, -9.713111002f },
	{ -4.413989064f, -3.4641145939999998f, -9.713111692f },
	{ 4.531127742f, -3.464115284f, 7.8439033479999996f },
	{ 4.676138372f, -3.464115284f, 7.8439033479999996f },
	{ 4.607623028f, -3.464115284f, 7.941900414f },
	{ 4.531127742f, -3.464115284f, 7.982584193999999f },
	{ -4.314543228f, -3.464115284f, 7.982584193999999f },
	{ -4.314543228f, -3.464115284f, 7.8439033479999996f },
	{ -4.459553858f, -3.464115284f, 7.8439033479999996f },
	{ -4.391038514f, -3.464115284f, 7.941900414f },
	{ 4.531127742f, -3.4641145939999998f, -9.599086662f },
	{ 4.676138372f, -3.4641145939999998f, -9.599086662f },
	{ -4.314543228f, -3.4641145939999998f, -9.599086662f },
	{ -4.459553858f, -3.4641145939999998f, -9.599086662f },
	{ 4.531127742f, -3.4641145939999998f, -9.768587415999999f },
	{ 4.630574268f, -3.4641145939999998f, -9.713111002f },
	{ -4.314543228f, -3.4641145939999998f, -9.768587415999999f },
	{ -4.413989754f, -3.4641145939999998f, -9.713111002f }
};

GLfloat static p_textures[68][2] = {
	{ 0.98451f, 0.008962f },
	{ 0.991906f, 0.014444f },
	{ 0.976253f, 0.014444f },
	{ 0.976253f, 0.006685f },
	{ 0.021456f, 0.014444f },
	{ 0.021456f, 0.006685f },
	{ 0.005804f, 0.014444f },
	{ 0.0132f, 0.008962f },
	{ 0.991906f, 0.990313f },
	{ 0.976253f, 0.990313f },
	{ 0.021456f, 0.990313f },
	{ 0.005804f, 0.990313f },
	{ 0.986987f, 0.996693f },
	{ 0.976253f, 0.999796f },
	{ 0.021456f, 0.999796f },
	{ 0.010722f, 0.996693f },
	{ 0.988841f, 0.998217f },
	{ 0.778563f, 0.998217f },
	{ 0.778563f, 0.992682f },
	{ 0.988841f, 0.992681f },
	{ 0.990387f, 0.006251f },
	{ 0.990386f, 0.262f },
	{ 0.998879f, 0.262f },
	{ 0.998879f, 0.006251f },
	{ 0.021981f, 0.999052f },
	{ 0.021981f, 0.73928f },
	{ 0.975591f, 0.73928f },
	{ 0.975592f, 0.999052f },
	{ 0.004583f, 0.011185f },
	{ 0.212886f, 0.011185f },
	{ 0.212886f, 0.005666f },
	{ 0.004583f, 0.005666f },
	{ -1.72E-4f, 0.006251f },
	{ -1.71E-4f, 0.262f },
	{ 0.008321f, 0.262f },
	{ 0.008321f, 0.006251f },
	{ 0.778563f, 0.007316f },
	{ 0.988841f, 0.007316f },
	{ 0.004583f, 0.993461f },
	{ 0.212886f, 0.993461f },
	{ 0.778563f, 8.74E-4f },
	{ 0.988841f, 8.74E-4f },
	{ 0.986628f, 0.991067f },
	{ 0.986628f, 0.73896f },
	{ 0.975901f, 0.73896f },
	{ 0.975901f, 0.991067f },
	{ 0.02173f, 0.73896f },
	{ 0.02173f, 0.991067f },
	{ 0.011002f, 0.73896f },
	{ 0.011002f, 0.991067f },
	{ 0.004583f, 0.999882f },
	{ 0.212886f, 0.999882f },
	{ 0.975227f, 0.991975f },
	{ 0.99088f, 0.991975f },
	{ 0.983484f, 0.997458f },
	{ 0.975227f, 0.999734f },
	{ 0.020431f, 0.999734f },
	{ 0.020431f, 0.991975f },
	{ 0.004778f, 0.991975f },
	{ 0.012174f, 0.997458f },
	{ 0.975227f, 0.016106f },
	{ 0.99088f, 0.016106f },
	{ 0.020431f, 0.016106f },
	{ 0.004778f, 0.016106f },
	{ 0.975227f, 0.006623f },
	{ 0.985962f, 0.009726f },
	{ 0.020431f, 0.006623f },
	{ 0.009696f, 0.009726f }
};

GLfloat static p_normals[68][3] = {
	{ 0.391924f, 0.803387f, 0.448291f },
	{ 0.530133f, 0.835597f, 0.144004f },
	{ 0.244775f, 0.935833f, 0.253579f },
	{ 0.121552f, 0.827128f, 0.548712f },
	{ -0.258951f, 0.927768f, 0.268684f },
	{ -0.166452f, 0.851528f, 0.497185f },
	{ -0.492457f, 0.85288f, 0.173439f },
	{ 0.0f, 1.0f, 0.0f },
	{ 0.475498f, 0.867153f, -0.148149f },
	{ 0.262544f, 0.937151f, -0.229824f },
	{ -0.241856f, 0.947719f, -0.208169f },
	{ -0.533377f, 0.84071f, -0.09336f },
	{ 0.0f, 1.0f, 0.0f },
	{ 0.154133f, 0.896968f, -0.414358f },
	{ -0.108394f, 0.873707f, -0.474222f },
	{ -0.385446f, 0.852942f, -0.352025f },
	{ 0.819556f, -0.0f, 0.572999f },
	{ 0.819556f, -0.0f, 0.572999f },
	{ 0.953823f, -1.0E-6f, 0.30037f },
	{ 0.953823f, -1.0E-6f, 0.300369f },
	{ 0.469566f, 0.0f, 0.882897f },
	{ 0.469566f, 0.0f, 0.882897f },
	{ 0.469566f, 0.0f, 0.882897f },
	{ 0.469566f, 0.0f, 0.882897f },
	{ 0.0f, 1.0E-6f, 1.0f },
	{ 0.0f, 1.0E-6f, 1.0f },
	{ 0.0f, 1.0E-6f, 1.0f },
	{ 0.0f, 1.0E-6f, 1.0f },
	{ -0.953823f, -0.0f, 0.300369f },
	{ -0.953823f, -0.0f, 0.30037f },
	{ -0.819556f, 0.0f, 0.572999f },
	{ -0.819556f, 0.0f, 0.572999f },
	{ -0.469566f, 1.0E-6f, 0.882897f },
	{ -0.469568f, 1.0E-6f, 0.882896f },
	{ -0.469568f, 1.0E-6f, 0.882896f },
	{ -0.469566f, 1.0E-6f, 0.882897f },
	{ 0.981989f, -1.0E-6f, -0.188939f },
	{ 0.981989f, -1.0E-6f, -0.188938f },
	{ -0.981989f, -0.0f, -0.188938f },
	{ -0.981989f, -0.0f, -0.188939f },
	{ 0.928604f, -1.0E-6f, -0.371072f },
	{ 0.928605f, -1.0E-6f, -0.37107f },
	{ 0.487175f, -0.0f, -0.873305f },
	{ 0.487175f, -0.0f, -0.873305f },
	{ 0.251689f, 0.0f, -0.967808f },
	{ 0.25169f, 0.0f, -0.967808f },
	{ -0.25169f, 0.0f, -0.967808f },
	{ -0.25169f, 0.0f, -0.967808f },
	{ -0.487176f, 0.0f, -0.873304f },
	{ -0.487175f, 0.0f, -0.873305f },
	{ -0.928605f, -0.0f, -0.37107f },
	{ -0.928604f, -0.0f, -0.371072f },
	{ 0.0f, -1.0f, -0.0f },
	{ 0.0f, -1.0f, -0.0f },
	{ 0.0f, -1.0f, 0.0f },
	{ 0.0f, -1.0f, 0.0f },
	{ 0.0f, -1.0f, 0.0f },
	{ 0.0f, -1.0f, -0.0f },
	{ 0.0f, -1.0f, -0.0f },
	{ 0.0f, -1.0f, 0.0f },
	{ 0.0f, -1.0f, -0.0f },
	{ 0.0f, -1.0f, -0.0f },
	{ 0.0f, -1.0f, -0.0f },
	{ 0.0f, -1.0f, -0.0f },
	{ 0.0f, -1.0f, 0.0f },
	{ 0.0f, -1.0f, 0.0f },
	{ 0.0f, -1.0f, 0.0f },
	{ 0.0f, -1.0f, 0.0f }
};

GLushort static p_indexes[60][3] = {
	{ 0, 1, 2 },
	{ 0, 2, 3 },
	{ 2, 4, 5 },
	{ 2, 5, 3 },
	{ 5, 4, 6 },
	{ 5, 6, 7 },
	{ 8, 9, 2 },
	{ 8, 2, 1 },
	{ 2, 9, 10 },
	{ 2, 10, 4 },
	{ 10, 11, 6 },
	{ 10, 6, 4 },
	{ 8, 12, 13 },
	{ 8, 13, 9 },
	{ 13, 14, 10 },
	{ 13, 10, 9 },
	{ 10, 14, 15 },
	{ 10, 15, 11 },
	{ 16, 17, 18 },
	{ 16, 18, 19 },
	{ 20, 21, 22 },
	{ 20, 22, 23 },
	{ 24, 25, 26 },
	{ 24, 26, 27 },
	{ 28, 29, 30 },
	{ 28, 30, 31 },
	{ 32, 33, 34 },
	{ 32, 34, 35 },
	{ 19, 18, 36 },
	{ 19, 36, 37 },
	{ 38, 39, 29 },
	{ 38, 29, 28 },
	{ 37, 36, 40 },
	{ 37, 40, 41 },
	{ 42, 43, 44 },
	{ 42, 44, 45 },
	{ 45, 44, 46 },
	{ 45, 46, 47 },
	{ 47, 46, 48 },
	{ 47, 48, 49 },
	{ 50, 51, 39 },
	{ 50, 39, 38 },
	{ 52, 53, 54 },
	{ 55, 52, 54 },
	{ 56, 57, 52 },
	{ 55, 56, 52 },
	{ 58, 57, 56 },
	{ 59, 58, 56 },
	{ 52, 60, 61 },
	{ 53, 52, 61 },
	{ 62, 60, 52 },
	{ 57, 62, 52 },
	{ 58, 63, 62 },
	{ 57, 58, 62 },
	{ 64, 65, 61 },
	{ 60, 64, 61 },
	{ 62, 66, 64 },
	{ 60, 62, 64 },
	{ 67, 66, 62 },
	{ 63, 67, 62 }
};

RVBed_0::RVBed_0()
{
	numFaces = 60;
	numVertices = 68;

	normals = new GLfloat[numVertices * 3];
	for (int i = 0; i < numVertices; i++) for (int j = 0; j < 3; j++) normals[3 * i + j] = p_normals[i][j];
	vertices = new GLfloat[numVertices * 3];
	for (int i = 0; i < numVertices; i++) for (int j = 0; j < 3; j++) vertices[3 * i + j] = p_vertices[i][j];
	textures = new GLfloat[numVertices * 2];
	for (int i = 0; i < numVertices; i++) for (int j = 0; j < 2; j++) textures[2 * i + j] = p_textures[i][j];
	indexes = new GLushort[numFaces * 3];
	for (int i = 0; i < numFaces; i++) for (int j = 0; j < 3; j++) indexes[3 * i + j] = p_indexes[i][j];
}

