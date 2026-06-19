#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void run_simulation(
    int N,
    int B,
    double p,
    string queueType,
    int T,
    int K,
    string outputFile);



int main(int argc, char* argv[])
{
    int N = 8;
    int B = 4;
    int T = 10000;
    double p = 0.5;
    int K = 0.8* N;
    string queueType = "INQ";
    string outputFile = "results.txt";

    // Parse command line arguments
    for(int i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], "-N") == 0)
            N = atoi(argv[++i]);

        else if(strcmp(argv[i], "-B") == 0)
            B = atoi(argv[++i]);

        else if(strcmp(argv[i], "-p") == 0)
            p = atof(argv[++i]);

        else if(strcmp(argv[i], "-queue") == 0)
            queueType = argv[++i];

        else if(strcmp(argv[i], "-K") == 0)
            K = atoi(argv[++i]);

        else if(strcmp(argv[i], "-out") == 0)
            outputFile = argv[++i];

        else if(strcmp(argv[i], "-T") == 0)
            T = atoi(argv[++i]);
    }

    cout << "Running Simulation with:\n";
    cout << "N = " << N << ", B = " << B
         << ", p = " << p
         << ", Queue = " << queueType
         << ", T = " << T << endl;

    // run_simulation(N, B, p, queueType, T);
    run_simulation(N, B, p, queueType, T, K, outputFile);

    return 0;
}