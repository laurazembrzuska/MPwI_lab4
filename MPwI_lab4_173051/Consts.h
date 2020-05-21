#pragma once

#define MAX_ITER 100000
#define SIZE_PROB_ARRAY 4

const double probArray[SIZE_PROB_ARRAY][SIZE_PROB_ARRAY] =
{ {0, 0, 0.1, 0.1},
	{ 0.2,0,0,0.2 },
	{ 0,0,0.3,0 },
	{ 0,0.5,0,0.5 } };