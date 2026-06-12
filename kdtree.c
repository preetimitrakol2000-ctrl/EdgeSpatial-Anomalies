#include <stdlib.h>
#include <math.h>
#include "kdtree.h"

KDNode* insert_sensor_node(KDNode* root, double* telemetry, int id, int depth) {
    if (root == NULL) {
        KDNode* node = (KDNode*)malloc(sizeof(KDNode));
        node->telemetry[0] = telemetry[0];
        node->telemetry[1] = telemetry[1];
        node->node_id = id;
        node->left = node->right = NULL;
        return node;
    }
    int axis = depth % 2; // Cycle matching axes split thresholds: Temp (0) -> Vibration (1)
    if (telemetry[axis] < root->telemetry[axis]) {
        root->left = insert_sensor_node(root->left, telemetry, id, depth + 1);
    } else {
        root->right = insert_sensor_node(root->right, telemetry, id, depth + 1);
    }
    return root;
}

int evaluate_anomaly_threshold(KDNode* root, double* query, double threshold, int depth) {
    if (root == NULL) return 0;

    // Euclidean distance assessment formulation across multidimensional readings
    double dx = query[0] - root->telemetry[0];
    double dy = query[1] - root->telemetry[1];
    double distance = sqrt((dx * dx) + (dy * dy));

    // If an historical baseline matches closely, it is deemed a known structural state (Not Anomaly)
    if (distance < threshold) return 1; 

    int axis = depth % 2;
    if (query[axis] < root->telemetry[axis]) {
        return evaluate_anomaly_threshold(root->left, query, threshold, depth + 1);
    } else {
        return evaluate_anomaly_threshold(root->right, query, threshold, depth + 1);
    }
}

void clear_spatial_tree(KDNode* root) {
    if (root == NULL) return;
    clear_spatial_tree(root->left);
    clear_spatial_tree(root->right);
    free(root);
}
