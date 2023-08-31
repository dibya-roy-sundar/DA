#include <iostream>
#include <string>
using namespace std;
bool issorted(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        return issorted(arr + 1, size - 1);
    }
}
bool linsearch(int arr[], int size, int key)
{
    if (size == 0)
    {
        return false;
    }
    if (arr[0] == key)
    {
        return true;
    }
    else
    {
        return (linsearch(arr + 1, size - 1, key));
    }
}
int binsearch(int arr[], int s, int e, int key)
{
    if (s > e)
    {
        return -1;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    if (arr[mid] > key)
    {
        return binsearch(arr, s, mid - 1, key);
    }
    else
    {
        return binsearch(arr, mid + 1, e, key);
    }
}
void reverse(string &s, int i)
{
    if (i > (s.length() - i - 1))
    {
        return;
    }
    swap(s[i], s[(s.length() - i - 1)]);
    i++;
    reverse(s, i);
}
int checkpalindrome(string &s, int i)
{
    if (i > (s.length() - i - 1))
    {
        return -1;
    }
    if (s[i] == s[s.length() - i - 1])
    {
        checkpalindrome(s, ++i);
    }
    else
    {
        return 0;
    }
    return 1;
}
int power(int a, int b)
{
    // base case
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    // recursive call
    if (b % 2 == 0)
    {
        return power(a, b / 2) * power(a, b / 2);
    }
    else
    {
        return a * power(a, b / 2) * power(a, b / 2);
    }
}
void bubblesort(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubblesort(arr, n - 1);
}
void merge(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    // cretae two new array
    int *first = new int[len1];
    int *second = new int[len2];
    int marrindex = s;
    // copy values
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[marrindex++];
    }
    marrindex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[marrindex++];
    }
    // merge
    int i1 = 0;
    int i2 = 0;
    marrindex = s;
    while (i1 < len1 && i2 < len2)
    {
        if (first[i1] < second[i2])
        {
            arr[marrindex++] = first[i1++];
        }
        else
        {
            arr[marrindex++] = second[i2++];
        }
    }
    while (i1 < len1)
    {
        arr[marrindex++] = first[i1++];
    }
    while (i2 < len2)
    {
        arr[marrindex++] = second[i2++];
    }
    delete[] first;
    delete[] second;
}
void mergesort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    // left
    mergesort(arr, s, mid);
    // right
    mergesort(arr, mid + 1, e);
    // merge
    merge(arr, s, e);
}

int partition(int arr[], int s, int e)
{
    // take a pivot
    int pivot = arr[s];
    int cnt = 0;
    // count the no of  element smaller than pivot
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < pivot)
        {
            cnt++;
        }
    }
    int pivotindex = s + cnt;
    // put in right place
    swap(arr[pivotindex], arr[s]);

    int i = s;
    int j = e;
    while (i < pivotindex && j > pivotindex)
    {
        while (arr[i] < arr[pivotindex])
        {
            i++;
        }
        while (arr[j] > arr[pivotindex])
        {
            j--;
        }
        if(i < pivotindex && j > pivotindex){
            swap(arr[i++], arr[j--]);
        }

    }
        return pivotindex;
}

    void quicksort(int arr[], int s, int e)
    {
        // base case
        if (s >= e)
        {
            return ;
        }
        // partition
        int p = partition(arr, s, e);
        // recursive call
        quicksort(arr, s, p - 1);
        quicksort(arr, p + 1, e);
    }
    int main()
    {
        int test[5] = {1, 8, 3, 9, 5};
        string s = "diid";
        // if(issorted(test,5)){
        //     cout<<"yes,sorted";
        // }else{
        //     cout<< "not sorted";
        // }
        // if(linsearch(test,5,4)){
        //     cout<<"yes,found";
        // }else{
        //     cout<< "not found";
        // }
        // cout<<binsearch(test,0,4,6)<<endl;
        // reverse(s,0);
        // cout<<s<<endl;
        // if(checkpalindrome(s,0)){
        //     cout<<"yes,palindrome";
        // }else{
        //     cout<< "not palindrome";
        // }
        // bubblesort(test,5);
        // mergesort(test, 0, 4);
        quicksort(test, 0, 4);
        for (int i = 0; i < 5; i++)
        {
            cout << test[i];
        }
        // cout<<power(1,5)<<endl;
        return 0;
    }