README OF ACN SWITCH SIMULATOR
--------------------------------------

============================================================
INPUT QUEUED SWITCH SIMULATOR
============================================================

Assignment: Advanced Computer Networks
Group No: 2

Group Members:
1. Arya Raag - A125002
2. Shivam Verma - A125020 
3. Siddharth Kumar - A125021
4. Srijita Verma - A125023

============================================================
PROJECT DESCRIPTION
============================================================

This project implements a simulator for an N x N input queued
packet switch. The simulator evaluates the performance of
different scheduling algorithms used in packet switching.

The following scheduling algorithms are implemented:

1. INQ (Input Queued Switch)
2. KOUQ (Knock-Out Output Queued Switch)
3. iSLIP (Iterative Round-Robin Scheduling with VOQ)

============================================================
FEATURES
============================================================

- Discrete time slot simulation
- Random packet generation using probability p
- Multiple scheduling algorithms
- Performance metric evaluation
- Output results stored in file

============================================================
SIMULATION PARAMETERS
============================================================

N  : Number of input/output ports
B  : Buffer size (default = 4)
p  : Packet generation probability
T  : Number of time slots
K  : Knock-out parameter (for KOUQ only)

============================================================
PERFORMANCE METRICS
============================================================

1. Average Packet Delay
2. Standard Deviation of Delay
3. Link Utilization
4. Drop Probability (KOUQ only)

============================================================
FILE STRUCTURE
============================================================

src/            → Source code files
include/        → Header files
results.txt     → Output results
report/         → Technical report (PDF + LaTeX)
Makefile        → Build instructions
README.txt      → Project documentation

============================================================
COMPILATION
============================================================

To compile the program, run:

make

OR manually:

g++ src/*.cpp -I include -o routing

============================================================
EXECUTION
============================================================

Example commands:

INQ:
./routing -N 8 -B 4 -p 0.5 -queue INQ -T 10000

KOUQ:
./routing -N 8 -B 4 -p 0.5 -queue KOUQ -K 6 -T 10000

iSLIP:
./routing -N 8 -B 4 -p 0.5 -queue iSLIP -T 10000

============================================================
OUTPUT
============================================================

The simulation results are appended to:

results.txt

Format:

N   p   Queue   AvgDelay   StdDev   Utilization   DropProb

============================================================
EXPERIMENTS PERFORMED
============================================================

Simulations were run for:

N = 4, 8, 16, 32
p = 0.5 (moderate load), 0.9 (heavy load)
K = 0.6N, 0.8N, 1.0N (for KOUQ)

============================================================
OBSERVATIONS
============================================================

- INQ suffers from Head-of-Line blocking
- KOUQ improves delay but may drop packets
- iSLIP achieves highest link utilization
- iSLIP performs best under heavy traffic

============================================================
NOTES
============================================================

- Ensure all files are compiled before execution
- Results file grows with multiple runs
- Remove executable using "make clean" if needed

============================================================
END OF FILE
============================================================