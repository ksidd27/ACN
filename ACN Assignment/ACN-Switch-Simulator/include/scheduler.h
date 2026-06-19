#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "switch.h"

void schedule_INQ(
    std::vector<InputPort>& inputs,
    std::vector<OutputPort>& outputs,
    int N);

void schedule_KOUQ(
    std::vector<InputPort>& inputs,
    std::vector<OutputPort>& outputs,
    int N,
    int K);

void schedule_iSLIP(
    std::vector<InputPort>& inputs,
    std::vector<OutputPort>& outputs,
    int N);

#endif