#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <math.h>

const int nstep = 40000000;
const double PI = 3.14159265358979323846;

const double a = -4.0;
const double b = 4.0;

void print_time(double ans,int potoks){
    printf("Кол-во потоков: %d\n",potoks);
    printf("Время: %.16f\n", ans);
}

double func(double x){
    return exp(-x*x);
}

double integrate_omp(double (*func)(double), double a, double b, int n,int potoks)
{
    double h = (b - a) / n;
    double sum = 0.0;


#pragma omp parallel num_threads(potoks)
    {
        int nthreads = omp_get_num_threads();
        int threadid = omp_get_thread_num();
        int items_per_thread = n / nthreads;

        int lb = threadid * items_per_thread;
        int ub = (threadid == nthreads - 1) ? (n - 1) : (lb + items_per_thread - 1);
        double sumloc = 0.0;


        for (int i = lb; i <= ub; i++)
            sumloc += func(a + h * (i + 0.5));
        #pragma omp atomic
        sum+=sumloc;
    }
    sum *= h;

    return sum;
}


int main(int argc, char const *argv[])
{
    int potoks = atoi(argv[1]);

    double start = omp_get_wtime();
    double res  = integrate_omp(func,a,b,nstep, potoks);
    double end = omp_get_wtime();

    print_time(end - start,potoks);
    
    return 0;
}