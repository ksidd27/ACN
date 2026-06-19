#include "../include/scheduler.h"
#include "../include/packet.h"

#include <vector>
#include <queue>

using namespace std;

/*
Virtual Output Queues
VOQ[input][output]
*/
static vector<vector<queue<Packet>>> VOQ;

/*
Round robin pointers
*/
static vector<int> grant_pointer;
static vector<int> accept_pointer;

/*
Matching arrays
*/
static vector<int> match_input;
static vector<int> match_output;


/*
Initialize structures
*/
void init_islip(int N)
{
    VOQ.assign(N, vector<queue<Packet>>(N));

    grant_pointer.assign(N,0);
    accept_pointer.assign(N,0);

    match_input.assign(N,-1);
    match_output.assign(N,-1);
}


/*
Move packets from input buffers to VOQ
*/
void load_packets(vector<InputPort>& inputs, int N)
{
    for(int i=0;i<N;i++)
    {
        if(!inputs[i].buffer.empty())
        {
            Packet pkt = inputs[i].buffer.front();
            inputs[i].buffer.pop();

            VOQ[i][pkt.dest].push(pkt);
        }
    }
}


/*
REQUEST + GRANT + ACCEPT
*/
void islip_match(int N)
{
    vector<vector<int>> request(N, vector<int>(N,0));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(!VOQ[i][j].empty())
                request[i][j] = 1;
        }
    }

    vector<int> grant(N,-1);

    // GRANT phase
    for(int j=0;j<N;j++)
    {
        for(int k=0;k<N;k++)
        {
            int i = (grant_pointer[j] + k) % N;

            if(request[i][j])
            {
                grant[j] = i;
                break;
            }
        }
    }

    // ACCEPT phase
    for(int i=0;i<N;i++)
    {
        for(int k=0;k<N;k++)
        {
            int j = (accept_pointer[i] + k) % N;

            if(grant[j] == i)
            {
                match_input[i] = j;
                match_output[j] = i;

                grant_pointer[j] = (i+1) % N;
                accept_pointer[i] = (j+1) % N;

                break;
            }
        }
    }
}


/*
Main iSLIP scheduler
*/
void schedule_iSLIP(
    vector<InputPort>& inputs,
    vector<OutputPort>& outputs,
    int N)
{
    static bool initialized = false;

    if(!initialized)
    {
        init_islip(N);
        initialized = true;
    }

    // load packets from inputs into VOQ
    load_packets(inputs, N);

    // perform matching
    islip_match(N);

    // send matched packets to outputs
    for(int i=0;i<N;i++)
    {
        int j = match_input[i];

        if(j != -1)
        {
            if(!VOQ[i][j].empty())
            {
                Packet pkt = VOQ[i][j].front();
                VOQ[i][j].pop();

                outputs[j].buffer.push(pkt);
            }

            match_input[i] = -1;
            match_output[j] = -1;
        }
    }
}