class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        int start = 0;
        int end = height.size() - 1;

        while (start < end)
        {
            int h = min(height[start], height[end]);
            int width = end - start;
            int area = h * width;
            max_area = max(max_area, area);

            if (height[start] < height[end])
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return max_area;
    }
};