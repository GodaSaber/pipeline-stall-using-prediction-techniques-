<h1 align="center">High Performance Computer Architecture</h1>
<p align="center"><strong>Instructor:</strong> Dr. Mai Salama</p>

<h2>Team Members</h2>
<ul>
  <li>Goda Saber Goda</li>
  <li>Hamed Essam Hamed</li>
  <li>Mohamed Waheed</li>
  <li>Mohamed Ahmed</li>
  <li>Nadia Kamel</li>
</ul>

<hr>

<h2>1. Problem Definition</h2>
<p>
In modern processor architectures, achieving high instruction throughput is paramount for maximizing overall system performance. However, control hazards—particularly those arising from conditional branch instructions—pose significant challenges to pipeline efficiency. When the outcome of a branch instruction is unresolved, the processor must either stall or speculatively fetch instructions that might ultimately be incorrect. These scenarios cause pipeline bubbles or flushes, leading to wasted clock cycles and degraded performance.
</p>
<p>
The primary objective of this assignment was to implement advanced control hazard mitigation techniques within a 5-stage pipeline processor simulator originally developed in Assignment 1. To facilitate detailed evaluation and extension, we utilized the SimpleScalar toolset, which provides a robust framework for simulating and analyzing processor behavior at the instruction level.
</p>

<hr>

<h2>2. Implemented Techniques</h2>
<ul>
  <li><strong>Dynamic Branch Prediction:</strong> Implemented two branch predictors:
    <ul>
      <li>2-bit saturating counter predictor — simple history-based.</li>
      <li>(2,2) correlating predictor — uses two levels of branch history for improved accuracy.</li>
    </ul>
  </li>
  <li><strong>Branch Target Buffer (BTB):</strong> Caches and quickly predicts target addresses of taken branches, enabling early instruction fetching.</li>
  <li><strong>Return Address Stack (RAS):</strong> Accurately predicts return addresses from function calls, critical for nested or recursive call handling.</li>
</ul>
<p>
By integrating these mechanisms, the pipeline speculates branch behavior and continues execution speculatively, only correcting course when necessary. This reduces pipeline stalls and improves instruction throughput.
</p>

<hr>

<h2>3. Challenges and Technical Issues</h2>
<ul>
  <li><strong>Optimal Placement of Prediction Logic:</strong> Prediction at Instruction Decode (ID) stage and update at Execute (EX) stage required careful timing considerations.</li>
  <li><strong>Misprediction Handling:</strong> Differentiated direction and target mispredictions with proper pipeline flushing and PC corrections.</li>
  <li><strong>SimpleScalar bpred Module Usage:</strong> Mastered <code>bpred_create()</code>, <code>bpred_lookup()</code>, and <code>bpred_update()</code> functions to manage prediction states.</li>
  <li><strong>BTB Simulation:</strong> Realistic hit/miss behavior modeled with cycle penalties in Instruction Fetch (IF) stage.</li>
  <li><strong>RAS Stack Management:</strong> Correct push/pop semantics for nested function calls to ensure accurate return prediction.</li>
  <li><strong>Speculative Execution Control:</strong> Managing speculative instruction paths and pipeline state integrity.</li>
  <li><strong>Debugging and Validation:</strong> Extensive testing to isolate logic errors and confirm prediction accuracy.</li>
</ul>

<hr>

<h2>4. Implementation Approach</h2>
<ul>
  <li><strong>Branch Prediction Logic:</strong>  
    <ul>
      <li>Branch prediction requests via <code>bpred_lookup()</code> at ID stage.</li>
      <li>Outcome resolution and predictor update via <code>bpred_update()</code> at EX stage.</li>
      <li>Configurable predictor types: 2-bit saturating and (2,2) correlating predictors.</li>
    </ul>
  </li>
  <li><strong>Pipeline Control Enhancements:</strong>  
    <ul>
      <li>Introduced control flags for speculative execution and misprediction detection.</li>
      <li>Implemented instruction flushing and PC redirection on misprediction.</li>
    </ul>
  </li>
  <li><strong>Branch Target Buffer (BTB):</strong>  
    <ul>
      <li>Integrated at IF stage using pre-decode signals (<code>MD_SET_OPCODE</code>).</li>
      <li>Modeled 0-cycle penalty for hits, 1-2 cycle penalty for misses.</li>
    </ul>
  </li>
  <li><strong>Return Address Stack (RAS):</strong>  
    <ul>
      <li>Configured stack size = 8.</li>
      <li>Enabled by <code>-ras</code> command line flag.</li>
      <li>Validated with nested call test scenarios.</li>
    </ul>
  </li>
  <li><strong>Testing & Validation:</strong>  
    <ul>
      <li>Used simple programs (<code>loop.S</code>, <code>loop2.S</code>) and benchmarks (<code>test-printf</code>, <code>anagram</code>).</li>
      <li>Measured instructions, cycles, prediction accuracy, penalty cycles, BTB hit/miss rates, and RAS behavior.</li>
    </ul>
  </li>
</ul>

<hr>

<h2>5. Results and Performance Analysis</h2>

<table>
  <thead>
    <tr>
      <th>Test Program</th>
      <th>Total Instructions</th>
      <th>Total Cycles</th>
      <th>Correct Predictions</th>
      <th>Mispredictions</th>
      <th>Prediction Accuracy</th>
      <th>BTB Hits / Misses</th>
      <th>RAS Accuracy / Stack Size</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>loop.S</td>
      <td>100</td>
      <td>231</td>
      <td>94</td>
      <td>6</td>
      <td>94%</td>
      <td>7 / 1</td>
      <td>100%</td>
    </tr>
    <tr>
      <td>loop2.S</td>
      <td>85</td>
      <td>188</td>
      <td>82</td>
      <td>3</td>
      <td>96%</td>
      <td>5 / 2</td>
      <td>Stack size: 8</td>
    </tr>
  </tbody>
</table>

<p>
The results confirm that the implemented prediction techniques significantly reduce branch penalty cycles, leading to improved pipeline throughput and processor efficiency.
</p>

<hr>

<h2>6. Conclusion</h2>
<p>
This project offered hands-on experience with critical architectural techniques essential to modern high-performance processors. By enhancing a 5-stage pipeline simulator with dynamic branch prediction, BTB, and RAS mechanisms, we effectively translated theoretical CPU design concepts into practical performance gains.
</p>
<p><strong>Key insights include:</strong></p>
<ul>
  <li>Accurate branch prediction is vital to minimize pipeline stalls and sustain instruction throughput.</li>
  <li>The Branch Target Buffer enables early target address prediction, reducing fetch delays for taken branches.</li>
  <li>The Return Address Stack ensures high accuracy in function return predictions, especially under nested or recursive calls.</li>
  <li>Careful design, integration, and validation of speculative execution components are necessary for correctness and performance.</li>
</ul>
<p>
Our work highlights how architectural innovations can substantially enhance processor performance by mitigating control hazards and exemplifies bridging theory with practical CPU simulation.
</p>

---

<p align="center"><em>Prepared by the team for the High Performance Computer Architecture course, Dr. Mai Salama</em></p>
