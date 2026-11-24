/* Loader_DLL.xex 0x831D7ED8-0x831D83C4 (two identical copies), executable version 0.0.0.3.
 * k-th smallest element of a float array (in-place quickselect with an
 * insertion-sort path for short arrays). */
#define SWAP(a, b) { temp = (a); (a) = (b); (b) = temp; }

float ts4l_select_kth_831D7ED8(float *arr, int n, int k)
{
    int l, r, i, j, mid, cnt, lim, k0, c2;
    float a, temp;

    k0 = k - 1;
    l = 0;
    r = n - 1;
    lim = 2 * n;
    if (n < 15) {
        for (j = 1; j < n; j++) {
            a = arr[j];
            for (i = j; i > 0 && a < arr[i - 1]; i--)
                arr[i] = arr[i - 1];
            arr[i] = a;
        }
        return arr[k0];
    }
    for (cnt = 0; cnt < lim; cnt += 2) {
        if (r - l <= 1)
            break;
        if (l < k0 && r > k0)
            mid = k0;
        else
            mid = (r + l) >> 1;
        SWAP(arr[mid], arr[l + 1])
        if (arr[r] < arr[l + 1])
            SWAP(arr[r], arr[l + 1])
        if (arr[r] < arr[l])
            SWAP(arr[r], arr[l])
        if (arr[l] < arr[l + 1])
            SWAP(arr[l], arr[l + 1])
        a = arr[l];
        i = l + 1;
        j = r;
        for (c2 = 0; c2 < lim; c2++) {
            do {
                i++;
            } while (arr[i] < a && i < r);
            do {
                j--;
            } while (arr[j] > a && j > l);
            if (j <= i)
                break;
            SWAP(arr[i], arr[j])
        }
        temp = arr[l];
        arr[l] = arr[j];
        arr[j] = temp;
        if (j <= k0)
            l = i;
        if (j >= k0)
            r = j - 1;
    }
    if (r == l + 1 && arr[r] < arr[l])
        SWAP(arr[r], arr[l])
    return arr[k0];
}

float ts4l_select_kth_831D8150(float *arr, int n, int k)
{
    int l, r, i, j, mid, cnt, lim, k0, c2;
    float a, temp;

    k0 = k - 1;
    l = 0;
    r = n - 1;
    lim = 2 * n;
    if (n < 15) {
        for (j = 1; j < n; j++) {
            a = arr[j];
            for (i = j; i > 0 && a < arr[i - 1]; i--)
                arr[i] = arr[i - 1];
            arr[i] = a;
        }
        return arr[k0];
    }
    for (cnt = 0; cnt < lim; cnt += 2) {
        if (r - l <= 1)
            break;
        if (l < k0 && r > k0)
            mid = k0;
        else
            mid = (r + l) >> 1;
        SWAP(arr[mid], arr[l + 1])
        if (arr[r] < arr[l + 1])
            SWAP(arr[r], arr[l + 1])
        if (arr[r] < arr[l])
            SWAP(arr[r], arr[l])
        if (arr[l] < arr[l + 1])
            SWAP(arr[l], arr[l + 1])
        a = arr[l];
        i = l + 1;
        j = r;
        for (c2 = 0; c2 < lim; c2++) {
            do {
                i++;
            } while (arr[i] < a && i < r);
            do {
                j--;
            } while (arr[j] > a && j > l);
            if (j <= i)
                break;
            SWAP(arr[i], arr[j])
        }
        temp = arr[l];
        arr[l] = arr[j];
        arr[j] = temp;
        if (j <= k0)
            l = i;
        if (j >= k0)
            r = j - 1;
    }
    if (r == l + 1 && arr[r] < arr[l])
        SWAP(arr[r], arr[l])
    return arr[k0];
}
