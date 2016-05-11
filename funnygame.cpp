//============================================================================
// Name        : funnygame.cpp
// Author      : Mateo A Zabala G
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    int N,raiz;
    scanf("%d %d",&N,&raiz);
    --raiz;
    
    vector<int> max[1000];
    
    for(int i = 1,a,b; i<N; ++i){
        scanf("%d %d",&a,&b);
        --a; --b;
        max[a].push_back(b);
        max[b].push_back(a);
    }
    
    int airp[1000],end = 0,hijos[1000];
    memset(hijos,-1,sizeof(hijos));
    
    airp[end] = raiz; ++end;
    hijos[raiz] = -2;
    
    for(int i = 0;i<N;++i){
        int ac = airp[i];
        
        for(int j = max[ac].size()-1;j>=0;--j){
            int next = max[ac][j];
            
            if(hijos[next]==-1){
                airp[end] = next; ++end;
                hijos[next] = ac;
            }
        }
    }
    
    bool win[1000];
    
    for(int i = N-1;i>=0;--i){
        int ac = airp[i];
        win[ac] = false;
        
        for(int j = max[ac].size()-1;j>=0;--j){
            int next = max[ac][j];
            
            if(hijos[next]==ac && !win[next])
                win[ac] = true;
        }
    }
    
    if(!win[raiz]) printf("First player loses\n");
    else{
        int selec = N+1;
        
        for(int i = max[raiz].size()-1;i>=0;--i){
            int next = max[raiz][i];
            
            if(hijos[next]==raiz && !win[next] && next<selec)
                selec = next;
        }
        
        printf("First player wins flying to airport %d\n",selec+1);
    }
    return 0;
}
