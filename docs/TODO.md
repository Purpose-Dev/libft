# Todo

## Mathematics functions

---

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

### **ft_memdup(const void *src, size_t n)**

```
INPUT: const void *src, size_t n
OUTPUT: void *
BEHAVIOR (C99 COMPLIANT):
  • Duplicates n bytes of memory
  • Allocates n bytes with malloc()
  • Copies content from src
  • src == NULL → returns NULL
  • n == 0 → returns valid pointer to 0 bytes
ERRORS: Memory allocation failure
ERRNO: None (malloc sets errno)
```

### **ft_memrchr(const void *s, int c, size_t n)**

```
INPUT: const void *s, int c, size_t n
OUTPUT: void *
BEHAVIOR (C99 COMPLIANT):
  • Searches for last occurrence of byte c in memory area s
  • Searches backwards from s+n-1 to s
  • Returns pointer to last occurrence or NULL if not found
ERRORS: None
ERRNO: None
```

### **ft_memccpy(void *dest, const void *src, int c, size_t n)**

```
INPUT: void *dest, const void *src, int c, size_t n
OUTPUT: void *
BEHAVIOR (C99 COMPLIANT):
  • Copies bytes from src to dest until c is found or n bytes copied
  • Stops at first occurrence of c
  • Returns pointer to byte after c in dest, or NULL if c not found
  • If c found, copies c as well
ERRORS: None
ERRNO: None
```

### **ft_memcasecmp(const void *s1, const void *s2, size_t n)**

```
INPUT: const void *s1, const void *s2, size_t n
OUTPUT: int
BEHAVIOR (C99 COMPLIANT):
  • Case-insensitive memory comparison
  • Compares n bytes treating ASCII letters case-insensitively
  • Returns <0, 0, >0 based on comparison result
  • Converts ASCII A-Z to a-z before comparison
ERRORS: None
ERRNO: None
```

## String functions

---

### **ft_strcpy(char *dest, const char *src)**

```
INPUT: char *dest, const char *src
OUTPUT: char *
BEHAVIOR (C99 COMPLIANT):
  • Copies string src to dest including null terminator
  • Returns pointer to dest
  • dest must have enough space allocated
  • Copies until '\0' is encountered and copied
ERRORS: Buffer overflow (undefined behavior)
ERRNO: None
```

### **ft_strcat(char *dest, const char *src)**

```
INPUT: char *dest, const char *src
OUTPUT: char *
BEHAVIOR (C99 COMPLIANT):
  • Concatenates src string to end of dest string
  • Returns pointer to dest
  • Finds end of dest, then appends src with null terminator
  • dest must have enough space for concatenated result
ERRORS: Buffer overflow (undefined behavior)
ERRNO: None
```

### **ft_strcmp(const char *s1, const char *s2)**

```
INPUT: const char *s1, const char *s2
OUTPUT: int
BEHAVIOR (C99 COMPLIANT):
  • Compares strings s1 and s2 lexicographically
  • Returns <0 if s1 < s2, 0 if s1 == s2, >0 if s1 > s2
  • Compares byte by byte until difference found or end reached
  • Uses unsigned char values for comparison
ERRORS: None
ERRNO: None
```

### **ft_strstr(const char *haystack, const char *needle)**

```
INPUT: const char *haystack, const char *needle
OUTPUT: char *
BEHAVIOR (C99 COMPLIANT):
  • Searches for first occurrence of substring needle in haystack
  • Returns pointer to first occurrence or NULL if not found
  • If needle is empty string, returns haystack
  • Case-sensitive search
ERRORS: None
ERRNO: None
```

### **ft_strcspn(const char *s, const char *reject)**

```
INPUT: const char *s, const char *reject
OUTPUT: size_t
BEHAVIOR (C99 COMPLIANT):
  • Returns length of initial segment of s with no chars from reject
  • Scans s until first character present in reject is found
  • Returns number of characters before first rejected character
  • If no rejected chars found, returns strlen(s)
ERRORS: None
ERRNO: None
```

### **ft_strspn(const char *s, const char *accept)**

```
INPUT: const char *s, const char *accept
OUTPUT: size_t
BEHAVIOR (C99 COMPLIANT):
  • Returns length of initial segment of s with only chars from accept
  • Counts characters from beginning of s that are in accept
  • Stops at first character not in accept
  • Returns count of accepted characters from start
ERRORS: None
ERRNO: None
```

### **ft_strtok(char *str, const char *delim)**

```
INPUT: char *str, const char *delim
OUTPUT: char *
BEHAVIOR (C99 COMPLIANT):
  • Tokenizes string using delimiters
  • First call: str = string to tokenize, subsequent: str = NULL
  • Returns pointer to next token or NULL if no more tokens
  • Modifies original string (replaces delimiters with '\0')
  • Uses internal static variable to maintain state
ERRORS: None
ERRNO: None
```

## Conversion functions

---

### **ft_atol(const char *str)**

```
INPUT: const char *str
OUTPUT: long
BEHAVIOR (C99 COMPLIANT):
  • Converts string to long integer
  • Skips leading whitespace
  • Accepts optional + or - sign
  • Stops at first non-digit character
  • Format: [whitespace][sign]digits
OVERFLOW: Undefined behavior (follows C99 standard)
ERRORS: None
ERRNO: None
```

### **ft_atof(const char *str)**

```
INPUT: const char *str
OUTPUT: double
BEHAVIOR (C99 COMPLIANT):
  • Converts string to double floating-point
  • Skips leading whitespace
  • Accepts optional + or - sign
  • Format: [whitespace][sign]digits[.digits][(e|E)[sign]digits]
  • Special cases: "inf", "infinity", "nan" (case-insensitive)
OVERFLOW: Returns ±HUGE_VAL, errno = ERANGE
ERRORS: Overflow, underflow
ERRNO: ERANGE on overflow/underflow
```

### **ft_ltoa(long n)**

```
INPUT: long n
OUTPUT: char *
BEHAVIOR (EXTENSION):
  • Converts long integer to string
  • Returns dynamically allocated string or NULL
  • Decimal representation with sign if negative
  • User responsible for freeing returned pointer
ERRORS: Memory allocation failure
ERRNO: None (malloc sets errno)
```

### **ft_utoa(unsigned int n)**

```
INPUT: unsigned int n
OUTPUT: char *
BEHAVIOR (EXTENSION):
  • Converts unsigned integer to string
  • Returns dynamically allocated string or NULL
  • Decimal representation without sign
  • User responsible for freeing returned pointer
ERRORS: Memory allocation failure
ERRNO: None (malloc sets errno)
```

### **ft_ftoa(double f, int precision)**

```
INPUT: double f, int precision
OUTPUT: char *
BEHAVIOR (EXTENSION):
  • Converts double to string with fixed decimal notation
  • precision specifies number of decimal places
  • Returns dynamically allocated string or NULL
  • Special cases: "inf", "-inf", "nan"
  • Rounding: IEEE 754 round-to-nearest-even
ERRORS: Memory allocation failure
ERRNO: None (malloc sets errno)
```
