#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

void showArray(int ar[], int members)
{
    for(int i=0;i < members;i++)
        cout << ar[i] << '\t';
    cout << endl;

}

void bubbleSort(int ar[],int members)
{
    int i,j,temp;
    for(i=0;i<members; i++)
    {
        for(j=i+1;j<members;j++)
        {
            if(ar[i]> ar[j])
            {
                temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
}

float mean(int ar[],int members)
{
    int sum = 0;
    for(int i=0;i<members;i++)
    {
        sum += ar[i];
    }
    return (float) sum/members;

}

float median(int ar[],int members)
{
    bubbleSort(ar, members);
    if(members%2 == 1)
    {
        return ar[members/2];
    }
    else
    {
        return (float) (ar[members/2]+ar[members/2 - 1]) / 2;
    }

}

int maximum(int ar[],int members)
{
    int result = ar[0];
    for(int i=0;i<members;i++)
    {
        if(ar[i]>result)
        {
            result = ar[i];
        }
    }
    return result;
}

int minimum(int ar[],int members)
{
    int result = ar[0];
    for(int i=0;i<members;i++)
    {
        if(ar[i]<result)
        {
            result = ar[i];
        }
    }
    return result;
}

float variance(int ar[],int members)
{
    float m = mean(ar, members);
    float numerator = 0;
    for(int i=0;i<members;i++)
    {
        numerator += pow((ar[i]-m),2);
    }

    return numerator/members;
}
float standard_deviation(int ar[],int members)
{
    return sqrt(variance(ar, members));
}
int main()
{
    int members;
    cout << "how many numbers : ";
    cin >> members;
    int ar[members];
    cout << "Enter numbers : ";
    for(int i=0;i<members;i++)
    {
        cin >> ar[i];
    }

    showArray(ar, members);
    cout << endl << endl;

    cout << "mean = " << mean(ar, members) << endl;
    cout << "median = " << median(ar, members) << endl;
    cout << "variance = " << variance(ar, members) << endl;
    cout << "standard deviation = " << standard_deviation(ar, members) << endl;
    cout << "maximum = " << maximum(ar, members) << endl;
    cout << "minimum = " << minimum(ar, members) << endl;

    getch();
}
