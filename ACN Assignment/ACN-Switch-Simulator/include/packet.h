#ifndef PACKET_H
#define PACKET_H

struct Packet
{
    int src;
    int dest;
    int arrival_time;
    int departure_time;
};

#endif