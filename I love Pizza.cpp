/* Date: 02.06.16
Problem: 12626 - I ❤ Pizza

*/
#include <bits/stdc++.h>

using namespace std;

int main(){

	int a, b, tc, s;
	string ss;

	cin >> tc;
	while(tc--){
		cin >> ss;
		int a, m, r,t, g, ai;
		a=m=r=g=ai=t = 0;
		int res = 0;

		for(int i = 0; i<ss.length(); i++){
			if(ss[i] == 'A'){
				a++;
			}
			else if(ss[i]== 'M'){
				m++;
			}
			else if(ss[i]== 'R'){
				r++;
			}
			else if(ss[i]== 'G'){
				g++;
			}
			else if(ss[i]== 'I'){
				ai++;
			}
			else if(ss[i]== 'T'){
				t++;
			}
		}
		a /= 3;
		r /= 2;
		if(m != 0 && g != 0 && t != 0 && ai != 0){
			res = min(a, r);
			res = min(res, m);
			res = min(res, g);
			res = min(res, t);
			res = min(res, ai);
			cout << res<< endl;
		}
		else cout << 0 << endl;

	}

	return 0;
}
