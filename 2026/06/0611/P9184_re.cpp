#include <bits/stdc++.h>
using namespace std;

const string A = "noun";
const string B1 = "transitive-verb";
const string B2 = "intransitive-verb";
const string C = "conjunction";

map<string, queue<string>> words;

void print(string X){
    if (words[X].empty()){
        cout << "NNNNN";
        return;
    }
    string temp = words[X].front();
    cout << temp;
    words[X].pop();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--){
        words.clear();

        int N, c, P;
        cin >> N >> c >> P;
        for (int i = 0; i < N; i++){
            string s, op;
            cin >> s >> op;
            words[op].push(s);
        }

        int maxwordscount = 0;
        int x1, x2, x3, x4, douhao;
        for (int v1 = words[B1].size(); v1 >= 0; v1--){
            for (int v2 = words[B2].size(); v2 >= 0; v2--){
                int SVO = v1*2 + v2;
                int sentences = v1+v2;
                int surplusNoun = words[A].size() - SVO;
                if (SVO > words[A].size()) continue;

                int conj = min(min(sentences/2, (int)words[C].size()), P); //贪心取最大
                int extranoun = min(surplusNoun, c);
                if (v1 == 0) extranoun = 0; //没有及物动词不能使用逗号
                if (v1 + v2 - conj > P) continue;

                int sum = SVO + v1 + v2 + extranoun + conj;
                if (maxwordscount <= sum){
                    maxwordscount = sum;
                    x1 = SVO + extranoun;
                    x2 = v1;
                    x3 = v2;
                    x4 = conj;
                    douhao = extranoun;
                }
            }
        }
        cout << maxwordscount << endl;

        int multisentences = x4;
        int needP = x2 + x3 - multisentences;
        for (int i = 0; i < multisentences * 2; i++){
            if (i != 0) cout << " ";
            print(A);
            cout << ' ';
            if (x2 > 0){//输出及物句
                print(B1);
                cout << ' ';
                while (douhao > 0){
                    print(A);
                    cout << ", ";
                    douhao--;
                }print(A);
                x2--;
            }
            else{//输出不及物句
                print(B2);
            }
            
            if (i % 2 == 0){
                cout << " ";
                print(C);
            }
            else{
                cout << ".";
            }
        }
        for (int i = multisentences; i < needP; i++){
            if (i != 0) cout << " ";
            print(A);
            cout << ' ';
            if (x2 > 0){
                print(B1);
                cout << ' ';
                while (douhao > 0){
                    print(A);
                    cout << ", ";
                    douhao--;
                }print(A);
                x2--;
            }
            else{
                print(B2);
            }
            cout << ".";
        }
        cout << endl;
    }
    return 0;
}