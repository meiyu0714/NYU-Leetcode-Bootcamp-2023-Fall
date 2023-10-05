Python:

1. [217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)

```python
class Solution:
    def containDuplicate(self, nums: List[int]) -> bool:
        seen = set()
        for num in nums
           if num in seen
              return True
           seen.add(num)
        return false;
```

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> cur;
        for(int num: nums){
            if(cur.find(num) != cur.end()){
                return true;
            } else{
                cur.insert(num);
            }
        }
        return false;
    }
};
```

1. [11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/)

   ```c++
   class Solution {
   public:
       int maxArea(vector<int>& height) {
           int left = 0, right = height.size() -1, max_area = 0;
           while(left < right){
               int temp = min(height[left], height[right]) * (right - left);
               max_area = max(temp, max_area);
               if(height[left] < height[right]) left++;
               else right--;
           }
           return max_area;
       }
   };
   ```

```python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        max_area = 0

        while left < right:
            temp = min(height[left], height[right]) * (right - left)
            max_area = max(temp, max_area)
            if height[left] < height[right]:
                left += 1
            else: right -= 1

        return max_area        
```



1. [239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)

```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) return nums;
        vector<int> ans;
        priority_queue<pair<int, int>> curr;
        for(int i = 0; i < k; i++){
            curr.push({nums[i], i});
        }
        ans.push_back(curr.top().first);
        for(int i = k; i < nums.size(); i++){
            //这里的i是right
            curr.push({nums[i],i});
            while(curr.top().second <= i-k){//比最左边数值的下标还小
                curr.pop();
            }
            ans.push_back({curr.top().first});
        }
        return ans;
    }
};
```

```python
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        #python 默认为小根堆，c++默认大根堆（最大最上）
        q = [(-nums[i],i) for i in range(k)]
        heapq.heapify(q)

        ans = [-q[0][0]]
        for i in range(k,n):
            heapq.heappush(q, (-nums[i],i))
            while q[0][1] <= i - k:
                heapq.heappop(q)
            ans.append(-q[0][0])

        return ans        
```

