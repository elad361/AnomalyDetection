#include <iostream>

float avg(float* x, int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += x[i];
    }
    return sum / size;
}
float var(float* x, int size)
{
    float sum = 0;
    float mu = avg(x, size);
    for (int i = 0; i < size; i++) {
        sum += (x[i] - mu)*(x[i] - mu);
    }
    return sum / size;
}
int main()
{
   float x[5];
   for (int i = 0; i < 5; i++) {
       std::cout << " enter num: ";
       std::cin >> x[i];
   }
   float vari = var(x, 5);
   std::cout << "var: " << vari;
}
