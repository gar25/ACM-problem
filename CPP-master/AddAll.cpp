#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main(void){

	int n, n1;


	while(scanf("%d", &n), n){

		priority_queue<int, vector<int>, greater<int> > q;

		for(int i = 0; i < n; i++){
			scanf("%d", &n1);
			q.push(n1);
		}

		int cost = 0, temp = 0;

		for(;q.size() > 1;){
			temp = q.top();
			q.pop();
			temp += q.top();
			q.pop();
			cost += temp;
			q.push(temp);
		}

		cout << cost << endl;

	}

	return 0;
}
