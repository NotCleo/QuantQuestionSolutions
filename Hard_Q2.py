import numpy as np

def expected_value(threshold, cost=0.02):
    # Compute E[max(threshold, x)] for x ~ Uniform(0,1)
    integral = threshold**2 + (1 - threshold**2) / 2
    return integral - cost

# Find fixed point numerically: V = threshold
thresholds = np.linspace(0, 1, 10000)
best_threshold = 0
for t in thresholds:
    expected = expected_value(t)
    if t >= expected:
        best_threshold = t
        break

print(f"Optimal threshold: {best_threshold:.4f}")
print(f"Expected payout: {expected_value(best_threshold):.4f}")
