int strlen(char* s)
{
    int n = 0;
    while (*s++ != '\0')
        ++n;
    return n;
}

void strcpy(char* s, const char* t, const int n)
{
    int i = 0;
    while ((*s++ = *t++) && i < n)
        ++i;
}

int strcmp(char* s, char* t, const int n)
{
    int i;

    for (i = 0; s[i] == t[i] && i < n; ++i)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

char* strcat(char* dest, const char* src, const int n)
{
    int n = strlen(dest);

    int i;
    for (i = 0; src[i] != '\0' && i < n; ++i)
        dest[n++] = src[i];

    return dest - n;
}

int strend(const char* s, const char* t)
{
    int n = strlen(s);
    int m = strlen(t);
    if (n < m)
        return 0;

    return (strcmp(s + (n - m), t) == 0) ? 1 : 0;
}
