#include <bitset>
#include <iostream>

using namespace std;

bitset<1000005> bits;
/*
 * Not sure why I am having time limit problems
 * Changes made
 * Dropped the functions implemented directly
 * Instead of bitset rest()
 * Going to set each bit myself?
 *
 */

int main(){
	int n, m, s, e, r;
	bool conflict = false;
	while(true){
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0){
			break;
		}
		conflict = false;
		bits.reset();
		for(int i = 0; i < n; i++){
			scanf("%d %d", &s, &e);
			//returns true if a conflict returns false if no conflict
			if(!conflict){
				for(int i1 = s; i1 < e; i1++){
					if(bits.test(i1)){
						conflict = true;
						break;
					}
					bits.set(i1);
				}
			}
		}


		for(int i = 0; i < m; i++){
			/*Time Limit
			 * if(conflict){
				break;
			}
			 */
			scanf("%d %d %d", &s, &e, &r);
			//Works 6ms?
			if(!conflict){
				while(e <= 1000000){

					for(int i1 = s; i1 < e; i1++){
						if(bits.test(i1)){
							conflict = true;
							break;
						}
						bits.set(i1);
					}
					if(conflict){
						break;
					}
					s+=r;
					e+=r;
				}
			}

		}

		if(conflict){
			cout << "CONFLICT" << endl;
		}else{
			cout << "NO CONFLICT" << endl;
		}
	}
	return (0);
}
