<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
</head>
<body>

  <h1 align="center">🚀 Simulation of Control Hazard Mitigation in Pipelined Processors</h1>
  <p align="center"><em>A simulation project that models and analyzes branch prediction mechanisms in modern processors using SimpleScalar.</em></p>

  <hr>

  <h2>📚 Table of Contents</h2>
  <ul>
    <li><a href="#acknowledgments">💡 Acknowledgments</a></li>
    <li><a href="#problem-description">🔍 Problem Description</a></li>
    <li><a href="#prerequisites">🧰 Prerequisites</a></li>
    <li><a href="#environment-setup">🖥️ Environment Setup</a></li>
    <li><a href="#simulation-code-implementation">✏️ Simulation Code Implementation</a></li>
    <li><a href="#compile-and-run">🏁 Compile and Run</a></li>
    <li><a href="#testing-and-validation">🧪 Testing and Validation</a></li>
    <li><a href="#challenges-encountered">🧩 Challenges Encountered</a></li>
    <li><a href="#handling-challenges">🛠️ Handling Challenges</a></li>
    <li><a href="#conclusion">📝 Conclusion</a></li>
    <li><a href="#references">📌 References</a></li>
    <li><a href="#contributors">👥 Contributors</a></li>
  </ul>

  <hr>

  <h2 id="acknowledgments">💡 Acknowledgments</h2>
  <p>This project was developed under the supervision of <strong>Dr. Mai Salama</strong> as part of the High Performance Computer Architecture course.</p>

  <hr>

  <h2 id="problem-description">🔍 Problem Description</h2>
  <p>
    In pipelined processors, control hazards caused by conditional branches can significantly impact performance due to pipeline stalls or incorrect instruction fetches.
    This project simulates advanced control hazard mitigation techniques using the SimpleScalar toolset by integrating:
  </p>
  <ul>
    <li>2-bit saturating branch predictor</li>
    <li>(2,2) correlating predictor</li>
    <li>Branch Target Buffer (BTB)</li>
    <li>Return Address Stack (RAS)</li>
  </ul>

  <hr>

  <h2 id="prerequisites">🧰 Prerequisites</h2>
  <ul>
    <li>Basic understanding of pipelining and control hazards</li>
    <li>Familiarity with C programming</li>
    <li>Linux environment or WSL (Windows Subsystem for Linux)</li>
    <li>SimpleScalar toolset installed</li>
  </ul>

  <hr>

  <h2 id="environment-setup">🖥️ Environment Setup</h2>
  <ol>
    <li>Download and install the SimpleScalar toolset from <a href="http://www.simplescalar.com/">SimpleScalar</a></li>
    <li>Clone this repository and navigate to the source folder</li>
    <li>Ensure environment variables are set correctly for SimpleScalar</li>
  </ol>

  <hr>

  <h2 id="simulation-code-implementation">✏️ Simulation Code Implementation</h2>
  <ul>
    <li>Implemented <code>bpred_lookup()</code> in the Instruction Decode (ID) stage</li>
    <li>Updated predictions with <code>bpred_update()</code> in the Execute (EX) stage</li>
    <li>Integrated BTB in the Instruction Fetch (IF) stage using opcode detection</li>
    <li>Added a stack-based RAS with push/pop logic for nested function returns</li>
  </ul>

  <hr>

  <h2 id="compile-and-run">🏁 Compile and Run</h2>
  <ol>
    <li>Compile the simulator using <code>make</code></li>
    <li>Run test programs:
      <ul>
        <li><code>./sim-outorder -bpred [type] test/loop.S</code></li>
        <li>Enable RAS: <code>-ras</code> flag</li>
      </ul>
    </li>
  </ol>

  <hr>

  <h2 id="testing-and-validation">🧪 Testing and Validation</h2>
  <ul>
    <li>Tested with <code>loop.S</code>, <code>loop2.S</code>, <code>test-printf</code>, and <code>anagram</code></li>
    <li>Measured:
      <ul>
        <li>Prediction accuracy</li>
        <li>BTB hit/miss rates</li>
        <li>RAS correctness</li>
        <li>Total cycles vs instructions</li>
      </ul>
    </li>
  </ul>

  <hr>

  <h2 id="challenges-encountered">🧩 Challenges Encountered</h2>
  <ul>
    <li>Correct placement of branch prediction and update logic</li>
    <li>Differentiating between direction and target mispredictions</li>
    <li>Handling instruction flushing after mispredictions</li>
    <li>Simulating realistic BTB delays</li>
    <li>Ensuring accurate RAS push/pop during nested function calls</li>
  </ul>

  <hr>

  <h2 id="handling-challenges">🛠️ Handling Challenges</h2>
  <ul>
    <li>Used extensive debugging and logs to isolate errors</li>
    <li>Validated logic with test cases and benchmarks</li>
    <li>Adjusted control signals to maintain correct speculative paths</li>
  </ul>

  <hr>

  <h2 id="conclusion">📝 Conclusion</h2>
  <p>
    This simulation demonstrated practical implementation of branch prediction in a pipelined processor. Key takeaways:
  </p>
  <ul>
    <li>Accurate prediction greatly reduces pipeline stalls</li>
    <li>BTB improves fetch stage performance for taken branches</li>
    <li>RAS ensures high accuracy in function returns, especially for recursion</li>
    <li>Simulation tools like SimpleScalar bridge theory and real-world processor architecture</li>
  </ul>

  <hr>

  <h2 id="references">📌 References</h2>
  <ul>
    <li>SimpleScalar Toolset Documentation</li>
    <li>Computer Architecture: A Quantitative Approach - Hennessy & Patterson</li>
    <li>Course notes from Dr. Mai Salama</li>
  </ul>

  <hr>

  <h2 id="contributors">👥 Contributors</h2>
  <ul>
    <li>Goda Saber Goda</li>
    <li>Hamed Essam Hamed</li>
    <li>Mohamed Waheed</li>
    <li>Mohamed Ahmed</li>
    <li>Nadia Kamel</li>
  </ul>

  <hr>
  <p align="center"><em>Prepared for the High Performance Computer Architecture course, supervised by Dr. Mai Salama</em></p>

</body>
</html>
