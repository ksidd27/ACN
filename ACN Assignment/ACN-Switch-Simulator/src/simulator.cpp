#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "../include/metrics.h"
#include "../include/switch.h"
#include "../include/scheduler.h"

using namespace std;

extern void generate_packets(
    vector<InputPort>& inputs,
    int N,
    double p,
    int current_time);

extern void transmit_packets(
    vector<OutputPort>& outputs,
    int current_time);

extern long long total_packets;

void run_simulation(
    int N,
    int B,
    double p,
    string queueType,
    int T,
    int K,
    string outputFile)

{
    vector<InputPort> inputs(N);
    vector<OutputPort> outputs(N);


    int t;
    for(t=0; t<T; t++)
    {
        total_slots++;

        generate_packets(inputs, N, p, t);

        if(queueType == "INQ")
            schedule_INQ(inputs, outputs, N);

        else if(queueType == "KOUQ")
            schedule_KOUQ(inputs, outputs, N, K);

        else if(queueType == "iSLIP")
            schedule_iSLIP(inputs, outputs, N);

        transmit_packets(outputs, t);
    }


    double avg_delay = compute_avg_delay();
    double std_dev = compute_std_dev();
    double utilization = compute_link_utilization(N, T);
    double drop_prob = compute_drop_probability();

    cout << "Simulation Finished\n";
    cout << "Packets Transmitted: " << total_packets << endl;
    cout << "Average Delay: " << avg_delay << endl;
    cout << "Standard Deviation Delay: " << std_dev << endl;
    cout << "Link Utilization: " << utilization << endl;
    cout << "Drop Probability: " << drop_prob << endl;

    ofstream fout(outputFile, ios::app);

    fout << N << " " << p << " " << queueType << " " << avg_delay << " " << std_dev << " " << utilization << " " << drop_prob << endl;

    fout.close();


}
