// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         int left=0;
//         int ans=0;
//         unordred_map<int,int>mp;
//         for(int right=0;right<fruits.size(),right++){
//             mp[fruits[right]]++;
//             while(fruits.size()>2){
//                 mp[[fruits[left]--];
//                  if(mp[fruits[left]]==0){
//                 mp.erase[fruits[left]];
//             }
//               left++;
//             }
           
//           ans = max(ans, right - left + 1);
//         }
//           return ans;
//     }
// };
class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int left = 0;
        int ans = 0;

        unordered_map<int, int> mp;

        for (int right = 0; right < fruits.size(); right++) {

            // Add current fruit
            mp[fruits[right]]++;

            // If we have more than 2 fruit types
            while (mp.size() > 2) {

                mp[fruits[left]]--;

                // Remove fruit type completely
                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }

                left++;
            }

            // Current window length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};