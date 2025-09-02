// integration_demo.cpp2
// Integration demonstration for cppfront self-hosting components

import std;
import quantum_protocol_registry;
import realtime_telemetry;
import adaptive_optimizer;

void main_demo() {
    std::cout << "Cppfront Self-Hosting Integration Demonstration\n" << std::endl;

    // Initialize system components
    quantum_protocol_registry registry = {};
    performance_telemetry telemetry = {};
    adaptive_optimizer optimizer = {};

    telemetry.start_monitoring();
    optimizer.telemetry = telemetry;
    optimizer.initialize();

    // Register protocol candidates with confidence scores
    registry.register_candidate("rest", 0.6);
    registry.register_candidate("quic", 0.8);
    registry.register_candidate("ipfs", 0.5);

    registry.diagnostic_dump();

    // Collect performance metrics
    telemetry.collect_metric(performance_metric{"build-1", 1200.0, 450.0, 0.01});
    telemetry.collect_metric(performance_metric{"build-2", 300.0, 120.0, 0.0});

    telemetry.diagnostic_summary();

    // Select optimal protocol candidate
    auto opt = registry.select_optimal();
    if (opt.has_value()) {
        std::cout << "Selected protocol: " << opt.value() << std::endl;
    } else {
        std::cout << "No protocol selected" << std::endl;
    }

    // Execute adaptive optimization on sample code
    auto res = optimizer.optimize_adaptive("int main() { return 0; }");
    std::cout << "Optimization improvement: " << res.improvement_percent << "%\n" << std::endl;

    telemetry.stop_monitoring();
}
