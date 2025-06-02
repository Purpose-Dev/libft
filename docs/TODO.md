# Todo

## Mathematics functions

---

### **ft_is_nan(double x) / ft_is_inf(double x)**

```
INPUT: double x
OUTPUT: int (0 or 1)
BEHAVIOR (C99 COMPLIANT):
  • is_nan: Returns 1 if x is NaN, 0 otherwise
  • is_inf: Returns 1 if x is ±inf, 0 otherwise
ERRORS: None
ERRNO: Unmodified
```

### **ft_fibonacci(int n)**

```
INPUT: int n
OUTPUT: long
BEHAVIOR:
  • n < 0 → Returns -1 (error)
  • n == 0 → Returns 0
  • n == 1 → Returns 1
  • n >= 2 → F(n) = F(n-1) + F(n-2)
OVERFLOW:
  • n > 78 → long overflow (unprotected)
ERRORS: n < 0, overflow
ERRNO: Unmodified
```

### **ft_next_prime(int n)**

```
INPUT: int n
OUTPUT: int
BEHAVIOR:
  • n < 2 → Returns 2 (first prime)
  • n >= 2 → Returns the smallest prime > n
LIMIT:
  • If no prime found before INT_MAX → Returns -1
ERRORS: No prime found
ERRNO: Unmodified
```

### **ft_sin(double x) / ft_cos(double x)**

```
INPUT: double x (radians)
OUTPUT: double [-1.0, 1.0]
BEHAVIOR (C99 COMPLIANT):
  • x finite → Mathematical sin/cos
  • x == ±inf → Returns nan, errno = EDOM
  • x == nan → Returns nan
PRECISION: ~15 decimal places
ERRORS: x == ±inf
ERRNO: EDOM if x == ±inf
```

### **ft_tan(double x)**

```
INPUT: double x (radians)
OUTPUT: double
BEHAVIOR (C99 COMPLIANT):
  • x finite → tan(x) = sin(x)/cos(x)
  • x == π/2 + nπ → Returns ±inf, errno = ERANGE
  • x == ±inf → Returns nan, errno = EDOM
  • x == nan → Returns nan
ERRORS: Division by zero, x == ±inf
ERRNO: ERANGE (asymptotes), EDOM (±inf)
```

### **ft_sinh(double x) / ft_cosh(double x)**

```
INPUT: double x
OUTPUT: double
BEHAVIOR (C99 COMPLIANT):
  • sinh(x) = (e^x - e^-x) / 2
  • cosh(x) = (e^x + e^-x) / 2
  • x == ±inf → sinh returns ±inf, cosh returns +inf
  • x == nan → Returns nan
OVERFLOW:
  • |x| > ~700 → Overflow, errno = ERANGE
ERRORS: Overflow
ERRNO: ERANGE if overflow
```