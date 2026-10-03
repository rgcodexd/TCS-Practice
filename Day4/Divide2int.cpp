#include <climits>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the special overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the final result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to prevent overflow when taking abs(INT_MIN)
        long long pvd = std::abs(static_cast<long long>(dividend));
        long long pvs = std::abs(static_cast<long long>(divisor));

        long long quotient = 0;

        // Subtract shifted multiples of the divisor from the dividend
        while (pvd >= pvs) {
            long long temp = pvs, multiple = 1;
            
            // Double the divisor and the multiplier until the next shift exceeds pvd
            while (pvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            
            pvd -= temp;
            quotient += multiple;
        }

        return negative ? -quotient : quotient;
    }
};