#include "../include/scheduler.h"
#include "../include/metrics.h"
#include <vector>
#include <algorithm>
#include <random>

void schedule_KOUQ(
    std::vector<InputPort>& inputs,
    std::vector<OutputPort>& outputs,
    int N,
    int K)
{
    std::vector<std::vector<int>> requests(N);

    for (int i = 0; i < N; i++)
    {
        if (!inputs[i].buffer.empty())
        {
            Packet pkt = inputs[i].buffer.front();
            int dest = pkt.dest;

            if (dest >= 0 && dest < N)
                requests[dest].push_back(i);
        }
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());

    for (int out = 0; out < N; out++)
    {
        int numRequests = requests[out].size();

        if (numRequests == 0)
            continue;

        std::shuffle(requests[out].begin(), requests[out].end(), gen);

        int accepted = std::min(numRequests, K);

        std::vector<Packet> acceptedPackets;

        for (int j = 0; j < accepted; j++)
        {
            int inputIndex = requests[out][j];

            Packet pkt = inputs[inputIndex].buffer.front();

            acceptedPackets.push_back(pkt);

            inputs[inputIndex].buffer.pop();
        }

        std::sort(acceptedPackets.begin(), acceptedPackets.end(),
                  [](const Packet &a, const Packet &b)
                  {
                      return a.arrival_time < b.arrival_time;
                  });

        for (auto &pkt : acceptedPackets)
        {
            if (outputs[out].buffer.size() < outputs[out].buffer_size)
            {
                outputs[out].buffer.push(pkt);
            }
        }

        for (int j = accepted; j < numRequests; j++)
        {
            int inputIndex = requests[out][j];

            if (!inputs[inputIndex].buffer.empty())
                inputs[inputIndex].buffer.pop();
                drop_events++;
        }
    }
}