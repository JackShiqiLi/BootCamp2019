#include <iostream>
#include <vector>

#include <omp.h>

int main(void){
    const int N = 10000;
    std::vector<double> a1(N);
    std::vector<double> b1(N);
    std::vector<double> a2(N);
    std::vector<double> b2(N);
    int i;
    int num_threads = omp_get_max_threads();

    std::cout << "dot of vectors with length " << N  << " with " << num_threads << " threads: " << std::endl;

    // initialize the vectors
    #pragma omp parallel shared(a1, b1) private(i)
    #pragma omp for
    for(i=0; i<N; i++) {
        a1[i] = 1./2.;
        b1[i] = double(i+1);
    }

    double time_parallel = -omp_get_wtime();
    double dot1=0.;

    #pragma omp parallel for reduction(+:dot1)
    for(int i=0; i<N; i++) {
        dot1 += a1[i] * b1[i];
    }
    time_parallel += omp_get_wtime();

    // use formula for sum of arithmetic sequence: sum(1:n) = (n+1)*n/2
    double expected = double(N+1)*double(N)/4.;
    std::cout << "dot product " << dot1
              << (dot1==expected ? " which matches the expected value "
                                : " which does not match the expected value ")
              << expected << std::endl;
    std::cout << "parallely that took " << time_parallel << " seconds" << std::endl;

    std::cout << "==============================================================" << '\n';

    std::cout << "dot of vectors with length " << N  << " serially: " << std::endl;

    // initialize the vectors
    for(i=0; i<N; i++) {
        a2[i] = 1./2.;
        b2[i] = double(i+1);
    }

    double time_serial = -omp_get_wtime();
    double dot2=0.;

    for(int i=0; i<N; i++) {
        dot2 += a2[i] * b2[i];
    }
    time_serial += omp_get_wtime();

    // use formula for sum of arithmetic sequence: sum(1:n) = (n+1)*n/2
    int max_threads = omp_get_max_threads();
    std::cout << "dot product " << dot2
              << (dot2==expected ? " which matches the expected value "
                                : " which does not match the expected value ")
              << expected << std::endl;
    std::cout << "serially that took " << time_serial << " seconds" << std::endl;

    std::cout << "==============================================================" << '\n';
    std::cout << "speedup    : " << time_serial/time_parallel << std::endl;
    std::cout << "efficiency : " << (time_serial/time_parallel)/double(max_threads) << std::endl;

    return 0;
}
