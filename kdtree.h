#ifndef KDTREE_H
#define KDTREE_H

typedef struct KDNode {
    double telemetry[2]; // Coordinates: [Temperature, Vibration]
    int node_id;
    struct KDNode* left;
    struct KDNode* right;
} KDNode;

KDNode* insert_sensor_node(KDNode* root, double* telemetry, int id, int depth);
int evaluate_anomaly_threshold(KDNode* root, double* query, double threshold, int depth);
void clear_spatial_tree(KDNode* root);

#endif
