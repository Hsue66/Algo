#include<stdio.h>

#define INF 987654321
#define MAX 90000

int Min,N;
int MAP[100][100],v[100][100];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

struct Node{
    int x, y;
};

struct Queue{
    int fidx;
    int bidx;
    Node node[MAX];

    void init(){
        fidx = bidx = 0;
    }
    int empty(){
        return fidx == bidx;
    }
    void push(int a,int b){
        bidx = (bidx+1)%MAX;
        node[bidx].x = a;
        node[bidx].y = b;
    }
    void pop(){
        fidx++;
    }
    Node front(){
        return node[fidx+1];
    }
};

void init(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            v[i][j] = INF;
    }
}

int min(int a, int b){
    if(a < b)
        return a;
    else
        return b;
}

int main(){
    int testcase;
    scanf("%d",&testcase);
    for(int tc =0 ; tc<testcase; tc++){
        scanf("%d",&N);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++)
                scanf("%1d",&MAP[i][j]);
        }
        init();
        Min = INF;
        Queue q;
        q.init();
        q.push(0,0);
        v[0][0] = 0;
        while(!q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            q.pop();
            for(int i=0; i<4; i++){
                int tx = x+dir[i][0];
                int ty = y+dir[i][1];
                if(0<=tx && tx <N && 0<=ty && ty <N ){
                    int tmp = v[x][y]+MAP[tx][ty];
                    if(tmp < v[tx][ty]){
                        v[tx][ty] = tmp;
                        if(tmp < Min)
                            q.push(tx,ty);
                    }
                }
            }
        }
        printf("#%d %d\n",tc+1,v[N-1][N-1] );
    }
}
