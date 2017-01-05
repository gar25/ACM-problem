#include <vector>
#include <iostream>

using namespace std;

#define LSOne(S) (S & (-S))

typedef vector<int> vi;

class FenwickTree {
private: vi ft;
public : FenwickTree(int n){
	ft.assign(n + 1, 0);
}

int rsq(int b){
	int sum = 0;
	for(; b; b-= LSOne(b))
		sum += ft[b];
	return sum;
}

int rsq(int a, int b){
	return rsq(b) - (a == 1 ? 0 : rsq(a-1));
}

//adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
void adjust(int k, int v) {
	for(; k < (int)ft.size(); k += LSOne(k))
		ft[k] += v;
}
};


int main(){
	int n, x, y;
	vi level_counts;
	scanf("%d", &n);

	FenwickTree ft(320001);
	level_counts.assign(n, 0);

	for(int i = 0; i < n; i++){
		scanf("%d %d", &x, &y);
		level_counts[ft.rsq(x + 1)]++; //shift over X because the fen tree is 1 indexed
		ft.adjust(x + 1, 1);
	}

	for(int i = 0; i < n; i++){
		cout << level_counts[i] << endl;
	}
	return 0;

}
