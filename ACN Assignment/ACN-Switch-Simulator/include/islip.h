#ifndef ISLIP_H
#define ISLIP_H

#include <vector>
#include "packet.h"

struct InputPort;
struct OutputPort;

void schedule_iSLIP(
    std::vector<InputPort>& inputs,
    std::vector<OutputPort>& outputs,
    int N);

#endif