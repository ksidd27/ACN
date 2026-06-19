#include <vector>
#include <iostream>
#include "../include/switch.h"
#include "../include/scheduler.h"
#include "../include/metrics.h"

using namespace std;



void transmit_packets(
    vector<OutputPort>& outputs,
    int current_time)
{
    
    for(int o=0; o<outputs.size(); o++)
    {
        if(!outputs[o].buffer.empty())
        {
            Packet pkt = outputs[o].buffer.front();
            outputs[o].buffer.pop();

            int delay = current_time - pkt.arrival_time;

            total_delay += delay;
            total_delay_sq += delay * delay;

            total_packets++;

            outputs[o].transmitted++;

            link_usage++;

            //to check if working or not flow
            //cout << "Packet transmitted from "<< pkt.src << " to " << pkt.dest << endl;

            /* cout << "Packet transmitted from input "
                 << pkt.src
                 << " to output "
                 << pkt.dest
                 << " at time "
                 << current_time
                 << endl;
            */
                 //  to check packets are flowing or not in various time slots   
        }
    }

}

