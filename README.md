<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <title>🚀 Simulation of Pipeline Stalls Reduction Techniques</title>
</head>
<body>

<h1 align="center">🚀 Simulation of Pipeline Stalls Reduction Techniques</h1>
<p align="center"><strong>Instructor:</strong> Dr. Mai Salama</p>

<hr>

<h2>📚 Table of Contents</h2>
<ul>
  <li><a href="#acknowledgments">💡 Acknowledgments</a></li>
  <li><a href="#problem-description">🔍 Problem Description</a></li>
  <li><a href="#prerequisites">🧰 Prerequisites</a></li>
  <li><a href="#environment-setup">🖥️ Environment Setup</a></li>
  <li><a href="#installation-guide">📥 Installation Guide</a></li>
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
<p>We would like to thank Dr. Mai Salama for her guidance and support throughout this project on High Performance Computer Architecture.</p>

<hr>

<h2 id="problem-description">🔍 Problem Description</h2>
<p>
In modern processor architectures, pipeline stalls caused by control hazards (especially due to conditional branches) significantly impact instruction throughput and overall performance.
This project aims to reduce pipeline stalls by integrating advanced control hazard mitigation techniques into a 5-stage pipeline simulator using the SimpleScalar toolset.
</p>

<hr>

<h2 id="prerequisites">🧰 Prerequisites</h2>
<ul>
  <li>Basic understanding of computer architecture and pipeline design</li>
  <li>Familiarity with C/C++ and terminal usage</li>
  <li>Linux environment (Ubuntu recommended)</li>
</ul>

<hr>

<h2 id="environment-setup">🖥️ Environment Setup</h2>
<ol>
  <li>Download and install the <strong>SimpleScalar Toolset</strong></li>
  <li>Clone the base simulator from your course repository or use the one provided in Assignment 1</li>
  <li>Install required tools:
    <ul>
      <li><code>sudo apt install build-essential</code></li>
      <li><code>sudo apt install gdb</code></li>
    </ul>
  </li>
  <li>Configure paths and compile base simulator</li>
</ol>

<hr>

<h2 id="installation-guide">📥 Installation Guide</h2>
<h3>Step 1: Prerequisites</h3>
<pre><code>sudo apt update && sudo apt upgrade
sudo apt install build-essential gdb flex bison
sudo apt install gcc-multilib g++-multilib binutils-multiarch lib32z1 libc6-i386 lib32gcc-s1
</code></pre>

<h3>Step 2: Environment Variables</h3>
<pre><code>export IDIR="$HOME/simplescalar"
export HOST="i686-pc-linux"
export TARGET="sslittle-na-sstrix"
export PATH="$IDIR/bin:$IDIR/sslittle-na-sstrix/bin:$PATH"
</code></pre>

<h3>Step 3: Download & Extract Tarballs</h3>
<pre><code>mkdir -p $IDIR
mv ~/simpletools-2v0.tgz ~/simpleutils-990811.tar.gz ~/gcc-2.7.2.3.ss.tar.gz ~/simplesim-3v0d-with-cheetah.tar.gz $IDIR
cd $IDIR
</code></pre>

<h3>Step 4: Build Components</h3>
<ul>
  <li><strong>SimpleTools:</strong>
    <pre><code>tar xvfz simpletools-2v0.tgz
rm -rf gcc-2.6.3
</code></pre>
  </li>
  <li><strong>SimpleUtils:</strong>
    <pre><code>tar xvfz simpleutils-990811.tar.gz
cd simpleutils-990811
sed -i 's/yy_current_buffer/YY_CURRENT_BUFFER/g' ld/ldlex.l
./configure --host=$HOST --target=$TARGET --with-gnu-as --with-gnu-ld --prefix=$IDIR
make CFLAGS="-O"
make install
cd ..
</code></pre>
  </li>
  <li><strong>SimpleSim (Simulator):</strong>
    <pre><code>tar xvfz simplesim-3v0d-with-cheetah.tar.gz
cd simplesim-3.0
make config-pisa
make
cd ..
</code></pre>
  </li>
</ul>

<h3>Step 5: GCC Cross-Compiler</h3>
<pre><code>tar xvfz gcc-2.7.2.3.ss.tar.gz
cd gcc-2.7.2.3
./configure --host=$HOST --target=$TARGET --with-gnu-as --with-gnu-ld --prefix=$IDIR
chmod -R +w .
</code></pre>

<p><strong>Makefile & Code Fixes:</strong></p>
<ul>
  <li>Add <code>-I/usr/include</code> in Makefile</li>
  <li>Replace <code>&lt;varargs.h&gt;</code> with <code>&lt;stdarg.h&gt;</code> in protoize.c</li>
  <li>Fix pointer increment bug in obstack.h</li>
</ul>

<h3>Build, Enquire, and Install</h3>
<pre><code>export ORIGINAL_PATH="$PATH"
export PATH="/usr/bin:$PATH"

make LANGUAGES=c CFLAGS="-O" CC="gcc -m32"
make enquire
$IDIR/simplesim-3.0/sim-safe enquire -f > float.h-cross
make LANGUAGES=c CFLAGS="-O" CC="gcc -m32" install

export PATH="$ORIGINAL_PATH"
</code></pre>

<h3>Step 6: Test Compilation</h3>
<pre><code>mkdir -p $IDIR/tests
cd $IDIR/tests

cat <<EOF > hello.c
#include &lt;stdio.h&gt;
int main() {
    printf("Hello World!\\n");
    return 0;
}
EOF

$IDIR/bin/sslittle-na-sstrix-gcc -o hello hello.c
file hello
$IDIR/simplesim-3.0/sim-safe hello
</code></pre>

<hr>

<h2 id="simulation-code-implementation">✏️ Simulation Code Implementation</h2>
<ul>
  <li><strong>Dynamic Branch Prediction:</strong>
    <ul>
      <li>Implemented 2-bit saturating counter predictor</li>
      <li>Implemented (2,2) correlating predictor</li>
    </ul>
  </li>
  <li><strong>Branch Target Buffer (BTB):</strong> Added to fetch stage to predict target addresses</li>
  <li><strong>Return Address Stack (RAS):</strong> Implemented for accurate return prediction in nested function calls</li>
  <li>Used SimpleScalar APIs:
    <ul>
      <li><code>bpred_create()</code></li>
      <li><code>bpred_lookup()</code></li>
      <li><code>bpred_update()</code></li>
    </ul>
  </li>
</ul>

<hr>

<h2 id="compile-and-run">🏁 Compile and Run</h2>
<ol>
  <li>Navigate to the simulator directory</li>
  <li>Compile using <code>make</code></li>
  <li>Run the simulator:
    <pre><code>./sim-pipe -bpred &lt;predictor-type&gt; -ras -redir:sim sim.out test-printf</code></pre>
  </li>
</ol>

<hr>

<h2 id="testing-and-validation">🧪 Testing and Validation</h2>
<table border="1" cellspacing="0" cellpadding="5">
  <thead>
    <tr>
      <th>Test Program</th>
      <th>Total Instructions</th>
      <th>Total Cycles</th>
      <th>Correct Predictions</th>
      <th>Mispredictions</th>
      <th>Prediction Accuracy</th>
      <th>BTB Hits / Misses</th>
      <th>RAS Accuracy</th>
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

<hr>

<h2 id="challenges-encountered">🧩 Challenges Encountered</h2>
<ul>
  <li>Correct placement of prediction and update logic in pipeline stages</li>
  <li>Accurately flushing pipeline and redirecting PC on misprediction</li>
  <li>Debugging BTB and RAS logic for nested function calls</li>
</ul>

<hr>

<h2 id="handling-challenges">🛠️ Handling Challenges</h2>
<ul>
  <li>Used logging and GDB for debugging</li>
  <li>Validated each component separately before integration</li>
  <li>Created custom test programs to verify misprediction handling</li>
</ul>

<hr>

<h2 id="conclusion">📝 Conclusion</h2>
<p>
This simulation enhanced our understanding of control hazards and branch prediction in pipelines. Our implementation significantly reduced stall cycles and improved overall throughput by leveraging dynamic prediction, BTB, and RAS techniques. This project helped bridge the gap between theoretical computer architecture and practical simulation-based performance evaluation.
</p>

<hr>

<h2 id="references">📌 References</h2>
<ul>
  <li>SimpleScalar documentation</li>
  <li>Hennessy & Patterson – Computer Architecture: A Quantitative Approach</li>
  <li>Course materials from High Performance Computer Architecture</li>
</ul>

<hr>

<h2 id="contributors">👥 Contributors</h2>
<ul>
  <li><a href="https://github.com/GodaSaber" target="_blank">@GodaSaber</a></li>
  <li><a href="https://github.com/hamedessamhamed" target="_blank">@HamedEssam</a></li>
  <li><a href="https://github.com/MohammedWaheedAbdallah" target="_blank">@MohamedWaheed</a></li>
  <li><a href="https://github.com/mohamedahmed" target="_blank">@MohamedAhmed</a></li>
  <li><a href="https://github.com/nadiakamelmohamed" target="_blank">@NadiaKamel</a></li>
</ul>

<p align="center"><em>Prepared by the team for the High Performance Computer Architecture course</em></p>

</body>
</html>
