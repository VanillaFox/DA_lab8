#include <iostream>
#include <vector>
#include <algorithm>
#include "func.h"

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