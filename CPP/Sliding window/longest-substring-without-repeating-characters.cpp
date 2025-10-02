#include <bits/stdc++.h>
using namespace std;
/**
 * Problem: Longest Substring Without Repeating Characters
 *
 * This solution uses the "Sliding Window" technique along with an
 * unordered map (hash map) to efficiently find the length of the
 * longest substring without repeating characters.
 */
class Solution {
public:
    /**
     * Finds the length of the longest substring without repeating characters.
     *
     * @param s The input string.
     * @return The length of the longest substring without repeating characters.
     */
    int lengthOfLongestSubstring(string s) {
        // Handle the edge case for an empty string.
        if (s.size() == 0) return 0;

        // 'mp' will store the frequency of characters in the current window (i to j).
        // Key: character (char), Value: count (int).
        unordered_map<char, int> mp;

        // 'i' is the start (left) of the window, 'j' is the end (right) of the window.
        int i = 0, j = 0;
        // 'ans' stores the maximum length found so far.
        int ans = 0;

        // Iterate through the string, expanding the window with 'j'.
        while (j < s.size()) {
            // 1. Expand the window to the right: Add the new character s[j].
            mp[s[j]]++;

            // Check the current window: The substring from s[i] to s[j] is j-i+1 characters long.

            // 2. Case 1: All characters in the window are unique.
            // If the number of unique characters (mp.size()) is equal to the window size (j-i+1),
            // we have a valid non-repeating substring. Update the max length.
            if (mp.size() == j - i + 1) {
                ans = std::max(ans, j - i + 1);
            }
            // 3. Case 2: There are repeating characters in the window.
            // If mp.size() is less than j-i+1, at least one character is repeated.
            else if (mp.size() < j - i + 1) {
                // Shrink the window from the left by moving 'i' until the repetition is gone.
                while (mp.size() < j - i + 1) {
                    // Remove the character at the left end of the window (s[i]).
                    mp[s[i]]--;

                    // If the count of s[i] drops to 0, it's no longer present in the window.
                    // Remove it from the map to maintain the accurate unique character count (mp.size()).
                    if (mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }

                    // Move the left pointer 'i' to the right to shrink the window.
                    i++;
                }
                // Note: After shrinking, the window is valid again, but we don't update 'ans' here
                // because a smaller valid window can't be the longest. The expansion step (j++)
                // will eventually lead to a new max length.
            }
            // Move the right pointer 'j' to expand the window again in the next iteration.
            j++;
        }

        // Return the final maximum length found.
        return ans;
    }
};

// ---
// ## Main Function for Testing
// ---

int main() {
    Solution sol;

    // Test Case 1: Simple longest substring
    std::string s1 = "abcabcbb";
    int result1 = sol.lengthOfLongestSubstring(s1);
    std::cout << "Input: \"" << s1 << "\" | Longest Substring Length: " << result1 << " (Expected: 3)\n";

    // Test Case 2: All repeating characters
    std::string s2 = "bbbbb";
    int result2 = sol.lengthOfLongestSubstring(s2);
    std::cout << "Input: \"" << s2 << "\" | Longest Substring Length: " << result2 << " (Expected: 1)\n";

    // Test Case 3: Longest substring at the end
    std::string s3 = "pwwkew";
    int result3 = sol.lengthOfLongestSubstring(s3);
    std::cout << "Input: \"" << s3 << "\" | Longest Substring Length: " << result3 << " (Expected: 3)\n";

    // Test Case 4: Empty string
    std::string s4 = "";
    int result4 = sol.lengthOfLongestSubstring(s4);
    std::cout << "Input: \"" << s4 << "\" | Longest Substring Length: " << result4 << " (Expected: 0)\n";

    // Test Case 5: Complex case
    std::string s5 = "dvdf";
    int result5 = sol.lengthOfLongestSubstring(s5);
    std::cout << "Input: \"" << s5 << "\" | Longest Substring Length: " << result5 << " (Expected: 3)\n";

    // Test Case 6: Longest possible
    std::string s6 = "abcdefgh";
    int result6 = sol.lengthOfLongestSubstring(s6);
    std::cout << "Input: \"" << s6 << "\" | Longest Substring Length: " << result6 << " (Expected: 8)\n";

    return 0;
}