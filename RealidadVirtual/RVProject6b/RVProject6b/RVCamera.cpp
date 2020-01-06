#include "stdafx.h"
#include <glew.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "RVCamera.h"

//
// FUNCIÓN: RVCamera::RVCamera()
//
// PROPÓSITO: Construye una cámara
//
// COMENTARIOS: 
//     La posición inicial es (0,0,0).
//     La orientación incial es el sistema de coordenadas del modelo
//     El tamaño del paso inicial es 0.1
//     El támaño del giro inicial es 1.0 grados
//
RVCamera::RVCamera() {
	xPos = 0.0f;
	yPos = 0.0f;
	zPos = 0.0f;
	
	xDir = 0.0f;
	yDir = 0.0f;
	zDir = 1.0f;
	
	xUp = 0.0f;
	yUp = 1.0f;
	zUp = 0.0f;
	
	xRight = 1.0f;
	yRight = 0.0f;
	zRight = 0.0f;

	moveStep = 1.5f;
	turnStep = 2.0f;
	cosAngle = (GLfloat) cos(3.141592*turnStep / 180);
	sinAngle = (GLfloat) sin(3.141592*turnStep / 180);
}

//
// FUNCIÓN: RVCamera::PlaceCamera()
//
// PROPÓSITO: Aplica los cambios a la matriz ModelView para situar la cámara.
//
void RVCamera::PlaceCamera()
{
	// Creates a rotation matrix using vectors Dir, Up and Right
	GLfloat m[16];
	m[0] = xRight;
	m[4] = yRight;
	m[8] = zRight;
	m[12] = 0.0;
	m[1] = xUp;
	m[5] = yUp;
	m[9] = zUp;
	m[13] = 0.0;
	m[2] = xDir;
	m[6] = yDir;
	m[10] = zDir;
	m[14] = 0.0;
	m[3] = 0.0;
	m[7] = 0.0;
	m[11] = 0.0;
	m[15] = 1.0;
	glMultMatrixf(m);

	glTranslatef(-xPos, -yPos, -zPos);
}

//
// FUNCIÓN: RVCamera::SetPosition(GLfloat x, GLfloat y, GLfloat z)
//
// PROPÓSITO: Asigna la posición de la cámara con respecto al sistema de coordenadas del modelo.
//
void RVCamera::SetPosition(GLfloat x, GLfloat y, GLfloat z)
{
	xPos = x;
	yPos = y;
	zPos = z;
}

//
// FUNCIÓN: RVCamera::SetDirection(GLfloat xDir, GLfloat yDir, GLfloat zDir, GLfloat xUp, GLfloat yUp, GLfloat zUp)
//
// PROPÓSITO: Asigna la orientación de la cámara.
//
void RVCamera::SetDirection(GLfloat xD, GLfloat yD, GLfloat zD, GLfloat xU, GLfloat yU, GLfloat zU)
{
	xDir = xD;
	yDir = yD;
	zDir = zD;

	xUp = xU;
	yUp = yU;
	zUp = zU;


	// Right = Up x Dir
	xRight = yUp*zDir - zUp*yDir;
	yRight = zUp*xDir - xUp*zDir;
	zRight = xUp*yDir - yUp*xDir;
}

//
// FUNCIÓN: RVCamera::SetMoveStep(GLfloat step)
//
// PROPÓSITO: Asigna el avance en cada paso.
//
void RVCamera::SetMoveStep(GLfloat step)
{
	moveStep = step;
}

//
// FUNCIÓN: RVCamera::SetTurnStep(GLfloat step)
//
// PROPÓSITO: Asigna el ángulo de giro en cada paso.
//
void RVCamera::SetTurnStep(GLfloat step)
{
	turnStep = step;
	cosAngle = (GLfloat) cos(3.141592*turnStep / 180);
	sinAngle = (GLfloat) sin(3.141592*turnStep / 180);
}

//
// FUNCIÓN: RVCamera::GetPosition()
//
// PROPÓSITO: Obtiene la posición de la cámara.
//
void RVCamera::GetPosition(GLfloat* vPos)
{
	vPos[0] = xPos;
	vPos[1] = yPos;
	vPos[2] = zPos;
}

//
// FUNCIÓN: RVCamera::GetDirection()
//
// PROPÓSITO: Obtiene la orientación de la cámara (eje Z).
//
void RVCamera::GetDirection(GLfloat* vDir)
{
	vDir[0] = xDir;
	vDir[1] = yDir;
	vDir[2] = zDir;
}

//
// FUNCIÓN: RVCamera::GetUpDirection()
//
// PROPÓSITO: Obtiene la orientación cenital de la cámara (eje Y).
//
void RVCamera::GetUpDirection(GLfloat* vUp)
{
	vUp[0] = xUp;
	vUp[1] = yUp;
	vUp[2] = zUp;
}

//
// FUNCIÓN: RVCamera::GetMoveStep()
//
// PROPÓSITO: Obtiene el avance en cada paso.
//
GLfloat RVCamera::GetMoveStep()
{
	return moveStep;
}

//
// FUNCIÓN: RVCamera::GetTurnStep()
//
// PROPÓSITO: Obtiene el ángulo de giro en cada paso.
//
GLfloat RVCamera::GetTurnStep()
{
	return turnStep;
}

//
// FUNCIÓN: RVCamera::MoveFront()
//
// PROPÓSITO: Mueve el observador un paso (moveStep) en la dirección (-xDir, -yDir, -zDir) 
//
//
void RVCamera::MoveFront()
{
	GLfloat x = xPos - xDir*moveStep;
	GLfloat z = zPos - zDir*moveStep;

	if (!zonaProhibida(x,z) && !zonaPuerta(x,z)) {
		xPos = x;
		yPos -= yDir*moveStep;
		zPos = z;
	}

}

//
// FUNCIÓN: RVCamera::MoveBack()
//
// PROPÓSITO: Mueve el observador un paso (moveStep) hacia atrás en la dirección (xDir, yDir, zDir) 
//
//
void RVCamera::MoveBack()
{
	GLfloat x = xPos + xDir*moveStep;
	GLfloat z = zPos + zDir*moveStep;

	if (!zonaProhibida(x, z) && !zonaPuerta(x, z)) {
		xPos = x;
		yPos += yDir*moveStep;
		zPos = z;
	}
}

//
// FUNCIÓN: RVCamera::MoveLeft()
//
// PROPÓSITO: Mueve el observador un paso (moveStep) hacia la izquierda. 
//
//
void RVCamera::MoveLeft()
{
	xPos -= xRight*moveStep;
	yPos -= yRight*moveStep;
	zPos -= zRight*moveStep;
}

//
// FUNCIÓN: RVCamera::MoveRight()
//
// PROPÓSITO: Mueve el observador un paso (moveStep) hacia la derecha. 
//
//
void RVCamera::MoveRight()
{
	xPos += xRight*moveStep;
	yPos += yRight*moveStep;
	zPos += zRight*moveStep;
}

//
// FUNCIÓN: RVCamera::MoveUp()
//
// PROPÓSITO: Mueve el observador un paso (moveStep) hacia arriba. 
//
//
void RVCamera::MoveUp()
{
	xPos += xUp*moveStep;
	yPos += yUp*moveStep;
	zPos += zUp*moveStep;
}

//
// FUNCIÓN: RVCamera::MoveDown()
//
// PROPÓSITO: Mueve el observador un paso (moveStep) hacia abajo. 
//
void RVCamera::MoveDown()
{
	xPos -= xUp*moveStep;
	yPos -= yUp*moveStep;
	zPos -= zUp*moveStep;
}

//
// FUNCIÓN: RVCamera::TurnRight()
//
// PROPÓSITO: Rota el observador un paso (angleStep) hacia su derecha.
//
void RVCamera::TurnRight()
{
	xDir = cosAngle*xDir - sinAngle*xRight;
	yDir = cosAngle*yDir - sinAngle*yRight;
	zDir = cosAngle*zDir - sinAngle*zRight;

	// Right = Up x Dir
	xRight = yUp*zDir - zUp*yDir;
	yRight = zUp*xDir - xUp*zDir;
	zRight = xUp*yDir - yUp*xDir;
}

//
// FUNCIÓN: RVCamera::TurnLeft()
//
// PROPÓSITO: Rota el observador un paso (angleStep) hacia su izquierda.
//
void RVCamera::TurnLeft()
{
	xDir = cosAngle*xDir + sinAngle*xRight;
	yDir = cosAngle*yDir + sinAngle*yRight;
	zDir = cosAngle*zDir + sinAngle*zRight;

	// Right = Up x Dir
	xRight = yUp*zDir - zUp*yDir;
	yRight = zUp*xDir - xUp*zDir;
	zRight = xUp*yDir - yUp*xDir;
}

//
// FUNCIÓN: RVCamera::TurnUp()
//
// PROPÓSITO: Rota el observador un paso (angleStep) hacia arriba.
//
void RVCamera::TurnUp()
{
	xDir = cosAngle*xDir - sinAngle*xUp;
	yDir = cosAngle*yDir - sinAngle*yUp;
	zDir = cosAngle*zDir - sinAngle*zUp;

	// Up = Dir x Right
	xUp = yDir*zRight - zDir*yRight;
	yUp = zDir*xRight - xDir*zRight;
	zUp = xDir*yRight - yDir*xRight;
}

//
// FUNCIÓN: RVCamera::TurnDown()
//
// PROPÓSITO: Rota el observador un paso (angleStep) hacia abajo.
//
void RVCamera::TurnDown()
{
	xDir = cosAngle*xDir + sinAngle*xUp;
	yDir = cosAngle*yDir + sinAngle*yUp;
	zDir = cosAngle*zDir + sinAngle*zUp;

	// Up = Dir x Right
	xUp = yDir*zRight - zDir*yRight;
	yUp = zDir*xRight - xDir*zRight;
	zUp = xDir*yRight - yDir*xRight;
}

//
// FUNCIÓN: RVCamera::TurnCW()
//
// PROPÓSITO: Rota el observador un paso (angleStep) en sentido del reloj.
//
void RVCamera::TurnCW()
{
	xUp = cosAngle*xUp + sinAngle*xRight;
	yUp = cosAngle*yUp + sinAngle*yRight;
	zUp = cosAngle*zUp + sinAngle*zRight;

	// Right = Up x Dir
	xRight = yUp*zDir - zUp*yDir;
	yRight = zUp*xDir - xUp*zDir;
	zRight = xUp*yDir - yUp*xDir;
}

//
// FUNCIÓN: RVCamera::TurnDown()
//
// PROPÓSITO: Rota el observador un paso (angleStep) en sentido contrario al reloj.
//
void RVCamera::TurnCCW()
{
	xUp = cosAngle*xUp - sinAngle*xRight;
	yUp = cosAngle*yUp - sinAngle*yRight;
	zUp = cosAngle*zUp - sinAngle*zRight;

	// Right = Up x Dir
	xRight = yUp*zDir - zUp*yDir;
	yRight = zUp*xDir - xUp*zDir;
	zRight = xUp*yDir - yUp*xDir;
}


//
// FUNCIÓN: RVCamera::setZonaPuerta(GLfloat puertas[5][4])
//
// PROPÓSITO: obtiene las coordenas de las puertas para impedir o permitir el paso
//
void RVCamera::setZonaPuerta(GLfloat puertas[5][4])
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			zonaPuertas[i][j] = puertas[i][j];
		}
	}
}


//
// FUNCIÓN: RVCamera::zonaProhibida(GLfloat x, GLfloat z)
//
// PROPÓSITO: comprueba que la posición definida por las coordenadas x y z no se encuentra en una zona prohibida
//
bool RVCamera::zonaProhibida(GLfloat x, GLfloat z)
{
	//Vallas
	if (x >= 95.0f || x <= -95.0f) return true;
	if (z >= 195.0f || z <= -195.0f) return true;
	
	//Muros Exteriores
	if (z >= 70.0f && z <=130.9f && x <= 64.2f && x >= 56.0f) return true;
	if (z >= 70.0f && z <= 130.9f && x >= -64.2f && x <= -56.0f) return true;
	if (z >= 126.0f && z <= 134.0f && ((x >= -61.15f && x <= 6.2f) || (x >= 16.2f && x<=61.15f))) return true;
	if (z >= 68.0f && z <= 76.0f && x >= -61.15f && x <= 61.15f) return true;

	//Piscina
	if (z <= -17.0f && z >= -143.0f && x >= -83.0f && x <= 83.0f) return true;
	
	//Muros Interiores
	if (z <= 102.0f && z >= 73.3f && ((x >= 20.41f && x <= 25.51f) || (x <= -11.65f && x >= -14.75f))) return true;
	if (z <= 102.0f && z >= 98.9f && ((x <= 23.51f && x >= 13.51f) || (x <= 3.51f && x >= -16.49f) || (x <= -26.49f && x >= -61.15f ))) return true;
	if (z <= 113.9f && z >= 109.99f && ((x <= -1.35f && x >= -11.35) || (x <= -21.35f && x >= -33.7f))) return true;
	if (z <= 128.7f && z >= 112.09f && ((x <= -0.35f && x >= -3.45f) || (x <= -31.6f && x >= -34.7f))) return true;

	//muebles
	if (z <= 128.7f && z >= 108.7f && x >= -58.95f && x <= -46.95f) return true;
	if (z <= 96.9f && z >= 76.7f && x >= -58.95f && x <= -39.05f) return true;
	if (z <= 84.9f && z >= 73.3f && x >= -12.65f && x <= 9.35f) return true;
	return false;
}


//
// FUNCIÓN: RVCamera::zonaPuerta(GLfloat x, GLfloat z)
//
// PROPÓSITO: comprueba que la posición definida por las coordenadas x y z no se encuentra en una zona de puertas
//
bool RVCamera::zonaPuerta(GLfloat x, GLfloat z)
{
	int i = 0;

	while (i < 5) {
		if ((zonaPuertas[i][0] - 2.0f) <= x && (2.0f + zonaPuertas[i][1]) > x && (2.0f + zonaPuertas[i][2]) >= z && (zonaPuertas[i][3] - 2.0f) <= z) {
			return true;
		}
		i++;
	}
	return false;
}


