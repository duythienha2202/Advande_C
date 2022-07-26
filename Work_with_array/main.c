// this funciton use to compare two string if them similar
int compare_str(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] != '\0')
    {
        if (s1[i] == s2[i]){
            i++;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
    R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
//find the smallest number in an array
int min_of_arr(int Arr[], int length_arr)
{
    mergeSort(Arr, 0, length_arr - 1);
    return Arr[0];
}
//find the biggest number in an array
int max_of_arr(int Arr[], int length_arr)
{
    mergeSort(Arr, 0, length_arr - 1);
    return Arr[length_arr - 1];
}

