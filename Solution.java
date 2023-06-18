
import java.util.Arrays;

public class Solution {

    public int findRadius(int[] housePositions, int[] heaterPositions) {
        Arrays.sort(housePositions);
        Arrays.sort(heaterPositions);

        int minRadius = 0;
        int indexHeater = 0;

        for (int house : housePositions) {
            while (indexHeater + 1 < heaterPositions.length
                    && house - heaterPositions[indexHeater] > heaterPositions[indexHeater + 1] - house) {
                ++indexHeater;
            }
            minRadius = Math.max(minRadius, Math.abs(house - heaterPositions[indexHeater]));
        }

        return minRadius;
    }
}
