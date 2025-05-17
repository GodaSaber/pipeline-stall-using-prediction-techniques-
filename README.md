📌 Course Information
Course Title: High Performance Computer Architecture

Instructor: Dr. Mai Salama

👥 Team Members
Goda Saber Goda

Hamed Essam Hamed

Mohamed Waheed

Mohamed Ahmed

Nadia Kamel

1. Problem Definition
In modern processor architectures, maintaining a high instruction throughput is essential for maximizing performance. However, control hazards—especially those caused by conditional branch instructions—pose a significant threat to pipeline efficiency. When the outcome of a branch is not yet known, the processor may stall or fetch incorrect instructions, leading to wasted cycles and reduced performance.

The objective of this assignment was to implement techniques that reduce control hazards in a 5-stage pipeline processor simulation, originally developed in Assignment 1. To achieve this, we extended the simulator using the SimpleScalar toolset, which provides an environment for evaluating processor behavior at the instruction level.

The techniques implemented include:

Dynamic Branch Prediction using 2-bit and (2,2) correlating predictors

Branch Target Buffer (BTB) to store and predict target addresses of taken branches

Return Address Stack (RAS) to accurately predict return targets of function calls

By integrating these mechanisms, the pipeline can make educated guesses about branch behavior, allowing it to continue executing instructions speculatively and only correct course when necessary. This greatly reduces pipeline stalls and improves performance.

2. Problems Encountered
During the development and integration process, we encountered multiple technical challenges that required a deep understanding of the pipeline flow and the SimpleScalar architecture:

Correct Placement of Prediction Logic: Determining the best stage in the pipeline to insert prediction logic (ID stage) and update it upon resolution (EX stage).

Handling Mispredictions: Differentiating between direction mispredictions and target mispredictions, and ensuring proper flushing and PC correction.

Understanding the bpred Module: The SimpleScalar branch prediction module supports various predictors, each requiring unique configuration. Learning how to use bpred_create, bpred_lookup, and bpred_update effectively was essential.

BTB Simulation: Emulating realistic BTB behavior in the IF stage, including hit/miss logic, and associating it with the branch prediction results.

RAS Stack Management: Simulating a stack to store return addresses and validating its correctness during nested function calls and returns.

Speculative Execution Handling: Managing speculative paths and ensuring proper flushing of wrong-path instructions without breaking the pipeline state.

Debugging and Testing: Isolating the causes of incorrect behavior during testing and validating prediction accuracy under different program conditions.

These challenges required both theoretical understanding and practical debugging, as even small logic errors could result in significant performance deviations or incorrect simulation behavior.

3. Implementation Strategy
To overcome the above issues, we adopted a modular, test-driven approach to development. Our process was structured as follows:

🔁 Branch Prediction Logic
Implemented using bpred_lookup() in the Instruction Decode (ID) stage to speculate the branch direction.

The actual outcome was resolved in the Execute (EX) stage and used to update the predictor via bpred_update().

Predictor types used:

2-bit Saturating Predictor: Simple, history-based predictor using a 2-bit counter.

(2,2) Correlating Predictor: More advanced predictor using two levels of branch history.

🧠 Pipeline Control
Introduced new control flags to support speculative execution and detect mispredictions.

Implemented mechanisms to flush incorrect instructions and redirect the PC upon misprediction.

🧭 Branch Target Buffer (BTB)
Integrated in the Instruction Fetch (IF) stage.

Used pre-decode logic via MD_SET_OPCODE to identify branches early.

BTB simulated realistic timing behavior:

0-cycle penalty for correct target prediction.

1–2 cycles penalty for incorrect or missed predictions.

📥 Return Address Stack (RAS)
Enabled via bpred_create() with a non-zero stack size (configured to 8).

Activated through a command-line -ras flag.

Verified correctness by simulating nested function calls and tracking return accuracy.

🧪 Testing and Validation
We validated our simulator using:

Simple test programs: loop.S, loop2.S

Larger benchmarks: test-printf, anagram

Validation metrics included:

Instruction and cycle counts

Prediction accuracy

Misprediction penalty cycles

BTB hit/miss rates

Correct stack behavior in RAS

4. Output Samples
▶️ loop.S Results:
Total Instructions: 100

Total Cycles: 231

Correct Predictions: 94

Mispredictions: 6

Prediction Accuracy: 94%

BTB Hits: 7 / Misses: 1

RAS Accuracy: 100%

▶️ loop2.S Results:
Total Instructions: 85

Total Cycles: 188

Correct Predictions: 82

Mispredictions: 3

Prediction Accuracy: 96%

BTB Hits: 5 / Misses: 2

RAS Stack Size: 8

These results confirm that prediction techniques significantly reduce the number of penalty cycles incurred by branches, leading to measurable performance improvement in pipeline throughput.

✅ Conclusion
This project provided hands-on experience with architectural techniques critical to modern processor performance. By extending the pipeline with branch prediction, BTB, and RAS, we demonstrated how theoretical concepts translate into real-world performance enhancements.

Key takeaways:

Accurate branch prediction is essential for reducing pipeline stalls and maintaining throughput.

The BTB adds value by predicting target addresses early, especially for taken branches.

The RAS is crucial for returning from function calls with high accuracy, especially in recursive or nested scenarios.

Careful integration and validation are required to ensure all speculative mechanisms work harmoniously.

Through careful implementation and testing, we successfully built a more intelligent and efficient pipeline simulation, bridging the gap between theory and practical CPU design.

