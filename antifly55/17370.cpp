#include <bits/stdc++.h>
using namespace std;

int xx[] = {1,1,0,-1,-1, 0};
int yy[] = {1,-1,-2,-1,1, 2};
int visit[300][300], n;

int f(int x, int y, int direction, int recent) {
	if(visit[x][y] == 1 && n==recent) return 1;
	if(visit[x][y] == 1 || recent > n) return 0;

	visit[x][y]++;
	
	int sum = f(x + xx[(direction + 1) % 6], y + yy[(direction + 1) % 6], (direction + 1) % 6, recent + 1) +
	f(x + xx[(direction + 5) % 6], y + yy[(direction + 5) % 6], (direction + 5) % 6, recent + 1);
	
	visit[x][y]--;
	return sum;
}


int main(){
	cin >> n;
	visit[100][100]++;
	cout << f(100, 102, 5, 0) << endl;
	return 0;
}
