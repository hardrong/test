class Solution {
public:
    int GetUglyNumber_Solution(int index) {

   if (index < 1)
        return NULL;
 
    int minVal = 0;
    queue<int> q2, q3, q5;
    q2.push(1);
 
    for (int i = 0; i < index; i++)
    {
        int val2 = q2.empty() ? INT_MAX : q2.front();
        int val3 = q3.empty() ? INT_MAX : q3.front();
        int val5 = q5.empty() ? INT_MAX : q5.front();
 
        minVal = min(val2, min(val3, val5));
 
        if (minVal == val2)
        {
            q2.pop();
            q2.push(2 * minVal);
            q3.push(3 * minVal);
        }
        else if (minVal == val3)
        {
            q3.pop();
            q3.push(3 * minVal);
        }
        else
        {
            q5.pop();
        }
 
        q5.push(5 * minVal);
    }
 
    return minVal;
        
    }
};