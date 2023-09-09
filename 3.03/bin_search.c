#include <stdio.h>

int bin_search(int x, int v[], int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (x == v[mid]) {
            return mid;
        } else if (x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{

}
