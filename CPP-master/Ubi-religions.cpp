#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
int disjointSets = 0;

class UnionFind {
private:
	vi p, rank, setSize;
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N, 1);
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}
	int findSet(int i){
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j){
		if(!isSameSet(i, j)){
			numSets--;
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y]){
				p[y] = x;
				setSize[x] += setSize[y];
			}
			else{
				p[x] = y;
				setSize[y] += setSize[x];
				if(rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
	int disjointSets(){
		return numSets;
	}
	int sizeOfSet(int n) {
		return setSize[findSet(n)];
	}
};


int main(){
	int n, m, i, j;
	int counter = 0;
	while(true){
		scanf("%d %d", &n, &m);
		counter++;
		if(n == 0 && m == 0){
			return 0;
		}

		UnionFind UF(n);

		for(int i1 = 0; i1 < m; i1++){
			scanf("%d %d", &i, &j);
			UF.unionSet(i-1,j-1);
		}
		int sets = UF.disjointSets();
		cout << "Case " << counter << ": " << sets << endl;
	}
	return 0;
}
