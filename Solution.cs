
using System;

public class Solution
{
    public int FindRadius(int[] housePositions, int[] heaterPositions)
    {
        Array.Sort(housePositions);
        Array.Sort(heaterPositions);

        int minRadius = 0;
        int indexHeater = 0;

        foreach (int house in housePositions)
        {
            while (indexHeater + 1 < heaterPositions.Length
                    && house - heaterPositions[indexHeater] > heaterPositions[indexHeater + 1] - house)
            {
                ++indexHeater;
            }
            minRadius = Math.Max(minRadius, Math.Abs(house - heaterPositions[indexHeater]));
        }

        return minRadius;
    }
}
