#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <thread>
#include <mutex>

std::mutex mtx;
int tmp = 1;

void processCar(int car, int direction, int time, std::map<int, int>& road) {
    std::lock_guard<std::mutex> lock(mtx);
    if ((direction == 1 || direction == 2) && tmp == 1) {
        tmp = 0;
        std::cout << "Traffic Light on road A is green\n";
        road.clear();
    } else if ((direction == 3 || direction == 4) && tmp == 0) {
        tmp = 1;
        std::cout << "Traffic Light on road B is green\n";
        road.clear();
    }
    road[time]++;
    if (road[time] > 2) {
        std::cout << "Road in direction " << direction << " is full!\n IMPOSIBLE!!!\n";
        exit(-1);
    }
    std::cout << "Car " << car << " passed in direction " << direction << "\n";
}

int main(){
    std::vector<int> cars = {1, 3, 5, 2, 4}, D = {2, 1, 2, 4, 3}, T = {10, 20, 30, 40, 40};
    std::map<int, int> d1, d2, d3, d4;
    std::vector<std::thread> threads;

    std::vector<std::pair<int, int>> times;
    for (int i = 0; i < T.size(); i++) {
        times.push_back({T[i], i});
    }

    std::sort(times.begin(), times.end());

    for (const auto& t : times) {
        int i = t.second;
        if (D[i] == 1 || D[i] == 2) {
            threads.push_back(std::thread(processCar, cars[i], D[i], T[i], std::ref(d1)));
        } else if (D[i] == 3 || D[i] == 4) {
            threads.push_back(std::thread(processCar, cars[i], D[i], T[i], std::ref(d2)));
        }
    }

    for (auto& th : threads) th.join();

    return 0;
}
