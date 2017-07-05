#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;



void rysujChoine (int n, int m)
{
    if (m<=(n/2))
    {
        for (int i=0;i<n/2-m+2;i++) cout<<" ";
        for (int j=1; j<=m;j++) cout<<'/';
        cout<<'#';
        for (int j=1; j<=m;j++) cout<<'\\';
        cout<<endl;
        rysujChoine(n,m+1);
    }
}


int main()
{
    int n;
    cout<<"Elo! Jak wysoka chcesz choinke (liczba z zakresu 1-58)?"<<endl;
    cin>>n;
    cout<<endl;
    cout<<endl;
    cout<<"Ho! Ho! Ho! Oto Twoja choinka:"<<endl;
    cout<<endl;
    cout<<endl;
    for (int i=0;i<=n+1;i++)
    {
        cout<<" ";
    }
    cout<<'*'<<endl;
    rysujChoine(2*n,1);
    for (int i=0;i<=n+1;i++)
    {
        cout<<" ";
    }
    cout<<'#'<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"        _  _   _         _      _  .  _ ___        _   _   |  |  |"<<endl;
    cout<<"  |\\/| |_ |_| |_| \\_/   |  |_| |_| | |_  |  |\\/|  /_\\ |_   |  |  |"<<endl;
    cout<<"  |  | |_ | \\ | \\  |    |_ | | | \\ |  _| |  |  | /   \\ _|  .  .  ."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    system ("pause");
}
