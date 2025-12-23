class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        int c1 = 0;
        int c2 = height.size() - 1;
        while (c1 < c2)
        {
            int h = min(height[c1], height[c2]);
            int width = c2 - c1;
            int area = h * width;
            max_area = max(max_area, area);

            if (height[c1] < height[c2])
            {
                c1++;
            }
            else
            {
                c2--;
            }
        }
        return max_area;
    }
};