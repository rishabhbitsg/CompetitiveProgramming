#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

int main() {
  int a[8][8];
  string n;
  cin >> n;

 
  string s2;
  cin >> s2;

  int l = n.length();
  int x = 0, y = 0;
  for(int i = 0; i < l; i++)
  {
     if(n[i] >= 48 && n[i] <= 57)
     {
         int r = n[i] - 48;
         for(int j = 1; j <= r; j++)
         {
             a[x][y] = 0;
             y++;
         }
     }

     else if(n[i] == 47)
     {
         x++;
         y = 0;
     }

     else if(n[i] == 66)
     {
        if (s2[0] == 'w') {
          a[x][y] = 2;
          y++;
        }
     }

     else
     {
         a[x][y] = 1;
         y++;
     }
 }


  // for (int i = 0; i < 7; i++) {
  //   for (int j = 0; j < 7; j++) {
  //     cout << a[i][j] << " ";
  //   }
  //   cout << endl;
  // }


  cout << endl;
}