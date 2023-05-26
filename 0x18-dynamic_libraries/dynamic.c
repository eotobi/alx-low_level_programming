#include <unistd.h>

int _putchar(char c) {
    return write(1, &c, 1);
}

int _islower(int c) {
    return (c >= 'a' && c <= 'z');
}

int _isalpha(int c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int _abs(int n) {
    return (n < 0) ? -n : n;
}

int _isupper(int c) {
    return (c >= 'A' && c <= 'Z');
}

int _isdigit(int c) {
    return (c >= '0' && c <= '9');
}

int _strlen(char *s) {
    int length = 0;
    while (*s) {
        length++;
        s++;
    }
    return length;
}

void _puts(char *s) {
    while (*s) {
        _putchar(*s);
        s++;
    }
}

char *_strcpy(char *dest, char *src) {
    char *start = dest;
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return start;
}

int _atoi(char *s) {
    int result = 0;
    int sign = 1;
    if (*s == '-') {
        sign = -1;
        s++;
    }
    while (*s) {
        result = result * 10 + (*s - '0');
        s++;
    }
    return sign * result;
}

char *_strcat(char *dest, char *src) {
    char *start = dest;
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return start;
}

char *_strncat(char *dest, char *src, int n) {
    char *start = dest;
    while (*dest) {
        dest++;
    }
    while (*src && n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    *dest = '\0';
    return start;
}

char *_strncpy(char *dest, char *src, int n) {
    char *start = dest;
    while (*src && n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    while (n > 0) {
        *dest = '\0';
        dest++;
        n--;
    }
    return start;
}

int _strcmp(char *s1, char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

char *_memset(char *s, char b, unsigned int n) {
    char *start = s;
    while (n > 0) {
        *s = b;
        s++;
        n--;
    }
    return start;
}

char *_memcpy(char *dest, char *src, unsigned int n) {
    char *start = dest;
    while (n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    return start;
}

char *_strchr(char *s, char c) {
    while (*s) {
        if (*s == c) {
            return s;
        }
        s++;
    }
    if (*s == c) {
        return s;
    }
    return NULL;
}

unsigned int _strspn(char *s, char *accept) {
    unsigned int count = 0;
    while (*s && _strchr(accept, *s)) {
        count++;
        s++;
    }
    return count;
}

char *_strpbrk(char *s, char *accept) {
    while (*s) {
        if (_strchr(accept, *s)) {
            return s;
        }
        s++;
    }
    return NULL;
}

char *_strstr(char *haystack, char *needle) {
    while (*haystack) {
        char *h = haystack;
        char *n = needle;
        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }
        if (!*n) {
            return haystack;
        }
        haystack++;
    }
    return NULL;
}

