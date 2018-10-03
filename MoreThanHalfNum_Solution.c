class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    
        int sz = numbers.size();
        int array[100] ={0};
        
        int i = 0;
        int index = 0;
       if(sz<=1)
           return numbers[0];
        for(i = 0; i<sz; i++)
        {
            int ret = numbers[i];
            array[ret]++;
        }
        
        for(index = 0; index < 100;index++)
        {
            
            if(array[index]>sz/2)
                return index;
            
            
        }
        return 0;
    }
};