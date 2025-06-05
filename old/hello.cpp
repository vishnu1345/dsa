#include <iostream>
#include<math.h>
using namespace std;

int main()
{
   int arr[10] = {2,56,2,3,-2,56,54,6,66,8};
    int min = arr[0];
    int max=arr[0];
    for (int i = 0; i <10; i++)
    {
        if (arr[i]<min)
        {
            min = arr[i];
        }
        if (arr[i]>max)
        {
            max = arr[i];
        }
        
        
    }
    cout<<"max is "<<max<<endl;
    cout<<"min is "<<min<<endl;
}
