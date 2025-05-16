SimpleScalar Assignment #2
Team Members:

Goda Saber Goda

Hamed Essam Hamed

Mohamed Waheed

Mohamed Ahmed

Nadia Kamel

1. Definition of the Simulation Problem
The goal of this assignment is to extend the basic 5-stage pipeline simulator from Assignment 1 by adding mechanisms to reduce control hazards through branch prediction, branch target buffers (BTB), and return address stacks (RAS). The simulator is built using the SimpleScalar toolset, and the focus is to understand how these features improve performance by reducing branch penalties in the pipeline.

2. Problems Encountered
During development, we faced the following challenges:

Integrating branch prediction in the ID stage and updating the fetch path correctly based on the predicted outcome.

Correctly using the SimpleScalar bpred module, especially handling the different predictor types (2-bit, (2,2) correlated).

Handling mispredictions in both target and direction—identifying whether mispredictions occurred in the ID or EX stage.

Simulating BTB functionality in the IF stage and linking it with the rest of the pipeline.

Implementing and debugging the Return Address Stack (RAS) to accurately predict return instruction targets.

3. How We Solved Them
To address these problems, we took the following steps:

Carefully studied the behavior of the bpred.c module and how it is used in sim-bpred.c.

Used bpred_create, bpred_lookup, and bpred_update appropriately at each stage:

ID Stage: Performed branch prediction and updated the fetch PC.

EX Stage: Resolved actual branch outcomes and corrected any mispredictions.

Created new pipeline control flags to keep track of prediction states and speculative execution.

For BTB integration:

Performed lookups in the IF stage using predecode bits with MD_SET_OPCODE.

Tracked BTB hit/miss results and used them to simulate penalty cycles.

Enabled RAS by providing a non-zero stack size in bpred_create and using the -ras option in the simulator.

Used sample assembly programs (loop.S, loop2.S) to verify correctness and cycle counts.

Ensured compatibility with SimpleScalar output formats and compared results with reference outputs.
