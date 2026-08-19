class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMasks;

        // Step 1: Record reserved seats 2 through 9 as bitmasks
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 9) {
                rowMasks[row] |= (1 << (col - 2));
            }
        }

        // Step 2: Unreserved rows automatically add 2 groups each
        int totalGroups = (n - rowMasks.size()) * 2;

        // Bitmasks for the 3 potential seating blocks
        int leftMask   = 0b00001111; // seats 2, 3, 4, 5
        int middleMask = 0b00111100; // seats 4, 5, 6, 7
        int rightMask  = 0b11110000; // seats 6, 7, 8, 9

        // Step 3: Process only rows that contain reservations
        for (const auto& [row, mask] : rowMasks) {
            bool left   = (mask & leftMask) == 0;
            bool right  = (mask & rightMask) == 0;
            bool middle = (mask & middleMask) == 0;

            if (left && right) {
                totalGroups += 2;
            } else if (left || right || middle) {
                totalGroups += 1;
            }
        }

        return totalGroups;
    }
};