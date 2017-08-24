#include <map>
#include <iostream>
using namespace std;

#define long long long
const long M = 1000000007;
map<long, long> F;

long f(long n) 
{
	if (F.count(n)) return F[n];
	long k=n/2;
	if (n%2==0) 
	{
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
	} 
	else 
	{
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
	}
}

main()
{
	long n,t,i;
	F[0]=F[1]=1;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin >> n;
	    cout << (n==0 ? 0 : f(n+1)) << endl;
	}
}