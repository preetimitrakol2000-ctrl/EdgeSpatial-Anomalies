#include <stdio.h>
#include "kdtree.h"

int main() {
    printf("📡 Activating EdgeSpatial-Anomalies Space Partitioning Engine...\n\n");

    // Environmental Baselines [Temperature in °C, Vibration in Hz]
    double historical_baselines[3][2] = {
        {24.5, 50.0}, {26.2, 52.1}, {23.8, 48.9}
    };

    KDNode* calibration_tree = NULL;
    for (int i = 0; i < 3; i++) {
        calibration_tree = insert_sensor_node(calibration_tree, historical_baselines[i], i, 0);
    }

    // High anomaly reading simulation (e.g., HVAC failure vector)
    double live_stream_packet[2] = {42.1, 88.5};
    double anomaly_radius = 5.0;

    int is_normal = evaluate_anomaly_threshold(calibration_tree, live_stream_packet, anomaly_radius, 0);

    printf("📥 Incoming Telemetry Stream: Temp=%.1f°C, Vib=%.1fHz\n", live_stream_packet[0], live_stream_packet[1]);
    printf("🔮 Spatial Boundary Evaluation Verdict: %s\n", (is_normal == 0) ? "🚨 CRITICAL OUTLIER STATE DETECTED" : "✅ NOMINAL STRUCTURAL TARGET");

    clear_spatial_tree(calibration_tree);
    return 0;
}
