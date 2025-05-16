SimpleScalar Assignment #2: Pipeline Stall Reduction Techniques
Team Members:

Goda Saber Goda

Hamed Essam Hamed

Mohamed Waheed

Mohamed Ahmed

Nadia Kamel

1. Definition of the Simulation Problem
The objective of this assignment is to enhance the basic 5-stage pipeline simulator (from Assignment 1) by incorporating techniques to reduce control hazards. These techniques include:

Branch Prediction

Branch Target Buffer (BTB)

Return Address Stack (RAS)

The simulator is developed using the SimpleScalar toolset. The goal is to explore how these mechanisms help minimize pipeline stalls caused by branch instructions, thereby improving overall processor performance.

2. Problems Encountered
During the development process, we encountered several challenges:

Integrating Branch Prediction in the Instruction Decode (ID) stage and updating the fetch path based on predicted outcomes.

Correct usage of the SimpleScalar bpred module, including different predictor types like:

2-bit predictor

(2,2) correlated predictor

Handling mispredictions in both:

Branch direction

Target address

Identifying the correct stage (ID or EX) where mispredictions occurred.

Simulating BTB functionality in the Instruction Fetch (IF) stage and linking it with the rest of the pipeline.

Implementing and debugging the Return Address Stack (RAS) to correctly predict return instruction targets.

3. How We Solved Them
To resolve the above issues, we followed these steps:

✅ Branch Prediction Implementation
Studied the bpred.c and sim-bpred.c source files in detail.

Used the following functions at the appropriate stages:

bpred_create() – to initialize the predictor

bpred_lookup() – to perform prediction in the ID stage

bpred_update() – to update predictor status in the EX stage

🔁 Stage-specific Logic
ID Stage:

Performed branch prediction and updated the fetch program counter (PC) accordingly.

EX Stage:

Resolved actual branch outcomes.

Detected and corrected mispredictions.

⚙️ Pipeline Control
Added new control flags to manage:

Prediction states

Speculative execution

Flushes on misprediction

📦 BTB Integration
Performed BTB lookups in the IF stage using:

Instruction pre-decode via MD_SET_OPCODE

Tracked BTB hits/misses and applied penalty cycles as needed.

🌀 Return Address Stack (RAS)
Enabled RAS by:

Setting a non-zero stack size in bpred_create()

Using the -ras flag in the command-line interface

Verified correct behavior on return instructions.

🔍 Testing & Validation
Tested using assembly programs like:

loop.S

loop2.S

Verified:

Cycle counts

Prediction accuracy

Misprediction penalties

Ensured compatibility with SimpleScalar output and validated against expected results.

