// Codeforces

/*
There are one cat, k mice, and one hole on a coordinate line. The cat is located at the point 0, the hole is located at the 
point n. All mice are located between the cat and the hole: the i-th mouse is located at the point xi (0<xi<n). At each point, 
many mice can be located.

In one second, the following happens. First, exactly one mouse moves to the right by 1. If the mouse reaches the hole, it hides 
(i.e. the mouse will not any more move to any point and will not be eaten by the cat). Then (after that the mouse has finished 
its move) the cat moves to the right by 1. If at the new cat's position, some mice are located, the cat eats them (they will not 
be able to move after that). The actions are performed until any mouse hasn't been hidden or isn't eaten.

In other words, the first move is made by a mouse. If the mouse has reached the hole, it's saved. Then the cat makes a move. The 
cat eats the mice located at the pointed the cat has reached (if the cat has reached the hole, it eats nobody).

Each second, you can select a mouse that will make a move. What is the maximum number of mice that can reach the hole without 
being eaten?
*/

/*
Input
The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

Each test case consists of two lines. The first line contains two integers n and k (2≤n≤109, 1≤k≤4⋅105). 
The second line contains k integers x1,x2,…xk (1≤xi<n) — the initial coordinates of the mice.

It is guaranteed that the sum of all k given in the input doesn't exceed 4⋅105.

Output
For each test case output on a separate line an integer m (m≥0) — the maximum number of mice that can reach 
the hole without being eaten.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntestcase, len, nmice, catPos, miceSaved, deadMice, nturn, elem; 
    vector<int> mousePos;

    cin >> ntestcase;

    while(ntestcase--){
        cin >> len;
        cin >> nmice;
        catPos = 0;
        miceSaved = 0;
        deadMice = 0;
        for(int i = 0; i < nmice; i++){
            cin >> elem;
            mousePos.push_back(elem);
        }
        sort(mousePos.begin(), mousePos.end(), greater<int>());
        nturn = len-1;
        for(int mp : mousePos){
            nturn -= (len - mp);
            catPos += (len - mp);
            miceSaved += 1;
            if(nturn == 0)
                break;
            else if(nturn < 0){
                miceSaved--;
                break;
            }
        }
        mousePos.clear();
        cout << miceSaved << "\n";
    }
    return 0;
}

    
