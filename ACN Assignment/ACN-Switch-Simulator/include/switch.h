#ifndef SWITCH_H
#define SWITCH_H

#include <vector>
#include <queue>
#include "packet.h"

struct InputPort
{
    std::queue<Packet> buffer;
};

struct OutputPort
{
    std::queue<Packet> buffer;
    int buffer_size = 4;
    int transmitted = 0;
};

#endif






// #ifndef SWITCH_H
// #define SWITCH_H

// #include <vector>
// #include <queue>
// #include "packet.h"

// struct InputPort
// {
//     std::queue<Packet> inq;
//     std::vector<std::queue<Packet>> voq;
// };

// struct OutputPort
// {
//     std::queue<Packet> buffer;
//     int transmitted = 0;
// };

// #endif