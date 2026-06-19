#include "../include/metrics.h"
#include <cmath>

long long total_delay = 0;
long long total_delay_sq = 0;
long long total_packets = 0;

long long total_slots = 0;
long long drop_events = 0;

long long link_usage = 0;

void reset_metrics()
{
    total_delay = 0;
    total_delay_sq = 0 ;
    total_packets = 0;
    total_slots = 0;
    drop_events = 0;
    link_usage = 0;
}

double compute_avg_delay()
{
    if(total_packets == 0) return 0;
    return (double) total_delay / total_packets;
}

double compute_link_utilization(int N, int T)
{
    return (double) link_usage / (N * T);
}

double compute_std_dev()
{
    if(total_packets == 0) return 0;

    double avg = compute_avg_delay();

    double variance =
        (double)total_delay_sq / total_packets
        - (avg * avg);

    return sqrt(variance);
}

double compute_drop_probability()
{
    
    if(total_slots == 0) return 0;
    return (double)drop_events / total_slots;

}