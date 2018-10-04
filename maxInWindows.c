class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int>array;
        int plow = 0;
        int phight = size-1;
        if(num.size() <= 0)
            return array;
        if(size > num.size())
            return array;
        while(phight < num.size())
        {
                int max = plow;
                for(int i = plow; i<= phight; i++)
                {
                    if(num[i] > num[max])
                        max = i;
                 }
                array.push_back(num[max]);
                phight++;
                plow++;
        }
        return array;
    }
};