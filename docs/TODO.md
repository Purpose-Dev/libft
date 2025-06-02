# Todo

## Mathematics functions

---

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

## Memory functions

--- 

## String functions

--- 
