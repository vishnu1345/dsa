#include <iostream>
using namespace std;

int main()
{
    int array[3][3] = {{0,1,2}, {0,0,5}, {0,3,0}};
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j ++)
        {
            if (array[i][j] != 0)
            {
                count ++;
            }
        }
    }
    int sparse[count][3];
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0 ; j < 3; j++)
        {
            if (array[i][j]!=0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = array[i][j];
                k++;
            }
        }
    }
    int check = 0;
    
    for (int i = 0 ; i < count; i ++)
    {
        // for (int j = 0; j < 3; j++)
        
            cout << sparse[i][0]<<" "<<sparse[i][1]<<"  "<<sparse[i][2]<<endl;
        
    }
    cout << "Hello\n";
    for (int i = 0; i < k; i++)
    {
        int temp = sparse[i][0];
        sparse[i][0] = sparse[i][1];
        sparse[i][1] = temp;
    }
    for (int i = 0 ; i < count; i ++)
    {   
            cout << sparse[i][0]<<" "<<sparse[i][1]<<"  "<<sparse[i][2]<<endl;   
    }
    cout << "transpose\n";
    for (int i = 0; i < k-1; i++)
    {
        for (int j = 0; j < k-1-i; j++)
        {
            if (sparse[j][0]>sparse[j+1][0])
            {
                int temp[3] = {sparse[j][0],sparse[j][1],sparse[j][2]};
                sparse[j][0] = sparse[j+1][0];
                sparse[j][1] = sparse[j+1][1];
                sparse[j][2] = sparse[j+1][2];
                sparse[j+1][0]= temp[0];
                sparse[j+1][1]= temp[1];
                sparse[j+1][2]= temp[2];
            }
        }
    }
}