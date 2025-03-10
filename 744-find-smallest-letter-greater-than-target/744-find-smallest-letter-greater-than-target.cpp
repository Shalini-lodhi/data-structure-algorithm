class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
     int start=0,end=letters.size()-1;
        char ans=letters[start];
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(letters[mid]>target)
            {
                ans=letters[mid];
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
};