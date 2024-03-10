#ifndef DEBUG_H // START DEBUG_H
#define DEBUG_H

#include <bits/stdc++.h>
using namespace std;

// #define debugList(A)          	cerr << "? " << #A << ": "; bool band = 0; cerr << "[ ";  for(auto x : A) { if(!band) cerr << x , band = 1; else cerr << " , " << x ;} cerr << " ]" << endl;
#define debugPair(a,b)          cerr << "?? " << #a << " : " << a << " | " << #b << " : " << b << endl; 
#define debugIterablePairs(P) 	qwer cerr << "? " << #P << " : "; cerr << "{ " << endl; for(auto it : P) { cerr << "    " << it.first << " -> " << it.second << endl; } cerr << "} " << endl; qwer 
#define debugGraph(GP)          cerr << "? " << #GP << " = "; cerr << "{ " << endl; int cntNodes = 0; for(vi adj : GP) { if(adj.size()) { cerr << "   "; cerr << cntNodes << " => "; debugList(adj) } cntNodes ++;} cerr << "}" << endl;
#define debugGraphWeight(GP) 	qwer cerr << "? " << #GP << " = {" << endl; int cntNodes = 0; for(auto it : GP ){ if( it.size() ){ cerr << cntNodes << " => [ "; for(auto iter : it){ cerr << iter.fi << "-w{" << iter.se << "} "; } cerr << "]" << endl; } cntNodes++; } qwer

#define debugVar(A) cerr << "? " << #A << ": "; imprimeVar(A);
template<typename T>
void imprimeVar(T A){
    cerr << (A) << '\n';
}

#define debugList(A) cerr << "? " << #A << ": "; imprimeList(A);
template<typename T>
void imprimeList(T A){
    bool band = 0;
    cerr << "[ ";
    for(auto x : A) { 
        if(!band) cerr << x , band = 1; 
        else cerr << " , " << x ;
    }
    cerr << " ]" << endl;
}

#endif // DEBUG_H