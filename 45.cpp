// //1
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >>n;
    int ma[100][100];
    for (int i =0;i<n;i++){
        for (int j=0;j<n;j++){
            if (j<n-1-i){
                ma[i][j]=0;
            }
            else{
                if (j==n-1-i){
                    ma[i][j]=1;
                }else{
                    ma[i][j]=2;
                }
            }
            cout<< ma[i][j]<<" ";
        }
        cout <<endl;
    }

    return 0;
}

//2
#include <iostream>

using namespace std;

int main() {
    int n,m,w;
    cin >>n>>m;
    cin>>w;
    int grib[32][32]={0};
    int dx[]={-1,-1,-1,0,1,1,1,0};
    int dy[]={-1,0,1,1,1,0,-1,-1};
    for (int i =0;i<w;++i){
        int x,y;
        cin >> x >>y;
        --x;
        --y;
        grib[x][y] = -1; //ввели грибы в массив
        for (int j = 0;j<8;++j){
            int nx = x+dx[j];
            int ny = y+dy[j];
            if (nx >= 0 && nx < n && ny >= 0 && ny<m &&grib[nx][ny]!=-1){
                grib[nx][ny]++;
            }

        }
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (grib[i][j]==-1){
                cout<<"*";
            }else{
                cout <<grib[i][j];
            }
        }
        cout<<endl;
    }
    return 0;
}

//3

#include <iostream>

using namespace std;
int main() {
    int x,n;
    cin >> x >> n;
    char posledovatelnost[25][10000];
    posledovatelnost[0][0]='0'+x;
    posledovatelnost[0][1]='\0';
    for (int i=1;i<n;++i){
        int pos = 0;
        int count = 1;
        for (int j =1;posledovatelnost[i-1][j-1]!='\0';++j){
            if (posledovatelnost[i-1][j]==posledovatelnost[i-1][j-1]){
                count++;
            }else{
                posledovatelnost[i][pos++]='0'+count;
                posledovatelnost[i][pos++]=posledovatelnost[i-1][j-1];
                count = 1;
            }
        }
        posledovatelnost[i][pos]='\0';
    }
    cout <<posledovatelnost[n-1]<<endl;

    return 0;
}