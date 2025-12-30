class Solution
{
public:
        vector<int> sortArray(vector<int> &nums)
        {
                priority_queue<int, vector<int>, greater<int>> min_heap;

                for (int el : nums)
                {
                        min_heap.push(el);
                }
                vector<int> ans;
                for (int i = 0; i < nums.size(); i++)
                {
                        ans.push_back(min_heap.top());
                        min_heap.pop();
                }
                return ans;
        }
};