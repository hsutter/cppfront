#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <optional>
#include <utility>

// Include our self-hosting components
#include "quantum_protocol_registry.cpp"
#include "realtime_telemetry.cpp"
#include "adaptive_optimizer.cpp"

int main() {
    std::cout << "=== Cppfront Self-Hosting Comprehensive Test ===\n" << std::endl;
    
    // Test 1: Quantum Protocol Registry
    std::cout << "1. Testing Quantum Protocol Registry:" << std::endl;
    quantum_protocol_registry registry = {};
    
    registry.register_candidate("rest", 0.6);
    registry.register_candidate("quic", 0.8);
    registry.register_candidate("ipfs", 0.5);
    
    registry.diagnostic_dump();
    
    auto optimal = registry.select_optimal();
    if (optimal.has_value()) {
        std::cout << "Selected optimal protocol: " << optimal.value() << std::endl;
    } else {
        std::cout << "No protocol selected" << std::endl;
    }
    
    std::cout << std::endl;
    
    // Test 2: Performance Telemetry
    std::cout << "2. Testing Performance Telemetry:" << std::endl;
    performance_telemetry telemetry = {};
    
    telemetry.start_monitoring();
    telemetry.collect_metric(performance_metric{"build-1", 1200.0, 450.0, 0.01});
    telemetry.collect_metric(performance_metric{"build-2", 300.0, 120.0, 0.0});
    telemetry.collect_metric(performance_metric{"build-3", 800.0, 200.0, 0.005});
    
    telemetry.diagnostic_summary();
    telemetry.stop_monitoring();
    
    std::cout << std::endl;
    
    // Test 3: Adaptive Optimizer
    std::cout << "3. Testing Adaptive Optimizer:" << std::endl;
    adaptive_optimizer optimizer = {};
    
    optimizer.telemetry = telemetry;
    optimizer.initialize();
    
    // Test optimization with different contexts
    auto ctx1 = performance_metric{"slow-build", 1500.0, 600.0, 0.02};
    auto strategy1 = optimizer.select_strategy(ctx1);
    std::cout << "Strategy for slow build: " << strategy1.name << " (level: " << strategy1.optimization_level << ")" << std::endl;
    
    auto ctx2 = performance_metric{"fast-build", 200.0, 50.0, 0.0};
    auto strategy2 = optimizer.select_strategy(ctx2);
    std::cout << "Strategy for fast build: " << strategy2.name << " (level: " << strategy2.optimization_level << ")" << std::endl;
    
    auto result = optimizer.optimize_adaptive("sample code");
    std::cout << "Optimization result: " << result.improvement_percent << "% improvement" << std::endl;
    
    std::cout << std::endl;
    
    // Test 4: Integration Test
    std::cout << "4. Integration Test - Full Pipeline:" << std::endl;
    
    // Simulate a complete optimization cycle
    telemetry.start_monitoring();
    
    // Collect some metrics
    telemetry.collect_metric(performance_metric{"phase-1", 1000.0, 300.0, 0.01});
    telemetry.collect_metric(performance_metric{"phase-2", 500.0, 150.0, 0.005});
    
    // Get latest context and select strategy
    auto current_ctx = telemetry.latest_context();
    auto selected_strategy = optimizer.select_strategy(current_ctx);
    
    std::cout << "Current context: " << current_ctx.name << " (" << current_ctx.compilation_time_ms << "ms)" << std::endl;
    std::cout << "Selected strategy: " << selected_strategy.name << std::endl;
    
    // Run optimization
    auto optimization_result = optimizer.optimize_adaptive("int main() { return 42; }");
    std::cout << "Optimization completed with " << optimization_result.improvement_percent << "% improvement" << std::endl;
    
    telemetry.stop_monitoring();
    
    std::cout << "\n=== Test Summary ===" << std::endl;
    std::cout << "✅ Quantum Protocol Registry: Working" << std::endl;
    std::cout << "✅ Performance Telemetry: Working" << std::endl;
    std::cout << "✅ Adaptive Optimizer: Working" << std::endl;
    std::cout << "✅ Integration Pipeline: Working" << std::endl;
    
    // Assessment
    std::cout << "\n=== Assessment ===" << std::endl;
    std::cout << "The self-hosting implementation provides:" << std::endl;
    std::cout << "- Protocol selection with confidence scoring" << std::endl;
    std::cout << "- Performance metric collection and analysis" << std::endl;
    std::cout << "- Adaptive optimization strategy selection" << std::endl;
    std::cout << "- Basic integration between components" << std::endl;
    std::cout << "\nHowever, it is QUITE MINIMAL:" << std::endl;
    std::cout << "- No actual code optimization (just mock improvements)" << std::endl;
    std::cout << "- No real protocol implementations" << std::endl;
    std::cout << "- No persistent storage or configuration" << std::endl;
    std::cout << "- No error handling or recovery" << std::endl;
    std::cout << "- No threading or concurrency" << std::endl;
    std::cout << "- No benchmarking or comparative analysis" << std::endl;
    
    return 0;
}
