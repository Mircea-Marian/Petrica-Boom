#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <queue>
#define getNext(a) (( ~( (( (~a) & mascaSobolanMort ) << 1) | (( (~a) & mascaSobolanMort ) >> 1) ) ) & mascaSobolanMort)
 
using namespace std;
 
int *dist;
 
struct LessThanComp
{
  bool operator()(const int& lhs, const int& rhs) const
  {
    return dist[lhs] > dist[rhs];
  }
};
 
void printBits(int val){
    int mask = 1 << 19;
    int a = 20;
    while(a--) {
        cout << ((val & mask) ? "1" : "0");
        mask /= 2;
    }
}
 
int main(){
 
    fstream file ("boom.in", ios::in);
 
    int N, M, i, a, b;
    file >> N >> M;
    int sarje[M][2], *itSarje = (int*)sarje, *itDist;
    const int mascaSobolanMort = (1 << N) - 1;
 
    i = mascaSobolanMort + 1;
 
    dist = new int [i];
    int *nrSarja = new int [i], *tata = new int [i];
    bool *visited = new bool [i], *itVisited;
 
 
    visited[0] = true;
    dist[0] = 0;
    priority_queue<int, std::vector<int>, LessThanComp> pq;
    itVisited = visited + 1;
    itDist = dist + 1;
    i--;
    while(i--) {
        *itVisited = false;
        *itDist = INT_MAX;
 
        itDist++;
        itVisited++;
    }
 
    itSarje = (int*)sarje;
    i = 0;
    while(i < M){
        file >> *itSarje >> a;
        itSarje++;
 
        *itSarje = 0;
        while(a--) {
            file >> b;
            *itSarje |= (1 << (b - 1));
        }
 
        //cout << i + 1 << " "; printBits(*itSarje); cout << " "; printBits(getNext(*itSarje)); cout << "\n";
 
        dist[*itSarje] = *(itSarje-1);
        tata[*itSarje] = 0;
        nrSarja[*itSarje] = i;
 
        pq.push(*itSarje);
        visited[*itSarje] = true;
 
        itSarje++;
        i++;
    }
    file.close();
 
    int nodId, j, c;
    while(!pq.empty()) {
        nodId = pq.top();
        pq.pop();
 
        //printBits(nodId); cout << " "; printBits(getNext(nodId)); cout << " " << dist[nodId] <<endl;
        //cout << nodId << " " << dist[nodId] << endl;
 
        if(nodId == mascaSobolanMort)
            break;
 
        itSarje = (int*)sarje;
        j = 0;
        c = getNext(nodId);
        while(j < M) {
            //itSarje     -> costul
            //itSarje + 1 -> masca
 
            b = c | (*(itSarje + 1));
            if(b && dist[b] > dist[nodId] + *itSarje){
                dist[b] = dist[nodId] + *itSarje;
                tata[b] = nodId;
                nrSarja[b] = j;
 
                //cout << *(itSarje + 1) << " " << dist[*(itSarje + 1)] << endl;
 
                if(!visited[b]){
                    pq.push(b);
                    visited[b] = true;
                }
            }
 
            itSarje+=2;
            j++;
        }
 
        // for(int mmm = 0 ; mmm <= mascaSobolanMort ; mmm++)
        //  cout << visited[mmm] << " ";
        // cout << endl;
    }
 
    file.open("boom.out", ios::out);
 
    file << dist[mascaSobolanMort] << endl;
    a = 0;
    nodId = mascaSobolanMort;
    while(nodId) {
        dist[a] = nrSarja[nodId];
        a++;
        nodId = tata[nodId];
    }
 
    file << a << endl;
 
    int *cc = dist;
 
    dist = dist + a - 1;
    while(a--) {
        file << *dist + 1 << endl;
        dist--;
    }
 
    file.close();
 
    delete[] cc;
    delete[] tata;
    delete[] nrSarja;
    delete[] visited;
}
