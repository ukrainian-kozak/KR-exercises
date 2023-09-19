#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../5.04/allocator.h"

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void my_qsort(void *lineptr[], int left, int right,
        int (*comp)(const void *, const void *));

void sort_lines(char *lineptr[], int nlines, int numeric, int revese, int fold, int dir_order);

int numcmp(const char *, const char *);
int revcmp(const char *, const char *);
int rncmp(const char *, const char *);
int dircmp(const char *, const char *);
int folcmp(const char *, const char *);
int dfcmp(const char *, const char *);


int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0, reverse = 0, fold = 0, dir_order = 0;

    if (argc > 1) {
        if (strcmp(argv[1], "-n") == 0) {
            numeric = 1;
        } else if (strcmp(argv[1], "-nr") == 0 || strcmp(argv[1], "-rn") == 0) {
            numeric = 1;
            reverse = 1;
        } else if (strcmp(argv[1], "-r") == 0) {
            reverse = 1;
        } else if (strcmp(argv[1], "-f") == 0) {
            fold = 1;
        } else if (strcmp(argv[1], "-d") == 0) {
            dir_order = 1;
        } else if (strcmp(argv[1], "-fd") == 0 || strcmp(argv[1], "-df") == 0) {
            fold = 1;
            dir_order = 1;
        } else {
            printf("There is an error in input arguments!\n");
            abort();
        }
    }



    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        sort_lines(lineptr, nlines, numeric, reverse, fold, dir_order);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort!\n");
        return 1;
    }
}

#define MAXLEN 1000     /* max length of any input line */

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int nlines, nread;
    char *p;
    char *line = NULL;

    size_t len = 0;
    nlines = 0;
    while ((nread = getline(&line, &len, stdin)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';     /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; ++i)
        printf("%s", lineptr[i]);
}

void my_qsort(void *v[], int left, int right,
        int (*comp)(const void *, const void *))
{
    int i, last;

    void swap(void *v[], int, int);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    my_qsort(v, left, last - 1, comp);
    my_qsort(v, last + 1, right, comp);
}

void sort_lines(char *lineptr[], int nlines, int numeric, int reverse, int fold, int dir_order)
{
    int (*cmp_func)(const char *, const char *) = strcmp;

    if (numeric && !reverse) {
        cmp_func = numcmp;
    } else if (numeric && reverse) {
        cmp_func = rncmp;
    } else if (reverse) {
        cmp_func = revcmp;
    } else if (fold && !dir_order) {
        cmp_func = folcmp;
    } else if (fold && dir_order) {
        cmp_func = dfcmp;
    } else if (dir_order) {
        cmp_func = dircmp;
    } else {
        cmp_func = strcmp;
    }

    my_qsort((void **) lineptr, 0, nlines - 1, (int (*)(const void *, const void *)) (cmp_func));
}

int numcmp(const char *s1, const char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int folcmp(const char *s1, const char *s2)
{
    int i;

    for (i = 0; tolower(s1[i]) == tolower(s2[i]); ++i)
        if (s1[i] == '\0')
            return 0;
    return s1[i] - s2[i];
}

int dircmp(const char *s1, const char *s2)
{
    int i = 0;
    int j = 0;

    for ( ;; ) {
        while (!isdigit(s1[i]) && !isspace(s1[i]) && !isalpha(s1[i]))
            ++i;
        while (!isdigit(s2[j]) && !isspace(s2[j]) && !isalpha(s2[j]))
            ++j;
        if (s1[i] != s2[j])
            return s1[i] - s2[j];
        if (s1[i] == '\0')
            return 0;
        ++i;
        ++j;
    }
}

int dfcmp(const char *s1, const char *s2)
{
    int i = 0;
    int j = 0;

    for ( ;; ) {
        while (!isdigit(s1[i]) && !isspace(s1[i]) && !isalpha(s1[i]))
            ++i;
        while (!isdigit(s2[j]) && !isspace(s2[j]) && !isalpha(s2[j]))
            ++j;
        if (tolower(s1[i]) != tolower(s2[j]))
            return s1[i] - s2[j];
        if (s1[i] == '\0')
            return 0;
        ++i;
        ++j;
    }
}

int revcmp(const char *s1, const char *s2) 
{
    int i;

    for (i = 0; s2[i] == s1[i]; ++i)
        if (s2[i] == '\0')
            return 0;
    return s2[i] - s1[i];
}

int rncmp(const char *s1, const char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return 1;
    else if (v1 > v2)
        return -1;
    else
        return 0;
}

void swap (void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
