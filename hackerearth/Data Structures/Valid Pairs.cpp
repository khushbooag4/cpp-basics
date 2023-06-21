#include<bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n)
{
    if (n == 1)
        return true;
    int lastDigit = n % 10;
    map<int, int> map;
    map[3] = 1;
    map[9] = 2;
    map[7] = 3;
    map[1] = 4;
 
    if (!map[lastDigit])
        return false;
 
    int power = map[lastDigit];
    double powerOfThree = pow(3, power);
    while (powerOfThree <= n) {
        if (powerOfThree == n)
            return true;
        power = power + 4;
        powerOfThree = pow(3, power);
    }
    return false;
}

int solve (int n, vector<long long> wth) {
   // Write your code here
   //3^k - double k = log10(n) - log10(3);
   int result = 0;
   map<long long,int> mp;
   for(auto x: wth){
     mp[x]++;
   }
   
   for(auto x: wth){
      for(int j=0;j<22;j++){
          long long y = pow(3,j) - x;
          if(mp.find(y) != mp.end()){
            result += mp[y];
          }
      }
   }

   return result/2;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<long long> wealth(N);
    for(int i_wealth = 0; i_wealth < N; i_wealth++)
    {
    	cin >> wealth[i_wealth];
    }

    int out_;
    out_ = solve(N, wealth);
    cout << out_;
}