#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

using namespace std;

void createA(vector<vector<double>> &A, int N) {
    for (int i = 0; i < N; ++i) {
        vector<double> row(N, 1.0); 
        row[i] = 2.0;               
        A.push_back(row);
    }
}

void createB(vector<double> &b, int N) {
    for (int i = 0; i < N; ++i) {
        b.push_back(N + 1.0); 
    }
}

void simpleIteration(const vector<vector<double>> &A, const vector<double> &b, vector<double> &x, double epsilon, int maxIter, int numThreads, double t) {
    int N = A.size();
    vector<double> x_new(N, 0.0);

    #pragma omp parallel num_threads(numThreads)
    {
        double maxDiff = 0.0;

        for (int iter = 0; iter < maxIter; ++iter) {
            maxDiff = 0.0;

            #pragma omp for schedule(dynamic)
            for (int i = 0; i < N; ++i) {
                double sum = 0.0;
                for (int j = 0; j < N; ++j) {
                    if (i != j) {
                        sum += A[i][j] * x[j];
                    }
                }

                double delta_x = (b[i] - sum) / A[i][i];
                x_new[i] = x[i] + t * delta_x;

                double localDiff = abs(x_new[i] - x[i]);

                #pragma omp critical
                {
                    if (localDiff > maxDiff) {
                        maxDiff = localDiff;
                    }
                }
            }
            x = x_new;
        }
    }
}

int main(int argc, char *argv[]) {
    int N = 10000;          
    double epsilon = 1e-5; 
    int maxIter = 10000;   
    double t = 1.5;        
    int numThreads = stoi(argv[1]);

    vector<vector<double>> A;
    vector<double> b;
    createA(A, N);
    createB(b, N);

    vector<double> x(N, 0.0);

    double start_time = omp_get_wtime();
    simpleIteration(A, b, x, epsilon, maxIter, numThreads, t);
    double end_time = omp_get_wtime();

    cout << "Кол-во потоков:" << numThreads << endl;
    cout << "Время: " << end_time - start_time << " секунд" << endl;

    bool isCorrect = true;
    for (int i = 0; i < N; ++i) {
        if (abs(x[i] - 1.0) > epsilon) {
            isCorrect = false;
            break;
        }
    }

    if (isCorrect) {
        cout << "Верно" << endl;
    } else {
        cout << "Неверно" << endl;
    }

    return 0;
}
