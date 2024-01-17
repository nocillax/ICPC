/*
Table of Contents: 

1. BST
2. DFS
3. 2D Grid
4. 

*/


// +_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+ BST +_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+

ll BST(ll arr[], ll sz, ll val){  
    ll left = 0;
    ll right = sz-1;
    while ( left <= right ){
        
        ll mid = (left + right) / 2;
    
        if(arr[mid] == val) return mid;

        else if(arr[mid] < val) {
            left = mid + 1;
        }
        else if(arr[mid] > val){
            right = mid - 1;
        }
    }
    return -1;
}
void NoCiLLaX(){

    ll sz; cin >> sz;
    ll arr[sz];

    for(ll i = 0; i < sz; i++){
        cin >> arr[i];
    }

    ll val; cin >> val;
    ll c = BST(arr, sz, val);
    cout << c << endl;
}

// +_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+ DFS +_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+

#define R 1000
vector <ll> G[R];
bool visited[R];
vector <ll> path;
stack <ll> st;
ll x = -1; 

void initGraph(vector <ll> v[R], ll x , ll y){
    v[x].push_back(y);
}

void graphInput(){ //input using adjacency list

    initGraph(G, 1, 2);
    initGraph(G, 1, 3);
    initGraph(G, 2, 1);
    initGraph(G, 2, 7);
    initGraph(G, 3, 1);
    initGraph(G, 3, 4);
    initGraph(G, 3, 5);
    initGraph(G, 4, 3);
    initGraph(G, 5, 3);
    initGraph(G, 5, 6);
    initGraph(G, 6, 5);
    initGraph(G, 7, 2);

}

void showGraphAdjacencyList(){
    for(int i = 0; i<=R ; i++){
        cout<<"["<<i<<"] = ";
        for(int j = 0; j<G[i].size(); j++){
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
}

void DFS(int sr){
    
    st.push(sr);
    while(!st.empty()){
        ll u = st.top();
        visited[u]=true;
        if(x == st.top()){
            path.push_back(x);
            st.pop();
        }
        else{
            for(int i=0; i<G[u].size(); i++){
                ll v = G[u][i];
                if(!visited[v]){
                    st.push(v);
                    break;
                }
            }
            x = u;
        }
    }
}

void showPath(){

    reverse(path.begin(), path.end());
    for(int i=0; i<path.size(); i++){
        cout<<path[i]<<" ";
    }
}

void NoCiLLaX(){

    graphInput();
    DFS(1);
    showPath();
}

// +_+_+_+_+_+_+_+_+_+_+_+_+_+_+ 2D GRID +_+_+_+_+_+_+_+_+_+_+_+_+_+_+

int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {0, 1, -1, 1, -1, 0, 1, -1};
ll m = 8, n = 8;    // Size of Grid

struct Mat{
    char ch;
    bool B;
    ll dist;
}matrix[10][10];    // Adust with Max possible value

ll BFS(ll startX, ll startY, ll destX, ll destY) {
    int cnt = 0;
    queue<PR> Q;
    Q.push({startX, startY});
    matrix[startX][startY].B = true;
    matrix[startX][startY].dist = 0;  // Distance from start to start is 0

    while (!Q.empty()) {
        PR v = Q.front();
        Q.pop();

        if (v.first == destX && v.second == destY) {
            // Destination reached
            return matrix[destX][destY].dist;
        }

        for (int i = 0; i < 8; i++) {
            ll r = v.first + dx[i];
            ll c = v.second + dy[i];

            if (r < 0 || c < 0 || r >= m || c >= n || matrix[r][c].B == true) continue;

            Q.push({r, c});
            matrix[r][c].B = true;
            matrix[r][c].dist = matrix[v.first][v.second].dist + 1;  // Update distance
            cnt++;
        }
    }

    // Destination not reachable
    return -1;
}

void showPath(ll destX, ll destY){
    vector<PR> path;
    PR val = mp(destX, destY);
    path.push_back(val);
    
    while(matrix[destX][destY].way != mpl(0,0)){
        val = matrix[destX][destY].way;
        path.push_back(val);
        destX = val.first;
        destY = val.second;
    }
    reverse(path.begin(), path.end());
    
    for(ll i = 0; i < path.size(); i++){
        cout<<path[i].first<<", "<<path[i].second<<nl;
    }
}

void NoCiLLaX(){

    cout<< BFS(0, 0, 7, 7) << nl;
    showPath(7,7)<<nl;
}
