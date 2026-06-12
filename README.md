# EdgeSpatial-Anomalies

An implementation of a multi-axis spatial index using a **K-Dimensional Tree (K-D Tree)** built in pure C99 for IoT edge gateways. This architecture allows resource-constrained microcontrollers to map multi-sensor telemetry fields and identify abnormal readings via distance thresholds in multi-dimensional space.

## 📊 Algorithmic Architecture
* **Data Structure:** Balanced 2-Dimensional Spatial Search Tree.
* **Search Complexity:** $O(\log N)$ average-case lookup, bypassing exhaustive $O(N)$ brute-force distance checking across telemetry buffers.
* **Memory Management:** Continuous allocation structures tracking streaming data horizons.

## 📦 Compilation & Execution
```bash
gcc main.c kdtree.c -o edge_spatial -lm
./edge_spatial
