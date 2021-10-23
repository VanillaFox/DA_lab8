#include<iostream>
#include<vector>

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

std::pair<std::vector<int>, int> NaivAlgo(std::vector<int> freepos, int N, int start, std::vector<std::vector<double>>& matrix){
    std::pair<std::vector<int>, int> pairs;
    std::vector<int> curfree, res, curres;
    int sum = 100000;
    if(start == N){
        return std::make_pair(res, 0);
    }
    for(int j = 0; j < freepos.size(); j++){
        if(matrix[freepos[j]][start]){
            curfree = freepos;
            std::vector<int>::iterator it = curfree.begin()+j;
            curfree.erase(it);
            pairs = NaivAlgo(curfree, N, start+1, matrix);
            pairs.first.push_back(freepos[j]);
            if(sum > pairs.second + matrix[freepos[j]][N]){
                sum = pairs.second + matrix[freepos[j]][N];
                res = pairs.first;
            }
        }
    }
    return std::make_pair(res, sum);
}