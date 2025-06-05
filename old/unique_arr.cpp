#include <iostream>
using namespace std;

int unique(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return arr[i];
                break;
            }
        }
    }
}
int main()
{
    int arr[5] = {14, 2, 1, 3, 1};
    int ans = unique(arr, 5);
    cout << ans << endl;
}