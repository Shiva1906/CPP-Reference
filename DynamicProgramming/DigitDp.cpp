//Digit DP : (G-One Numbers SPOJ)

#include<bits/stdc++.h>
using namespace std;
int dp[18][180][2];
set<int>mp;
void sieve()
{
	int n = 90;
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
	for (int p = 2; p * p <= n; p++) 
	{
		if (prime[p] == true) 
		{
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	for (int p = 2; p <= n; p++)
		if (prime[p])
		{
			mp.insert(p);
		}
}

 
 
int fun(int pos,int sum,int f,vector<int>&nums)
{
	if(pos>=nums.size())
	{
		return (mp.find(sum)!=mp.end());
	}

	if(dp[pos][sum][f]!=-1)
	{
		return dp[pos][sum][f];
	}

	int limit = 9;
	if(f) limit = nums[pos];

	int ans = 0;
	for(int dg = 0;dg<=limit;dg++)
	{
		int flag = f;
		if(f and dg == nums[pos])
		{
			flag = 1;
		}
		else{
			flag = 0;
		}

		ans += fun(pos+1,sum+dg,flag,nums);
	}

	return dp[pos][sum][f] = ans;

}
 
 
void solve()
{
	int a,b;
	cin>>a>>b;
	int x = b;
	//x;
	vector<int>v,v1;
	while(x)
	{
		v.push_back(x%10);
		x/=10;
	}
	reverse(v.begin(),v.end());
	memset(dp,-1,sizeof(dp));

	int ans_a = fun(0,0,1,v);

	int y = a;
	y--;
	while(y)
	{
		v1.push_back(y%10);
		y/=10;
	}
	reverse(v1.begin(),v1.end());
	memset(dp,-1,sizeof(dp));
	int ans_b = fun(0,0,1,v1);
	//cout<<ans_a<<" "<<ans_b<<endl;
	cout<<ans_a-ans_b<<endl;
}
 
 
int main()
{
	int t;
	cin>>t;
	sieve();

	while(t--)
	{
		solve();
	}

}
