#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,list<int> > l;
int cnt = 0;
std::vector<int> v;
void addEdge(int x,int y){
	l[x].push_back(y);
	l[y].push_back(x);
}


void dfs_helper(int src,map<int,bool> &visited){
    visited[src]  = true;
    cnt++;
    //cout << src <<" ";
    for(auto x: l[src]){
    	if(!visited[x]){
    		dfs_helper(x,visited);
    	}
    }
}
void dfs(){
	map<int,bool> visited;
    map<int,int > c;
	int i = 0;
	for(auto x:l){
		if(!visited[x.first]){
            i++;
			dfs_helper(x.first,visited);
            //cout << "i is "<<i <<" cnt is "<<cnt <<"\n";
            v.push_back(cnt);
		}
        c[i] = cnt;
        cnt = 0;
	}
     
}

int main(){
	int n,p;
	cin >> n >> p;
	while(p--){
		int x, y;
		cin >> x >> y;
		addEdge(x,y);
	}
   dfs();

   ll val = n*(n-1)/2;

   for(auto x:v){
       int vali= x*(x-1)/2;
        val = val - vali;
   }
   cout << val <<"\n";
}