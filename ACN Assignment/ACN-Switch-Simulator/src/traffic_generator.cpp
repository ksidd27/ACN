#include <cstdlib>
#include <vector>
#include "../include/switch.h"

using namespace std;

void generate_packets(
    vector<InputPort>& inputs,
    int N,
    double p,
    int current_time)
{
    for(int i=0;i<N;i++)
    {
        double r = (double) rand() / RAND_MAX;

        if(r < p)
        {
            Packet pkt;

            pkt.src = i;
            pkt.dest = rand() % N;
            pkt.arrival_time = current_time;

            if(inputs[i].buffer.size() < 4)
            {
                inputs[i].buffer.push(pkt);
            }
        }
    }
}