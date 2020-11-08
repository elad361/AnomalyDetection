#include <cmath>
#include "anomaly_detection_util.h"

//return the avg of the given array
float avg(float* x, int size)
{
	if (size == 0)
		return 0;
	
	float sum = 0;
	for (int i = 0; i < size; i++) {
		sum += x[i];
	}
	return sum / size;
}

// returns the variance of X and Y
float var(float* x, int size)
{
	if (size == 0)
		return 0;

	float sum = 0;
	float mu = avg(x, size);
	for (int i = 0; i < size; i++) {
		sum += (x[i] - mu) * (x[i] - mu);
	}
	return sum / size;
}

// returns the covariance of X and Y
float cov(float* x, float* y, int size)
{
	if (size == 0)
		return 0;

	float xMu = avg(x, size), yMu = avg(y, size), sum = 0;
	for (int i = 0; i < size; i++) {
		sum += (x[i] - xMu) * (y[i] - yMu);
	}
	return sum / size;
}

// returns the Pearson correlation coefficient of X and Y
float pearson(float* x, float* y, int size)
{
	if (size == 0)
		return 0;

	float covariance = cov(x, y, size);
	float standardDeviation = std::sqrt(var(x, size) * var(y, size));
	return covariance / standardDeviation;
}

// performs a linear regression and return s the line equation
Line linear_reg(Point** points, int size)
{
	if (size == 0)
		return Line(0, 0);

	float *x, *y, a, b;
	x = new float[size];
	y = new float[size];
	for (int i = 0; i < size; i++) {
		x[i] = points[i]->x;
		y[i] = points[i]->y;
	}
	a = cov(x, y, size) / var(x, size);
	b = (avg(y, size) - (a * avg(x, size)));
	return Line(a, b);
}

// returns the deviation between point p and the line
float dev(Point p, Line l) {
	float x = p.x;
	return std::abs(l.f(x) - p.y);
}

// returns the deviation between point p and the line equation of the points
float dev(Point p, Point** points, int size)
{
	Line lineReg = linear_reg(points, size);
	return dev(p, lineReg);
}
