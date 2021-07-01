/*Implementation
Team 22
Aakarshita Choudhary 10501012019
Sona Jaiswal         13101012019
*/

#include <stdio.h>
#include<stdbool.h>
#include<iostream>

using namespace std ;

void swap_ele(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_ele(int arr[], int n)
{

    for(int i = 0; i < n-1 ; i++)
    {
        for(int j = 0; j < n - i -1; j++)
        {
            if(arr[j] > arr[j + 1])
                swap_ele(&arr[j], &arr[j + 1]);
        }
    }
}

int main()
{

    int cnt = 0 ;

    cout<<"ADA Project "<<endl;
    cout << "SUBSET SUM PROBLEM " << endl ;
    int N;
    cout<<"Enter the total number of elements: ";
    cin>>N;

    int i;
    int Elements[N] = {0};
    for(int i=0;i<N;i++)
    {
       cin>>Elements[i];
    }


    int C=0;
    cout <<"Enter the Target Sum: " << endl ;
    cin>>C;
    cout << endl ;

    int bitmap[N], K, PSum, Iteration, Count, I, J;
    bool Found;

    sort_ele(Elements ,N) ;    //sort the elements in ascending order

    Iteration =1; Count =0;


    int count=0;
    for(i=0;i<N;i++)
    {
        if(Elements[i]<=C)
        {
            count++;
        }
    }

    N = count;

    K=N;
//initialize bitmap to 0
    for(I=K-1;I>=0;I--)
    {
        bitmap[I]=0;
    }

    PSum=0;

    MIDDLE:

    for(I=K-1;I>=0;I--)
    {
        if ((PSum + Elements[I]) <=C)
        {

            bitmap[I]=1;
            PSum=PSum + Elements[I];
        }
    }

    if (C==PSum)
    {
        if(cnt == 0 ){
            cout << "Following are the possible subsets : " ;
            cout << endl ;
            cnt ++ ;
        }

        for(i=0;i<N;i++)
        {
            if (bitmap[i]==1)         //Printing the elements where bitmap is set to 1
            {
                cout << Elements[i] << " ";
            }
        }
        cout << endl ;
        Count++;
        Found=true;
    }

    J=0;
    Found=false;
    while((J<N-1)&&(!Found))
    {
        if( (bitmap[J]==0)&&(bitmap[J+1]==1))         //finding the first 01 in the bitmap , starting from J = 0
        {
            Found = true;
            break;
        }
        else
            J++;
    }

    if (!Found) goto END ;

    else
    {
        bitmap[J]=1;
        bitmap[J+1]=0;

        for((I=0);I<J;I++)
        {
            bitmap[I]=0;
        }
    }

    PSum=0;
    for(I=N-1;I>=J;I--)
    {
        if (bitmap[I]==1)
        {
            PSum+=Elements[I];
        }
    }

    K=J;
    Iteration++;
    goto MIDDLE ;


    END:
    {
        cout << endl ;
        cout << "No of iterations : " << Iteration << endl ;
        cout << "No of solutions  :" << Count << endl ;

        return 0;
    }

}




