#include <iostream>
#include <vector>
#include <algorithm>

void Gauss(std::vector<std::vector<double>>& vec, std::vector<double>& res, int& N, int& M){
    int cost = N;
    for(int i = 0; i < N; i++){
        int rowNum, row = -1;
        int minCost = 51;
        for(int j = i; j < M; j++){
            if(vec[j][i] != 0 && vec[j][cost] < minCost){
                minCost = vec[j][cost];
                row = j;
            }
        }

        if(row == -1){
            res.clear();
            return;
        }

        rowNum = vec[row][cost+1];

        res.push_back(rowNum);
        vec[i].swap(vec[row]);

        for(int j = i + 1; j < M; j++){
            double k = vec[j][i] / vec[i][i];
            for(int l = i; l < N; l++){
                vec[j][l] -= vec[i][l] * k;
            }
        }
    }
}


int main(){
    int M, N;
    int p;
    std::cin >> M >> N;
    std::vector<std::vector<double>> coefs;
    std::vector<double> cur;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N+1; j++){
            std::cin >> p;
            cur.push_back(p);
        }
        cur.push_back(i+1);
        coefs.push_back(cur);
        cur.clear();
    }
    Gauss(coefs, cur, N, M);

    if(cur.empty()){
        std::cout << -1 << std::endl;
    }
    else{
        std::sort(cur.begin(), cur.end());
        std::cout << *cur.begin();
        for(std::vector<double>::iterator it = cur.begin() + 1; it != cur.end(); it++){
            std::cout << " " << *it;
        }
        std::cout << std::endl;
    }
}