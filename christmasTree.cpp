#include <iostream>
#include <cstdlib>
using namespace std;

void drawTree (int n, int m) {
    if ( m <= n/2 ) {
        for (int i=0; i < n/2 - m + 2; i++) cout << " ";
        for (int j=1; j <= m; j++) cout << '/';
        cout << '#';
        for (int j=1; j <= m; j++) cout << '\\';
        cout << endl;
        drawTree(n, m+1);
    }
}


int main()
{
    int n;
    cout << "How tall should your tree be (integer between 1-58)?" << endl;
    cin >> n;
    cout << endl;
    cout << endl;
    cout<<"Ho! Ho! Ho! Here's your Christmas Tree:"<<endl;
    cout << endl;
    cout << endl;
    for (int i=0; i <= n+1; i++) {
        cout << " ";
    }
    cout << '*' << endl;
    drawTree(2*n, 1);
    for (int i=0; i <= n+1; i++) {
        cout << " ";
    }
    cout << '#' << endl;
    cout << endl;
    cout << endl;
    cout << "        _  _   _         _      _  .  _ ___        _   _   |  |  |" << endl;
    cout << "  |\\/| |_ |_| |_| \\_/   |  |_| |_| | |_  |  |\\/|  /_\\ |_   |  |  |" << endl;
    cout << "  |  | |_ | \\ | \\  |    |_ | | | \\ |  _| |  |  | /   \\ _|  .  .  ." << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    system ("pause");
}
