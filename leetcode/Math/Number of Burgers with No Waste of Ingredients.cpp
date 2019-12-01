class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices % 2 != 0 || tomatoSlices < 2 * cheeseSlices || tomatoSlices > 4 * cheeseSlices)
            return {};
        return {(tomatoSlices / 2) - cheeseSlices, 2 * cheeseSlices - (tomatoSlices / 2)};
    }
};