#include "../include/scheduler.h"
#include <vector>
#include <random>

/*
INQ Scheduling
Each input has a single FIFO queue.
If multiple packets request the same output,
randomly select one.
*/

void schedule_INQ(
    std::vector<InputPort>& inputs,
    std::vector<OutputPort>& outputs,
    int N)
{
    std::vector<std::vector<int>> requests(N);

    for(int i = 0; i < N; i++)
    {
        if(!inputs[i].buffer.empty())
        {
            Packet pkt = inputs[i].buffer.front();
            int dest = pkt.dest;

            if(dest >= 0 && dest < N)
                requests[dest].push_back(i);
        }
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());

    for(int out = 0; out < N; out++)
    {
        if(requests[out].empty())
            continue;

        std::uniform_int_distribution<> dist(0, requests[out].size() - 1);

        int selectedInput = requests[out][dist(gen)];

        Packet pkt = inputs[selectedInput].buffer.front();

        if(outputs[out].buffer.size() < outputs[out].buffer_size)
        {
            outputs[out].buffer.push(pkt);
            inputs[selectedInput].buffer.pop();
        }
    }
}