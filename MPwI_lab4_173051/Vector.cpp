#include <iostream>
#include <stdio.h>    
#include <stdlib.h>     
#include <time.h>  
#include "Vector.h"
#include "Consts.h"

double probX[SIZE_PROB_ARRAY];
double probY[SIZE_PROB_ARRAY][SIZE_PROB_ARRAY];
unsigned int frequencyMatrix[SIZE_PROB_ARRAY][SIZE_PROB_ARRAY];
int indexCounter = 0;

struct VectorData
{
	int x;
	double originalX;
	int y;
	double originalY;
};

VectorData generatedVectors[MAX_ITER];

void createProbXArray()
{
	for (int h = 0; h < SIZE_PROB_ARRAY; h++)
	{
		probX[h] = 0;
		for (int w = 0; w < SIZE_PROB_ARRAY; w++)
		{
			probX[h] += probArray[h][w];
		}
	}

}

void createProbYArray()
{
	for (int h = 0; h < SIZE_PROB_ARRAY; h++)
	{
		for (int w = 0; w < SIZE_PROB_ARRAY; w++)
		{
			probY[h][w] = 0;
			probY[h][w] = probArray[h][w] / probX[h];
		}
	}
}

void initFrequencyMatrix()
{
	for (int i = 0; i < SIZE_PROB_ARRAY; i++)
	{
		for (int j = 0; j < SIZE_PROB_ARRAY; j++)
		{
			frequencyMatrix[i][j] = 0;
		}
	}
}

double randZeroToOne()
{
	return rand() / (RAND_MAX + 1.0);
}

void Vector::generateVectors()
{
	srand(time(NULL));
	int tmpX = 0;
	int tmpY = 0;
	createProbXArray();
	createProbYArray();
	initFrequencyMatrix();

	for (int i = 0; i < MAX_ITER; i++)
	{
		int x = 0;
		int y = 0;
		double tmpX = randZeroToOne();
		double tmpProb = 0;
		for (int i = 0; i < SIZE_PROB_ARRAY; i++)
		{
			tmpProb += probX[i];
			if (tmpX < tmpProb)
			{
				x = i;
				break;
			}
		}

		double tmpY = randZeroToOne();
		tmpProb = 0;

		for (int i = 0; i < SIZE_PROB_ARRAY; i++)
		{
			tmpProb += probY[x][i];
			if (tmpY < tmpProb)
			{
				y = i;
				break;
			}
		}

		frequencyMatrix[x][y]++;

		generatedVectors[indexCounter].x = x + 1;
		generatedVectors[indexCounter].originalX = tmpX;
		generatedVectors[indexCounter].y = y + 1;
		generatedVectors[indexCounter].originalY = tmpY;

		indexCounter++;
	}
}

void Vector::printFrequencyMatrix()
{
	for (int i = 0; i < SIZE_PROB_ARRAY; i++)
	{
		for (int j = 0; j < SIZE_PROB_ARRAY; j++)
		{
			std::cout << frequencyMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Number of generated numbers: " << indexCounter << std::endl;
}

void Vector::printGeneratedVectors()
{
	for (int i = 0; i < indexCounter; i++)
	{
		std::cout << i + 1 << ": (" << generatedVectors[i].originalX << ", " << generatedVectors[i].originalY << ")" <<
			" --> " << "(" << generatedVectors[i].x << ", " << generatedVectors[i].y << ")" << std::endl;
	}
}