
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    
public:
    int findRadius(vector<int>& housePositions, vector<int>& heaterPositions) const {

        //C++20: std::ranges::sort(housePositions)
        //       std::ranges::sort(heaterPositions)
        sort(housePositions.begin(), housePositions.end());
        sort(heaterPositions.begin(), heaterPositions.end());

        int minRadius = 0;
        int indexHeater = 0;

        for (const auto& house : housePositions) {
            while (indexHeater + 1 < heaterPositions.size()
                    && house - heaterPositions[indexHeater] > heaterPositions[indexHeater + 1] - house) {
                ++indexHeater;
            }
            minRadius = max(minRadius, abs(house - heaterPositions[indexHeater]));
        }

        return minRadius;
    }
};
