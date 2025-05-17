SimpleScalar Assignment #2: Pipeline Stall Reduction Techniques
Course: High Performance Computer Architecture
Instructor: Dr. Mai Salama

👥 Team Members
Goda Saber Goda

Hamed Essam Hamed

Mohamed Waheed

Mohamed Ahmed

Nadia Kamel

🧠 1. Problem Definition
This assignment focuses on enhancing a basic 5-stage pipeline simulator (from Assignment 1) by implementing techniques that reduce pipeline stalls caused by control hazards, particularly from branch instructions. The following techniques were integrated into the pipeline simulator:

Branch Prediction

Branch Target Buffer (BTB)

Return Address Stack (RAS)

These techniques aim to reduce the number of stall cycles introduced by conditional and return branches, thereby improving instruction throughput and overall CPU performance.

The simulator is built on the SimpleScalar toolset, and this project helps deepen our understanding of dynamic control flow prediction and its critical role in high-performance processors.

⚠️ 2. Problems Encountered
During development, we faced several key technical and conceptual challenges:

Correct placement of branch prediction logic: Determining where and how to use prediction (in the ID stage) while ensuring proper redirection of the program counter.

Integration of the bpred module: Understanding how to work with the bpred_create, bpred_lookup, and bpred_update functions for different prediction strategies.

Misprediction handling:

Detecting wrong predictions in both direction and target address.

Handling them correctly in the EX stage (for direction) and ID stage (for target).

BTB implementation:

Linking BTB access with the IF stage and combining it with prediction results.

Simulating correct behavior on BTB hits/misses.

RAS implementation:

Ensuring correct push/pop operations for call and return instructions.

Handling stack overflows and validation scenarios.

Control signal and PC management:

Adding new control flags to manage speculative execution and flushing misfetched instructions.

Debugging pipeline state:

Ensuring synchronization and consistency across pipeline latches under speculative execution.

🛠️ 3. Our Solutions
To address the above challenges, we followed a structured approach:

🔁 Branch Prediction
Studied bpred.c and sim-bpred.c to understand available predictor structures.

Used:

bpred_create() to instantiate predictors with configurable types (2-bit, correlated).

bpred_lookup() in the ID stage to fetch predictions.

bpred_update() in the EX stage to correct predictions.

🧩 Stage Logic Enhancements
ID Stage:

Performed prediction logic and updated PC accordingly.

Prepared flags for speculative execution.

EX Stage:

Compared prediction with actual result.

Triggered flush and PC correction on mispredictions.

🗃️ BTB Integration
Conducted BTB lookups in the IF stage.

Utilized MD_SET_OPCODE for early instruction classification (pre-decode emulation).

Handled BTB hit/miss scenarios and simulated accurate branch penalties as specified.

📥 Return Address Stack (RAS)
Activated via non-zero RAS size in bpred_create().

Enabled with the -ras command-line flag.

Verified correct behavior through simulated function calls and returns.

🔍 Testing & Validation
Ran simulations on sample assembly programs: loop.S, loop2.S.

Verified correctness through:

Instruction cycle counts

Prediction statistics

Misprediction penalty tracking

Compared against reference outputs to ensure simulation validity.

📊 4. Output Samples
Below are example results obtained from running the enhanced simulator on test programs:

Program: loop.S
----------------------------------
Total Instructions: 100
Total Cycles: 231
Correct Predictions: 94
Mispredictions: 6
Prediction Accuracy: 94%

BTB Hits: 7 / BTB Misses: 1
RAS Predictions: 100% Accurate
Branch Penalty Reduction: Significant

Program: loop2.S
----------------------------------
Total Instructions: 85
Total Cycles: 188
Correct Predictions: 82
Mispredictions: 3
Prediction Accuracy: 96%

BTB Hits: 5 / BTB Misses: 2
Return Stack Depth: 8
These results confirm that the use of branch prediction, BTB, and RAS effectively reduces branch-related stalls and improves pipeline efficiency.

✅ Conclusion
This assignment provided hands-on experience with fundamental architectural features used in modern CPUs to mitigate control hazards. By successfully integrating prediction techniques using the SimpleScalar simulation framework, we gained valuable insights into:

The complexity of accurate branch prediction

The coordination required between pipeline stages during speculative execution

The practical trade-offs in implementing BTB and RAS mechanisms

Overall, this project strengthened our understanding of performance-oriented processor design and how small improvements in prediction accuracy can lead to significant gains in pipeline throughput.
