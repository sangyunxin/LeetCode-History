/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(const Interval& a, const Interval& b){
        // if(a.start == b.start)
        //     return a.end <= b.end;
        // else
            return a.start < b.start;
    }
    
    该方法超时
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.empty())
            return res;
        
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            if(vis[i] != 0)
                continue;
            
            Interval cur = intervals[i];
            
            for(int j = i+1; j < n; j++){
                if(vis[j] != 0)
                    continue;
                Interval next = intervals[j];
                if(next.start >= cur.start && next.start <= cur.end){
                    cur.end = max(cur.end, next.end);
                    vis[j] = 1;
                }

            }
            
            res.push_back(cur);
        }
        
        return res;
        
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.empty())
            return res;
        
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        res.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            if(res.back().end < intervals[i].start)
                res.push_back(intervals[i]);
            else
                res.back().end = max(res.back().end, intervals[i].end);
        }
        
        return res;
        
    }
};