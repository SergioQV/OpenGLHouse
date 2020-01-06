#include "stdafx.h" 
#include <glew.h>
#include "RVBufferedObject.h"
#include "RVBed_1.h"

GLfloat static p_vertices[288][3] = {
	{ -3.6185830080000003f, -2.721827636f, 8.196110489999999f },
	{ -3.6185830080000003f, 1.30470559f, 8.196110489999999f },
	{ -3.64924992f, -2.721827636f, 8.249227104000001f },
	{ -3.64924992f, 1.30470559f, 8.249227104000001f },
	{ -3.7105833759999998f, 1.30470559f, 8.249227104000001f },
	{ -3.7105833759999998f, -2.721827636f, 8.249227104000001f },
	{ -3.74124992f, -2.721827636f, 8.196110489999999f },
	{ -3.74124992f, 1.30470559f, 8.196110489999999f },
	{ -3.74124992f, -2.721827636f, 8.196110489999999f },
	{ -3.74124992f, 1.30470559f, 8.196110489999999f },
	{ -3.7105833759999998f, 1.30470559f, 8.142993876f },
	{ -3.7105833759999998f, -2.721827636f, 8.142993876f },
	{ -3.64924992f, -2.721827636f, 8.142993876f },
	{ -3.64924992f, 1.30470559f, 8.142993876f },
	{ -3.6185830080000003f, 1.30470559f, 8.196110489999999f },
	{ -3.6185830080000003f, -2.721827636f, 8.196110489999999f },
	{ -2.698583008f, -2.721827636f, 8.196110489999999f },
	{ -2.698583008f, 1.43350536f, 8.196110489999999f },
	{ -2.72924992f, -2.721827636f, 8.249227104000001f },
	{ -2.72924992f, 1.43350536f, 8.249227104000001f },
	{ -2.790583376f, 1.43350536f, 8.249227104000001f },
	{ -2.790583376f, -2.721827636f, 8.249227104000001f },
	{ -2.8212499199999996f, -2.721827636f, 8.196110489999999f },
	{ -2.8212499199999996f, 1.43350536f, 8.196110489999999f },
	{ -2.8212499199999996f, -2.721827636f, 8.196110489999999f },
	{ -2.8212499199999996f, 1.43350536f, 8.196110489999999f },
	{ -2.790583376f, 1.43350536f, 8.142993876f },
	{ -2.790583376f, -2.721827636f, 8.142993876f },
	{ -2.72924992f, -2.721827636f, 8.142993876f },
	{ -2.72924992f, 1.43350536f, 8.142993876f },
	{ -2.698583008f, 1.43350536f, 8.196110489999999f },
	{ -2.698583008f, -2.721827636f, 8.196110489999999f },
	{ -1.778583008f, -2.721827636f, 8.196110489999999f },
	{ -1.778583008f, 1.479505452f, 8.196110489999999f },
	{ -1.8092499199999998f, -2.721827636f, 8.249227104000001f },
	{ -1.8092499199999998f, 1.479505452f, 8.249227104000001f },
	{ -1.870583376f, 1.479505452f, 8.249227104000001f },
	{ -1.870583376f, -2.721827636f, 8.249227104000001f },
	{ -1.90124992f, -2.721827636f, 8.196110489999999f },
	{ -1.90124992f, 1.479505452f, 8.196110489999999f },
	{ -1.90124992f, -2.721827636f, 8.196110489999999f },
	{ -1.90124992f, 1.479505452f, 8.196110489999999f },
	{ -1.870583376f, 1.479505452f, 8.142993876f },
	{ -1.870583376f, -2.721827636f, 8.142993876f },
	{ -1.8092499199999998f, -2.721827636f, 8.142993876f },
	{ -1.8092499199999998f, 1.479505452f, 8.142993876f },
	{ -1.778583008f, 1.479505452f, 8.196110489999999f },
	{ -1.778583008f, -2.721827636f, 8.196110489999999f },
	{ -0.858583008f, -2.721827636f, 8.196110489999999f },
	{ -0.858583008f, 1.479505452f, 8.196110489999999f },
	{ -0.88924992f, -2.721827636f, 8.249227104000001f },
	{ -0.88924992f, 1.479505452f, 8.249227104000001f },
	{ -0.950583376f, 1.479505452f, 8.249227104000001f },
	{ -0.950583376f, -2.721827636f, 8.249227104000001f },
	{ -0.98124992f, -2.721827636f, 8.196110489999999f },
	{ -0.98124992f, 1.479505452f, 8.196110489999999f },
	{ -0.98124992f, -2.721827636f, 8.196110489999999f },
	{ -0.98124992f, 1.479505452f, 8.196110489999999f },
	{ -0.950583376f, 1.479505452f, 8.142993876f },
	{ -0.950583376f, -2.721827636f, 8.142993876f },
	{ -0.88924992f, -2.721827636f, 8.142993876f },
	{ -0.88924992f, 1.479505452f, 8.142993876f },
	{ -0.858583008f, 1.479505452f, 8.196110489999999f },
	{ -0.858583008f, -2.721827636f, 8.196110489999999f },
	{ 0.061416992f, -2.721827636f, 8.196110489999999f },
	{ 0.061416992f, 1.479505452f, 8.196110489999999f },
	{ 0.03075008f, -2.721827636f, 8.249227104000001f },
	{ 0.03075008f, 1.479505452f, 8.249227104000001f },
	{ -0.030583376f, 1.479505452f, 8.249227104000001f },
	{ -0.030583376f, -2.721827636f, 8.249227104000001f },
	{ -0.06124992f, -2.721827636f, 8.196110489999999f },
	{ -0.06124992f, 1.479505452f, 8.196110489999999f },
	{ -0.06124992f, -2.721827636f, 8.196110489999999f },
	{ -0.06124992f, 1.479505452f, 8.196110489999999f },
	{ -0.030583376f, 1.479505452f, 8.142993876f },
	{ -0.030583376f, -2.721827636f, 8.142993876f },
	{ 0.03075008f, -2.721827636f, 8.142993876f },
	{ 0.03075008f, 1.479505452f, 8.142993876f },
	{ 0.061416992f, 1.479505452f, 8.196110489999999f },
	{ 0.061416992f, -2.721827636f, 8.196110489999999f },
	{ 0.981416992f, -2.721827636f, 8.196110489999999f },
	{ 0.981416992f, 1.479505452f, 8.196110489999999f },
	{ 0.9507500799999999f, -2.721827636f, 8.249227104000001f },
	{ 0.9507500799999999f, 1.479505452f, 8.249227104000001f },
	{ 0.889416624f, 1.479505452f, 8.249227104000001f },
	{ 0.889416624f, -2.721827636f, 8.249227104000001f },
	{ 0.85875008f, -2.721827636f, 8.196110489999999f },
	{ 0.85875008f, 1.479505452f, 8.196110489999999f },
	{ 0.85875008f, -2.721827636f, 8.196110489999999f },
	{ 0.85875008f, 1.479505452f, 8.196110489999999f },
	{ 0.889416624f, 1.479505452f, 8.142993876f },
	{ 0.889416624f, -2.721827636f, 8.142993876f },
	{ 0.9507500799999999f, -2.721827636f, 8.142993876f },
	{ 0.9507500799999999f, 1.479505452f, 8.142993876f },
	{ 0.981416992f, 1.479505452f, 8.196110489999999f },
	{ 0.981416992f, -2.721827636f, 8.196110489999999f },
	{ 1.9014166239999999f, -2.721827636f, 8.196110489999999f },
	{ 1.9014166239999999f, 1.479505452f, 8.196110489999999f },
	{ 1.8707504480000001f, -2.721827636f, 8.249227104000001f },
	{ 1.8707504480000001f, 1.479505452f, 8.249227104000001f },
	{ 1.809416624f, 1.479505452f, 8.249227104000001f },
	{ 1.809416624f, -2.721827636f, 8.249227104000001f },
	{ 1.778749712f, -2.721827636f, 8.196110489999999f },
	{ 1.778749712f, 1.479505452f, 8.196110489999999f },
	{ 1.778749712f, -2.721827636f, 8.196110489999999f },
	{ 1.778749712f, 1.479505452f, 8.196110489999999f },
	{ 1.809416624f, 1.479505452f, 8.142993876f },
	{ 1.809416624f, -2.721827636f, 8.142993876f },
	{ 1.8707504480000001f, -2.721827636f, 8.142993876f },
	{ 1.8707504480000001f, 1.479505452f, 8.142993876f },
	{ 1.9014166239999999f, 1.479505452f, 8.196110489999999f },
	{ 1.9014166239999999f, -2.721827636f, 8.196110489999999f },
	{ 2.821416624f, -2.721827636f, 8.196110489999999f },
	{ 2.821416624f, 1.43350536f, 8.196110489999999f },
	{ 2.7907504480000003f, -2.721827636f, 8.249227104000001f },
	{ 2.7907504480000003f, 1.43350536f, 8.249227104000001f },
	{ 2.7294166239999997f, 1.43350536f, 8.249227104000001f },
	{ 2.7294166239999997f, -2.721827636f, 8.249227104000001f },
	{ 2.698749712f, -2.721827636f, 8.196110489999999f },
	{ 2.698749712f, 1.43350536f, 8.196110489999999f },
	{ 2.698749712f, -2.721827636f, 8.196110489999999f },
	{ 2.698749712f, 1.43350536f, 8.196110489999999f },
	{ 2.7294166239999997f, 1.43350536f, 8.142993876f },
	{ 2.7294166239999997f, -2.721827636f, 8.142993876f },
	{ 2.7907504480000003f, -2.721827636f, 8.142993876f },
	{ 2.7907504480000003f, 1.43350536f, 8.142993876f },
	{ 2.821416624f, 1.43350536f, 8.196110489999999f },
	{ 2.821416624f, -2.721827636f, 8.196110489999999f },
	{ 3.7414166239999997f, -2.721827636f, 8.196110489999999f },
	{ 3.7414166239999997f, 1.30470559f, 8.196110489999999f },
	{ 3.7107504479999998f, -2.721827636f, 8.249227104000001f },
	{ 3.7107504479999998f, 1.30470559f, 8.249227104000001f },
	{ 3.649416624f, 1.30470559f, 8.249227104000001f },
	{ 3.649416624f, -2.721827636f, 8.249227104000001f },
	{ 3.6187497119999996f, -2.721827636f, 8.196110489999999f },
	{ 3.6187497119999996f, 1.30470559f, 8.196110489999999f },
	{ 3.6187497119999996f, -2.721827636f, 8.196110489999999f },
	{ 3.6187497119999996f, 1.30470559f, 8.196110489999999f },
	{ 3.649416624f, 1.30470559f, 8.142993876f },
	{ 3.649416624f, -2.721827636f, 8.142993876f },
	{ 3.7107504479999998f, -2.721827636f, 8.142993876f },
	{ 3.7107504479999998f, 1.30470559f, 8.142993876f },
	{ 3.7414166239999997f, 1.30470559f, 8.196110489999999f },
	{ 3.7414166239999997f, -2.721827636f, 8.196110489999999f },
	{ -3.6185830080000003f, -2.7218269459999997f, -9.975243473999999f },
	{ -3.6185830080000003f, 1.30470628f, -9.975243473999999f },
	{ -3.64924992f, -2.7218269459999997f, -9.92212617f },
	{ -3.64924992f, 1.30470628f, -9.92212617f },
	{ -3.7105833759999998f, 1.30470628f, -9.92212617f },
	{ -3.7105833759999998f, -2.7218269459999997f, -9.92212617f },
	{ -3.74124992f, -2.7218269459999997f, -9.975243473999999f },
	{ -3.74124992f, 1.30470628f, -9.975243473999999f },
	{ -3.74124992f, -2.7218269459999997f, -9.975243473999999f },
	{ -3.74124992f, 1.30470628f, -9.975243473999999f },
	{ -3.7105833759999998f, 1.30470628f, -10.028357972f },
	{ -3.7105833759999998f, -2.7218269459999997f, -10.028357972f },
	{ -3.64924992f, -2.7218269459999997f, -10.028357972f },
	{ -3.64924992f, 1.30470628f, -10.028357972f },
	{ -3.6185830080000003f, 1.30470628f, -9.975243473999999f },
	{ -3.6185830080000003f, -2.7218269459999997f, -9.975243473999999f },
	{ -2.698583008f, -2.7218269459999997f, -9.975243473999999f },
	{ -2.698583008f, 1.433506096f, -9.975243473999999f },
	{ -2.72924992f, -2.7218269459999997f, -9.92212617f },
	{ -2.72924992f, 1.433506096f, -9.92212617f },
	{ -2.790583376f, 1.433506096f, -9.92212617f },
	{ -2.790583376f, -2.7218269459999997f, -9.92212617f },
	{ -2.8212499199999996f, -2.7218269459999997f, -9.975243473999999f },
	{ -2.8212499199999996f, 1.433506096f, -9.975243473999999f },
	{ -2.8212499199999996f, -2.7218269459999997f, -9.975243473999999f },
	{ -2.8212499199999996f, 1.433506096f, -9.975243473999999f },
	{ -2.790583376f, 1.433506096f, -10.028357972f },
	{ -2.790583376f, -2.7218269459999997f, -10.028357972f },
	{ -2.72924992f, -2.7218269459999997f, -10.028357972f },
	{ -2.72924992f, 1.433506096f, -10.028357972f },
	{ -2.698583008f, 1.433506096f, -9.975243473999999f },
	{ -2.698583008f, -2.7218269459999997f, -9.975243473999999f },
	{ -1.778583008f, -2.7218269459999997f, -9.975243473999999f },
	{ -1.778583008f, 1.479506142f, -9.975243473999999f },
	{ -1.8092499199999998f, -2.7218269459999997f, -9.92212617f },
	{ -1.8092499199999998f, 1.479506142f, -9.92212617f },
	{ -1.870583376f, 1.479506142f, -9.92212617f },
	{ -1.870583376f, -2.7218269459999997f, -9.92212617f },
	{ -1.90124992f, -2.7218269459999997f, -9.975243473999999f },
	{ -1.90124992f, 1.479506142f, -9.975243473999999f },
	{ -1.90124992f, -2.7218269459999997f, -9.975243473999999f },
	{ -1.90124992f, 1.479506142f, -9.975243473999999f },
	{ -1.870583376f, 1.479506142f, -10.028357972f },
	{ -1.870583376f, -2.7218269459999997f, -10.028357972f },
	{ -1.8092499199999998f, -2.7218269459999997f, -10.028357972f },
	{ -1.8092499199999998f, 1.479506142f, -10.028357972f },
	{ -1.778583008f, 1.479506142f, -9.975243473999999f },
	{ -1.778583008f, -2.7218269459999997f, -9.975243473999999f },
	{ -0.858583008f, -2.7218269459999997f, -9.975243473999999f },
	{ -0.858583008f, 1.479506142f, -9.975243473999999f },
	{ -0.88924992f, -2.7218269459999997f, -9.92212617f },
	{ -0.88924992f, 1.479506142f, -9.92212617f },
	{ -0.950583376f, 1.479506142f, -9.92212617f },
	{ -0.950583376f, -2.7218269459999997f, -9.92212617f },
	{ -0.98124992f, -2.7218269459999997f, -9.975243473999999f },
	{ -0.98124992f, 1.479506142f, -9.975243473999999f },
	{ -0.98124992f, -2.7218269459999997f, -9.975243473999999f },
	{ -0.98124992f, 1.479506142f, -9.975243473999999f },
	{ -0.950583376f, 1.479506142f, -10.028357972f },
	{ -0.950583376f, -2.7218269459999997f, -10.028357972f },
	{ -0.88924992f, -2.7218269459999997f, -10.028357972f },
	{ -0.88924992f, 1.479506142f, -10.028357972f },
	{ -0.858583008f, 1.479506142f, -9.975243473999999f },
	{ -0.858583008f, -2.7218269459999997f, -9.975243473999999f },
	{ 0.061416992f, -2.7218269459999997f, -9.975243473999999f },
	{ 0.061416992f, 1.479506142f, -9.975243473999999f },
	{ 0.03075008f, -2.7218269459999997f, -9.92212617f },
	{ 0.03075008f, 1.479506142f, -9.92212617f },
	{ -0.030583376f, 1.479506142f, -9.92212617f },
	{ -0.030583376f, -2.7218269459999997f, -9.92212617f },
	{ -0.06124992f, -2.7218269459999997f, -9.975243473999999f },
	{ -0.06124992f, 1.479506142f, -9.975243473999999f },
	{ -0.06124992f, -2.7218269459999997f, -9.975243473999999f },
	{ -0.06124992f, 1.479506142f, -9.975243473999999f },
	{ -0.030583376f, 1.479506142f, -10.028357972f },
	{ -0.030583376f, -2.7218269459999997f, -10.028357972f },
	{ 0.03075008f, -2.7218269459999997f, -10.028357972f },
	{ 0.03075008f, 1.479506142f, -10.028357972f },
	{ 0.061416992f, 1.479506142f, -9.975243473999999f },
	{ 0.061416992f, -2.7218269459999997f, -9.975243473999999f },
	{ 0.981416992f, -2.7218269459999997f, -9.975243473999999f },
	{ 0.981416992f, 1.479506142f, -9.975243473999999f },
	{ 0.9507500799999999f, -2.7218269459999997f, -9.92212617f },
	{ 0.9507500799999999f, 1.479506142f, -9.92212617f },
	{ 0.889416624f, 1.479506142f, -9.92212617f },
	{ 0.889416624f, -2.7218269459999997f, -9.92212617f },
	{ 0.85875008f, -2.7218269459999997f, -9.975243473999999f },
	{ 0.85875008f, 1.479506142f, -9.975243473999999f },
	{ 0.85875008f, -2.7218269459999997f, -9.975243473999999f },
	{ 0.85875008f, 1.479506142f, -9.975243473999999f },
	{ 0.889416624f, 1.479506142f, -10.028357972f },
	{ 0.889416624f, -2.7218269459999997f, -10.028357972f },
	{ 0.9507500799999999f, -2.7218269459999997f, -10.028357972f },
	{ 0.9507500799999999f, 1.479506142f, -10.028357972f },
	{ 0.981416992f, 1.479506142f, -9.975243473999999f },
	{ 0.981416992f, -2.7218269459999997f, -9.975243473999999f },
	{ 1.9014166239999999f, -2.7218269459999997f, -9.975243473999999f },
	{ 1.9014166239999999f, 1.479506142f, -9.975243473999999f },
	{ 1.8707504480000001f, -2.7218269459999997f, -9.92212617f },
	{ 1.8707504480000001f, 1.479506142f, -9.92212617f },
	{ 1.809416624f, 1.479506142f, -9.92212617f },
	{ 1.809416624f, -2.7218269459999997f, -9.92212617f },
	{ 1.778749712f, -2.7218269459999997f, -9.975243473999999f },
	{ 1.778749712f, 1.479506142f, -9.975243473999999f },
	{ 1.778749712f, -2.7218269459999997f, -9.975243473999999f },
	{ 1.778749712f, 1.479506142f, -9.975243473999999f },
	{ 1.809416624f, 1.479506142f, -10.028357972f },
	{ 1.809416624f, -2.7218269459999997f, -10.028357972f },
	{ 1.8707504480000001f, -2.7218269459999997f, -10.028357972f },
	{ 1.8707504480000001f, 1.479506142f, -10.028357972f },
	{ 1.9014166239999999f, 1.479506142f, -9.975243473999999f },
	{ 1.9014166239999999f, -2.7218269459999997f, -9.975243473999999f },
	{ 2.821416624f, -2.7218269459999997f, -9.975243473999999f },
	{ 2.821416624f, 1.433506096f, -9.975243473999999f },
	{ 2.7907504480000003f, -2.7218269459999997f, -9.92212617f },
	{ 2.7907504480000003f, 1.433506096f, -9.92212617f },
	{ 2.7294166239999997f, 1.433506096f, -9.92212617f },
	{ 2.7294166239999997f, -2.7218269459999997f, -9.92212617f },
	{ 2.698749712f, -2.7218269459999997f, -9.975243473999999f },
	{ 2.698749712f, 1.433506096f, -9.975243473999999f },
	{ 2.698749712f, -2.7218269459999997f, -9.975243473999999f },
	{ 2.698749712f, 1.433506096f, -9.975243473999999f },
	{ 2.7294166239999997f, 1.433506096f, -10.028357972f },
	{ 2.7294166239999997f, -2.7218269459999997f, -10.028357972f },
	{ 2.7907504480000003f, -2.7218269459999997f, -10.028357972f },
	{ 2.7907504480000003f, 1.433506096f, -10.028357972f },
	{ 2.821416624f, 1.433506096f, -9.975243473999999f },
	{ 2.821416624f, -2.7218269459999997f, -9.975243473999999f },
	{ 3.7414166239999997f, -2.7218269459999997f, -9.975243473999999f },
	{ 3.7414166239999997f, 1.30470628f, -9.975243473999999f },
	{ 3.7107504479999998f, -2.7218269459999997f, -9.92212617f },
	{ 3.7107504479999998f, 1.30470628f, -9.92212617f },
	{ 3.649416624f, 1.30470628f, -9.92212617f },
	{ 3.649416624f, -2.7218269459999997f, -9.92212617f },
	{ 3.6187497119999996f, -2.7218269459999997f, -9.975243473999999f },
	{ 3.6187497119999996f, 1.30470628f, -9.975243473999999f },
	{ 3.6187497119999996f, -2.7218269459999997f, -9.975243473999999f },
	{ 3.6187497119999996f, 1.30470628f, -9.975243473999999f },
	{ 3.649416624f, 1.30470628f, -10.028357972f },
	{ 3.649416624f, -2.7218269459999997f, -10.028357972f },
	{ 3.7107504479999998f, -2.7218269459999997f, -10.028357972f },
	{ 3.7107504479999998f, 1.30470628f, -10.028357972f },
	{ 3.7414166239999997f, 1.30470628f, -9.975243473999999f },
	{ 3.7414166239999997f, -2.7218269459999997f, -9.975243473999999f }
};

GLfloat static p_textures[288][2] = {
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f },
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f },
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f },
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f },
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f },
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f },
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f },
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f },
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f },
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f },
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f },
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f },
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f },
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f },
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f },
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f },
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f },
	{ 0.998886f, 0.005917f },
	{ 0.998886f, 0.999982f },
	{ 0.75031f, 0.005917f },
	{ 0.75031f, 0.999982f },
	{ 0.253154f, 0.999982f },
	{ 0.253154f, 0.005917f },
	{ 0.004576f, 0.005917f },
	{ 0.004576f, 0.999982f },
	{ 0.004489f, 0.005685f },
	{ 0.004489f, 0.99975f },
	{ 0.253066f, 0.99975f },
	{ 0.253066f, 0.005685f },
	{ 0.750221f, 0.005685f },
	{ 0.750221f, 0.99975f },
	{ 0.9988f, 0.99975f },
	{ 0.9988f, 0.005685f }
};

GLfloat static p_normals[288][3] = {
	{ 0.866025f, 0.0f, 0.5f },
	{ 0.866025f, 0.0f, 0.5f },
	{ 0.5f, 0.0f, 0.866025f },
	{ 0.5f, 0.0f, 0.866025f },
	{ -0.500002f, 0.0f, 0.866024f },
	{ -0.500002f, 0.0f, 0.866024f },
	{ -0.866028f, 0.0f, 0.499996f },
	{ -0.866028f, 0.0f, 0.499996f },
	{ -0.866028f, 0.0f, -0.499996f },
	{ -0.866028f, 0.0f, -0.499996f },
	{ -0.500002f, 0.0f, -0.866024f },
	{ -0.500002f, 0.0f, -0.866024f },
	{ 0.5f, 0.0f, -0.866025f },
	{ 0.5f, 0.0f, -0.866025f },
	{ 0.866025f, 0.0f, -0.5f },
	{ 0.866025f, 0.0f, -0.5f },
	{ 0.866025f, 0.0f, 0.5f },
	{ 0.866025f, 0.0f, 0.5f },
	{ 0.5f, 0.0f, 0.866025f },
	{ 0.5f, 0.0f, 0.866025f },
	{ -0.500002f, 0.0f, 0.866024f },
	{ -0.500002f, 0.0f, 0.866024f },
	{ -0.866028f, 0.0f, 0.499996f },
	{ -0.866028f, 0.0f, 0.499996f },
	{ -0.866028f, 0.0f, -0.499996f },
	{ -0.866028f, 0.0f, -0.499996f },
	{ -0.500002f, 0.0f, -0.866024f },
	{ -0.500002f, 0.0f, -0.866024f },
	{ 0.5f, 0.0f, -0.866025f },
	{ 0.5f, 0.0f, -0.866025f },
	{ 0.866025f, 0.0f, -0.5f },
	{ 0.866025f, 0.0f, -0.5f },
	{ 0.866025f, 0.0f, 0.5f },
	{ 0.866025f, 0.0f, 0.5f },
	{ 0.5f, 0.0f, 0.866025f },
	{ 0.5f, 0.0f, 0.866025f },
	{ -0.500002f, 0.0f, 0.866024f },
	{ -0.500002f, 0.0f, 0.866024f },
	{ -0.866028f, 0.0f, 0.499996f },
	{ -0.866028f, 0.0f, 0.499996f },
	{ -0.866028f, 0.0f, -0.499996f },
	{ -0.866028f, 0.0f, -0.499996f },
	{ -0.500002f, 0.0f, -0.866024f },
	{ -0.500002f, 0.0f, -0.866024f },
	{ 0.5f, 0.0f, -0.866025f },
	{ 0.5f, 0.0f, -0.866025f },
	{ 0.866025f, 0.0f, -0.5f },
	{ 0.866025f, 0.0f, -0.5f },
	{ 0.866025f, 0.0f, 0.5f },
	{ 0.866025f, 0.0f, 0.5f },
	{ 0.5f, 0.0f, 0.866025f },
	{ 0.5f, 0.0f, 0.866025f },
	{ -0.500002f, 0.0f, 0.866024f },
	{ -0.500002f, 0.0f, 0.866024f },
	{ -0.866028f, 0.0f, 0.499996f },
	{ -0.866028f, 0.0f, 0.499996f },
	{ -0.866028f, 0.0f, -0.499996f },
	{ -0.866028f, 0.0f, -0.499996f },
	{ -0.500002f, 0.0f, -0.866024f },
	{ -0.500002f, 0.0f, -0.866024f },
	{ 0.5f, 0.0f, -0.866025f },
	{ 0.5f, 0.0f, -0.866025f },
	{ 0.866025f, 0.0f, -0.5f },
	{ 0.866025f, 0.0f, -0.5f },
	{ 0.866025f, 0.0f, 0.5f },
	{ 0.866025f, 0.0f, 0.5f },
	{ 0.5f, 0.0f, 0.866025f },
	{ 0.5f, 0.0f, 0.866025f },
	{ -0.500002f, 0.0f, 0.866024f },
	{ -0.500002f, 0.0f, 0.866024f },
	{ -0.866028f, 0.0f, 0.499996f },
	{ -0.866028f, 0.0f, 0.499996f },
	{ -0.866028f, 0.0f, -0.499996f },
	{ -0.866028f, 0.0f, -0.499996f },
	{ -0.500002f, 0.0f, -0.866024f },
	{ -0.500002f, 0.0f, -0.866024f },
	{ 0.5f, 0.0f, -0.866025f },
	{ 0.5f, 0.0f, -0.866025f },
	{ 0.866025f, 0.0f, -0.5f },
	{ 0.866025f, 0.0f, -0.5f },
	{ 0.866025f, 0.0f, 0.5f },
	{ 0.866025f, 0.0f, 0.5f },
	{ 0.5f, 0.0f, 0.866025f },
	{ 0.5f, 0.0f, 0.866025f },
	{ -0.500002f, 0.0f, 0.866024f },
	{ -0.500002f, 0.0f, 0.866024f },
	{ -0.866028f, 0.0f, 0.499996f },
	{ -0.866028f, 0.0f, 0.499996f },
	{ -0.866028f, 0.0f, -0.499996f },
	{ -0.866028f, 0.0f, -0.499996f },
	{ -0.500002f, 0.0f, -0.866024f },
	{ -0.500002f, 0.0f, -0.866024f },
	{ 0.5f, 0.0f, -0.866025f },
	{ 0.5f, 0.0f, -0.866025f },
	{ 0.866025f, 0.0f, -0.5f },
	{ 0.866025f, 0.0f, -0.5f },
	{ 0.86603f, 0.0f, 0.499992f },
	{ 0.86603f, 0.0f, 0.499992f },
	{ 0.500004f, 0.0f, 0.866023f },
	{ 0.500004f, 0.0f, 0.866023f },
	{ -0.5f, 0.0f, 0.866025f },
	{ -0.5f, 0.0f, 0.866025f },
	{ -0.866025f, 0.0f, 0.5f },
	{ -0.866025f, 0.0f, 0.5f },
	{ -0.866025f, 0.0f, -0.5f },
	{ -0.866025f, 0.0f, -0.5f },
	{ -0.5f, 0.0f, -0.866025f },
	{ -0.5f, 0.0f, -0.866025f },
	{ 0.500004f, 0.0f, -0.866023f },
	{ 0.500004f, 0.0f, -0.866023f },
	{ 0.86603f, 0.0f, -0.499992f },
	{ 0.86603f, 0.0f, -0.499992f },
	{ 0.86603f, 0.0f, 0.499992f },
	{ 0.86603f, 0.0f, 0.499992f },
	{ 0.500004f, 0.0f, 0.866023f },
	{ 0.500004f, 0.0f, 0.866023f },
	{ -0.5f, 0.0f, 0.866025f },
	{ -0.5f, 0.0f, 0.866025f },
	{ -0.866025f, 0.0f, 0.5f },
	{ -0.866025f, 0.0f, 0.5f },
	{ -0.866025f, 0.0f, -0.5f },
	{ -0.866025f, 0.0f, -0.5f },
	{ -0.5f, 0.0f, -0.866025f },
	{ -0.5f, 0.0f, -0.866025f },
	{ 0.500004f, 0.0f, -0.866023f },
	{ 0.500004f, 0.0f, -0.866023f },
	{ 0.86603f, 0.0f, -0.499992f },
	{ 0.86603f, 0.0f, -0.499992f },
	{ 0.86603f, 0.0f, 0.499992f },
	{ 0.86603f, 0.0f, 0.499992f },
	{ 0.500004f, 0.0f, 0.866023f },
	{ 0.500004f, 0.0f, 0.866023f },
	{ -0.5f, 0.0f, 0.866025f },
	{ -0.5f, 0.0f, 0.866025f },
	{ -0.866025f, 0.0f, 0.5f },
	{ -0.866025f, 0.0f, 0.5f },
	{ -0.866025f, 0.0f, -0.5f },
	{ -0.866025f, 0.0f, -0.5f },
	{ -0.5f, 0.0f, -0.866025f },
	{ -0.5f, 0.0f, -0.866025f },
	{ 0.500004f, 0.0f, -0.866023f },
	{ 0.500004f, 0.0f, -0.866023f },
	{ 0.86603f, 0.0f, -0.499992f },
	{ 0.86603f, 0.0f, -0.499992f },
	{ 0.866028f, 0.0f, 0.499995f },
	{ 0.866028f, 0.0f, 0.499995f },
	{ 0.500002f, 0.0f, 0.866024f },
	{ 0.500002f, 0.0f, 0.866024f },
	{ -0.500004f, 0.0f, 0.866023f },
	{ -0.500005f, 0.0f, 0.866023f },
	{ -0.866031f, 0.0f, 0.499991f },
	{ -0.866031f, 0.0f, 0.499991f },
	{ -0.866019f, 0.0f, -0.500011f },
	{ -0.866019f, 0.0f, -0.500011f },
	{ -0.499995f, 0.0f, -0.866028f },
	{ -0.499995f, 0.0f, -0.866028f },
	{ 0.499993f, 0.0f, -0.86603f },
	{ 0.499992f, 0.0f, -0.86603f },
	{ 0.866017f, 0.0f, -0.500015f },
	{ 0.866017f, 0.0f, -0.500015f },
	{ 0.866028f, 0.0f, 0.499995f },
	{ 0.866028f, 0.0f, 0.499995f },
	{ 0.500002f, 0.0f, 0.866024f },
	{ 0.500002f, 0.0f, 0.866024f },
	{ -0.500005f, 0.0f, 0.866023f },
	{ -0.500005f, 0.0f, 0.866023f },
	{ -0.866031f, 0.0f, 0.499991f },
	{ -0.866031f, 0.0f, 0.499991f },
	{ -0.866019f, 0.0f, -0.500011f },
	{ -0.866019f, 0.0f, -0.500011f },
	{ -0.499995f, 0.0f, -0.866028f },
	{ -0.499995f, 0.0f, -0.866028f },
	{ 0.499993f, 0.0f, -0.86603f },
	{ 0.499992f, 0.0f, -0.86603f },
	{ 0.866017f, 0.0f, -0.500015f },
	{ 0.866017f, 0.0f, -0.500015f },
	{ 0.866028f, 0.0f, 0.499995f },
	{ 0.866028f, 0.0f, 0.499995f },
	{ 0.500003f, 0.0f, 0.866024f },
	{ 0.500002f, 0.0f, 0.866024f },
	{ -0.500005f, 0.0f, 0.866022f },
	{ -0.500005f, 0.0f, 0.866023f },
	{ -0.866031f, 0.0f, 0.499991f },
	{ -0.866031f, 0.0f, 0.499991f },
	{ -0.866019f, 0.0f, -0.500011f },
	{ -0.866019f, 0.0f, -0.500011f },
	{ -0.499995f, 0.0f, -0.866028f },
	{ -0.499995f, 0.0f, -0.866028f },
	{ 0.499993f, 0.0f, -0.86603f },
	{ 0.499992f, 0.0f, -0.86603f },
	{ 0.866017f, 0.0f, -0.500015f },
	{ 0.866017f, 0.0f, -0.500015f },
	{ 0.866028f, 0.0f, 0.499995f },
	{ 0.866028f, 0.0f, 0.499995f },
	{ 0.500003f, 0.0f, 0.866024f },
	{ 0.500002f, 0.0f, 0.866024f },
	{ -0.500005f, 0.0f, 0.866022f },
	{ -0.500005f, 0.0f, 0.866023f },
	{ -0.866031f, 0.0f, 0.499991f },
	{ -0.866031f, 0.0f, 0.499991f },
	{ -0.866019f, 0.0f, -0.500011f },
	{ -0.866019f, 0.0f, -0.500011f },
	{ -0.499995f, 0.0f, -0.866028f },
	{ -0.499995f, 0.0f, -0.866028f },
	{ 0.499993f, 0.0f, -0.86603f },
	{ 0.499992f, 0.0f, -0.86603f },
	{ 0.866017f, 0.0f, -0.500015f },
	{ 0.866017f, 0.0f, -0.500015f },
	{ 0.866028f, 0.0f, 0.499995f },
	{ 0.866028f, 0.0f, 0.499995f },
	{ 0.500003f, 0.0f, 0.866024f },
	{ 0.500002f, 0.0f, 0.866024f },
	{ -0.500005f, 0.0f, 0.866022f },
	{ -0.500005f, 0.0f, 0.866023f },
	{ -0.866031f, 0.0f, 0.499991f },
	{ -0.866031f, 0.0f, 0.499991f },
	{ -0.866019f, 0.0f, -0.500011f },
	{ -0.866019f, 0.0f, -0.500011f },
	{ -0.499995f, 0.0f, -0.866028f },
	{ -0.499995f, 0.0f, -0.866028f },
	{ 0.499993f, 0.0f, -0.86603f },
	{ 0.499992f, 0.0f, -0.86603f },
	{ 0.866017f, 0.0f, -0.500015f },
	{ 0.866017f, 0.0f, -0.500015f },
	{ 0.866028f, 0.0f, 0.499995f },
	{ 0.866028f, 0.0f, 0.499995f },
	{ 0.500003f, 0.0f, 0.866024f },
	{ 0.500002f, 0.0f, 0.866024f },
	{ -0.500005f, 0.0f, 0.866022f },
	{ -0.500005f, 0.0f, 0.866023f },
	{ -0.866031f, 0.0f, 0.499991f },
	{ -0.866031f, 0.0f, 0.499991f },
	{ -0.866019f, 0.0f, -0.500011f },
	{ -0.866019f, 0.0f, -0.500011f },
	{ -0.499995f, 0.0f, -0.866028f },
	{ -0.499995f, 0.0f, -0.866028f },
	{ 0.499993f, 0.0f, -0.86603f },
	{ 0.499992f, 0.0f, -0.86603f },
	{ 0.866017f, 0.0f, -0.500015f },
	{ 0.866017f, 0.0f, -0.500015f },
	{ 0.866033f, 0.0f, 0.499987f },
	{ 0.866033f, 0.0f, 0.499987f },
	{ 0.500007f, 0.0f, 0.866021f },
	{ 0.500007f, 0.0f, 0.866022f },
	{ -0.500003f, 0.0f, 0.866024f },
	{ -0.500002f, 0.0f, 0.866024f },
	{ -0.866028f, 0.0f, 0.499995f },
	{ -0.866028f, 0.0f, 0.499995f },
	{ -0.866017f, 0.0f, -0.500015f },
	{ -0.866017f, 0.0f, -0.500015f },
	{ -0.499993f, 0.0f, -0.86603f },
	{ -0.499992f, 0.0f, -0.86603f },
	{ 0.499997f, 0.0f, -0.866027f },
	{ 0.499997f, 0.0f, -0.866027f },
	{ 0.866022f, 0.0f, -0.500006f },
	{ 0.866022f, 0.0f, -0.500006f },
	{ 0.866033f, 0.0f, 0.499987f },
	{ 0.866033f, 0.0f, 0.499987f },
	{ 0.500007f, 0.0f, 0.866022f },
	{ 0.500007f, 0.0f, 0.866022f },
	{ -0.500002f, 0.0f, 0.866024f },
	{ -0.500002f, 0.0f, 0.866024f },
	{ -0.866028f, 0.0f, 0.499995f },
	{ -0.866028f, 0.0f, 0.499995f },
	{ -0.866017f, 0.0f, -0.500015f },
	{ -0.866017f, 0.0f, -0.500015f },
	{ -0.499993f, 0.0f, -0.86603f },
	{ -0.499992f, 0.0f, -0.86603f },
	{ 0.499997f, 0.0f, -0.866027f },
	{ 0.499997f, 0.0f, -0.866027f },
	{ 0.866022f, 0.0f, -0.500006f },
	{ 0.866022f, 0.0f, -0.500006f },
	{ 0.866033f, 0.0f, 0.499987f },
	{ 0.866033f, 0.0f, 0.499987f },
	{ 0.500007f, 0.0f, 0.866022f },
	{ 0.500007f, 0.0f, 0.866022f },
	{ -0.500002f, 0.0f, 0.866024f },
	{ -0.500002f, 0.0f, 0.866024f },
	{ -0.866028f, 0.0f, 0.499995f },
	{ -0.866028f, 0.0f, 0.499995f },
	{ -0.866017f, 0.0f, -0.500015f },
	{ -0.866017f, 0.0f, -0.500015f },
	{ -0.499993f, 0.0f, -0.86603f },
	{ -0.499992f, 0.0f, -0.86603f },
	{ 0.499997f, 0.0f, -0.866027f },
	{ 0.499997f, 0.0f, -0.866027f },
	{ 0.866022f, 0.0f, -0.500006f },
	{ 0.866022f, 0.0f, -0.500006f }
};

GLushort static p_indexes[216][3] = {
	{ 0, 1, 2 },
	{ 1, 3, 2 },
	{ 2, 3, 4 },
	{ 2, 4, 5 },
	{ 5, 4, 6 },
	{ 4, 7, 6 },
	{ 8, 9, 10 },
	{ 8, 10, 11 },
	{ 11, 10, 12 },
	{ 10, 13, 12 },
	{ 12, 13, 14 },
	{ 12, 14, 15 },
	{ 16, 17, 18 },
	{ 17, 19, 18 },
	{ 18, 19, 20 },
	{ 18, 20, 21 },
	{ 21, 20, 22 },
	{ 20, 23, 22 },
	{ 24, 25, 26 },
	{ 24, 26, 27 },
	{ 27, 26, 28 },
	{ 26, 29, 28 },
	{ 28, 29, 30 },
	{ 28, 30, 31 },
	{ 32, 33, 34 },
	{ 33, 35, 34 },
	{ 34, 35, 36 },
	{ 34, 36, 37 },
	{ 37, 36, 38 },
	{ 36, 39, 38 },
	{ 40, 41, 42 },
	{ 40, 42, 43 },
	{ 43, 42, 44 },
	{ 42, 45, 44 },
	{ 44, 45, 46 },
	{ 44, 46, 47 },
	{ 48, 49, 50 },
	{ 49, 51, 50 },
	{ 50, 51, 52 },
	{ 50, 52, 53 },
	{ 53, 52, 54 },
	{ 52, 55, 54 },
	{ 56, 57, 58 },
	{ 56, 58, 59 },
	{ 59, 58, 60 },
	{ 58, 61, 60 },
	{ 60, 61, 62 },
	{ 60, 62, 63 },
	{ 64, 65, 66 },
	{ 65, 67, 66 },
	{ 66, 67, 68 },
	{ 66, 68, 69 },
	{ 69, 68, 70 },
	{ 68, 71, 70 },
	{ 72, 73, 74 },
	{ 72, 74, 75 },
	{ 75, 74, 76 },
	{ 74, 77, 76 },
	{ 76, 77, 78 },
	{ 76, 78, 79 },
	{ 80, 81, 82 },
	{ 81, 83, 82 },
	{ 82, 83, 84 },
	{ 82, 84, 85 },
	{ 85, 84, 86 },
	{ 84, 87, 86 },
	{ 88, 89, 90 },
	{ 88, 90, 91 },
	{ 91, 90, 92 },
	{ 90, 93, 92 },
	{ 92, 93, 94 },
	{ 92, 94, 95 },
	{ 96, 97, 98 },
	{ 97, 99, 98 },
	{ 98, 99, 100 },
	{ 98, 100, 101 },
	{ 101, 100, 102 },
	{ 100, 103, 102 },
	{ 104, 105, 106 },
	{ 104, 106, 107 },
	{ 107, 106, 108 },
	{ 106, 109, 108 },
	{ 108, 109, 110 },
	{ 108, 110, 111 },
	{ 112, 113, 114 },
	{ 113, 115, 114 },
	{ 114, 115, 116 },
	{ 114, 116, 117 },
	{ 117, 116, 118 },
	{ 116, 119, 118 },
	{ 120, 121, 122 },
	{ 120, 122, 123 },
	{ 123, 122, 124 },
	{ 122, 125, 124 },
	{ 124, 125, 126 },
	{ 124, 126, 127 },
	{ 128, 129, 130 },
	{ 129, 131, 130 },
	{ 130, 131, 132 },
	{ 130, 132, 133 },
	{ 133, 132, 134 },
	{ 132, 135, 134 },
	{ 136, 137, 138 },
	{ 136, 138, 139 },
	{ 139, 138, 140 },
	{ 138, 141, 140 },
	{ 140, 141, 142 },
	{ 140, 142, 143 },
	{ 144, 145, 146 },
	{ 145, 147, 146 },
	{ 146, 147, 148 },
	{ 146, 148, 149 },
	{ 149, 148, 150 },
	{ 148, 151, 150 },
	{ 152, 153, 154 },
	{ 152, 154, 155 },
	{ 155, 154, 156 },
	{ 154, 157, 156 },
	{ 156, 157, 158 },
	{ 156, 158, 159 },
	{ 160, 161, 162 },
	{ 161, 163, 162 },
	{ 162, 163, 164 },
	{ 162, 164, 165 },
	{ 165, 164, 166 },
	{ 164, 167, 166 },
	{ 168, 169, 170 },
	{ 168, 170, 171 },
	{ 171, 170, 172 },
	{ 170, 173, 172 },
	{ 172, 173, 174 },
	{ 172, 174, 175 },
	{ 176, 177, 178 },
	{ 177, 179, 178 },
	{ 178, 179, 180 },
	{ 178, 180, 181 },
	{ 181, 180, 182 },
	{ 180, 183, 182 },
	{ 184, 185, 186 },
	{ 184, 186, 187 },
	{ 187, 186, 188 },
	{ 186, 189, 188 },
	{ 188, 189, 190 },
	{ 188, 190, 191 },
	{ 192, 193, 194 },
	{ 193, 195, 194 },
	{ 194, 195, 196 },
	{ 194, 196, 197 },
	{ 197, 196, 198 },
	{ 196, 199, 198 },
	{ 200, 201, 202 },
	{ 200, 202, 203 },
	{ 203, 202, 204 },
	{ 202, 205, 204 },
	{ 204, 205, 206 },
	{ 204, 206, 207 },
	{ 208, 209, 210 },
	{ 209, 211, 210 },
	{ 210, 211, 212 },
	{ 210, 212, 213 },
	{ 213, 212, 214 },
	{ 212, 215, 214 },
	{ 216, 217, 218 },
	{ 216, 218, 219 },
	{ 219, 218, 220 },
	{ 218, 221, 220 },
	{ 220, 221, 222 },
	{ 220, 222, 223 },
	{ 224, 225, 226 },
	{ 225, 227, 226 },
	{ 226, 227, 228 },
	{ 226, 228, 229 },
	{ 229, 228, 230 },
	{ 228, 231, 230 },
	{ 232, 233, 234 },
	{ 232, 234, 235 },
	{ 235, 234, 236 },
	{ 234, 237, 236 },
	{ 236, 237, 238 },
	{ 236, 238, 239 },
	{ 240, 241, 242 },
	{ 241, 243, 242 },
	{ 242, 243, 244 },
	{ 242, 244, 245 },
	{ 245, 244, 246 },
	{ 244, 247, 246 },
	{ 248, 249, 250 },
	{ 248, 250, 251 },
	{ 251, 250, 252 },
	{ 250, 253, 252 },
	{ 252, 253, 254 },
	{ 252, 254, 255 },
	{ 256, 257, 258 },
	{ 257, 259, 258 },
	{ 258, 259, 260 },
	{ 258, 260, 261 },
	{ 261, 260, 262 },
	{ 260, 263, 262 },
	{ 264, 265, 266 },
	{ 264, 266, 267 },
	{ 267, 266, 268 },
	{ 266, 269, 268 },
	{ 268, 269, 270 },
	{ 268, 270, 271 },
	{ 272, 273, 274 },
	{ 273, 275, 274 },
	{ 274, 275, 276 },
	{ 274, 276, 277 },
	{ 277, 276, 278 },
	{ 276, 279, 278 },
	{ 280, 281, 282 },
	{ 280, 282, 283 },
	{ 283, 282, 284 },
	{ 282, 285, 284 },
	{ 284, 285, 286 },
	{ 284, 286, 287 }
};

RVBed_1::RVBed_1()
{
	numFaces = 216;
	numVertices = 288;

	normals = new GLfloat[numVertices * 3];
	for (int i = 0; i < numVertices; i++) for (int j = 0; j < 3; j++) normals[3 * i + j] = p_normals[i][j];
	vertices = new GLfloat[numVertices * 3];
	for (int i = 0; i < numVertices; i++) for (int j = 0; j < 3; j++) vertices[3 * i + j] = p_vertices[i][j];
	textures = new GLfloat[numVertices * 2];
	for (int i = 0; i < numVertices; i++) for (int j = 0; j < 2; j++) textures[2 * i + j] = p_textures[i][j];
	indexes = new GLushort[numFaces * 3];
	for (int i = 0; i < numFaces; i++) for (int j = 0; j < 3; j++) indexes[3 * i + j] = p_indexes[i][j];
}
