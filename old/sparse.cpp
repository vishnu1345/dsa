#include<iostream>
using namespace std;

int main(){
    int sparseMatrix[4][5] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };

    int size = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            if(sparseMatrix[i][j]!=0){
                size++;
            }
        }
    }

    int compact[size+1][3];
    int k =1;
    compact[0][0]=4;
    compact[0][1]=6;
    compact[0][2]=size;

    // int size = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            if(sparseMatrix[i][j]!=0){
                compact[k][0]=i;
                compact[k][1]=j;
                compact[k][2]=sparseMatrix[i][j];
                k++;
            }
        }
    }

      for (int i=0; i<size+1; i++)
    {
        for (int j=0; j<3; j++)
            cout<<compact[i][j];

        cout<<endl;
    }
}