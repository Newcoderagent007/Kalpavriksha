#include <stdio.h>

unsigned long long modular_exponentiation(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    base = base % mod; // Update base if it is more than or equal to mod
    
    while (exp > 0) {
        // If exp is odd, multiply base with result
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        // exp must be even now
        exp = exp/2; 
        base = (base * base) % mod; 
    }
    return result;
}

int main() {
    unsigned long long base, exp, mod;
    
    // Input validation
    do {
        printf("Enter base (positive integer): ");
        scanf("%llu", &base);
    } while(base <= 0);
    
    do {
        printf("Enter exponent (positive integer): ");
        scanf("%llu", &exp);
    } while(exp < 0);
    
    do {
        printf("Enter modulus (greater than 1): ");
        scanf("%llu", &mod);
    } while(mod <= 1);
    
    // Calculate the result of (base^exp) % mod
    unsigned long long result = modular_exponentiation(base, exp, mod);
    printf("Result: %llu\n", result);

    return 0;
}
