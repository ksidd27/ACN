#ifndef METRICS_H
#define METRICS_H

extern long long total_delay;
extern long long total_packets;
extern long long total_delay_sq;
extern long long total_slots;
extern long long drop_events;

extern long long link_usage;

void reset_metrics();

double compute_avg_delay();

double compute_std_dev();

double compute_link_utilization(int N, int T);

double compute_drop_probability();

#endif