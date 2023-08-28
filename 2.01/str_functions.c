int myatoi(char s[])
{
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

int myto_lower(int c)
{
    return (c >= 'A' && c<= 'Z') ? (c + 'a' - 'A') : c;
}

int myto_upper(int c)
{
    if (c >= 'a' && c <= 'z')
        return c + 'A' - 'a';
    else
        return c;
}

int isdigit(int c) 
{
    return (c >= '0' && c <= '9') ? 1 : 0;
}


