class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
         
        int sz = numbers.size();
        if(sz != 5)
            return false;
        int j = 0;
        for(j=0; j<sz; j++)
        {
            int ret = j-1;
            while(ret>=0)
            {
                if(numbers[ret]>numbers[ret+1])
                {
                    int tmp =numbers[ret+1];
                    numbers[ret+1] = numbers[ret];
                    numbers[ret] = tmp;
                    
                }
                ret--;
            }
           }
           
        int king = 0;
        int sum = 0;
     // sort(numbers.begin(),numbers.end());
        for (int i = 0; i < sz-1; i++)
        {
          
            if(numbers[i] == 0)
            {
                king++;
                continue;
            }
             if(numbers[i] == numbers[i+1])
                return false;
                 sum += numbers[i+1]-numbers[i]-1;;
           
            
        }
        if(king >=sum )
        {
            return true;
        }

            return false;
    }
};