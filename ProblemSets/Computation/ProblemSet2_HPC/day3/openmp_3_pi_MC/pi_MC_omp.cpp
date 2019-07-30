#include <iostream>
#include <vector>
#include <cstdlib>      //defines rand(), srand(), RAND_MAX
#include <ctime>        //defines ctime() for random numbers
#include <cmath>        //defines math functions
#include <omp.h>

int main()
{
    double x, y;
    srand(time(NULL));      //creates the seed time
    double a = 0;              //times a dart ends up inside the circle
    int numThrows = 5000000;          //times to throw the dart
    std::vector<double> throwDist(numThrows * 4);
    int num_threads = omp_get_max_threads();
    int i;
    double time_parallel = -omp_get_wtime();

    //creates 2 random numbers 'n' times
    #pragma omp parallel shared(a) private( i)
    #pragma omp for
    for(i = 0; i <= numThrows; i++)
    {
        x = (double)rand() / (RAND_MAX);
        y = (double)rand() / (RAND_MAX);
        throwDist[i] = sqrt(x*x + y*y);
    }
    //counts how often the dart is thrown inside the circle
    #pragma omp parallel for reduction(+:a)
    for(i = 0; i<= numThrows; i++)
    {
        if(throwDist[i] <= 1)
        {
            a += 1;
        }
    }
    time_parallel += omp_get_wtime();
    double pi_value = a / numThrows * 4;
    std::cout << "Compute the value of PI = " << pi_value << std::endl;
    std::cout << "parallely that took " << time_parallel << " seconds" << std::endl;

    std::cout << "==============================================================" << '\n';
return 0;
}
