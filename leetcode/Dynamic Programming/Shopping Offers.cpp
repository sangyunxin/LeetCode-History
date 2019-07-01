class Solution
{
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        int res = inner_product(price.begin(), price.end(), needs.begin(), 0);
        for (auto offer : special)
        {
            vector<int> nneeds = helper(offer, needs);
            if (nneeds.empty())
                continue;
            res = min(res, shoppingOffers(price, special, nneeds) + offer.back());
        }
        return res;
    }

    vector<int> helper(vector<int> &offer, vector<int> &needs)
    {
        vector<int> r(needs.size(), 0);
        for (int i = 0; i < needs.size(); ++i)
        {
            if (offer[i] > needs[i])
                return {};
            r[i] = needs[i] - offer[i];
        }
        return r;
    }
};