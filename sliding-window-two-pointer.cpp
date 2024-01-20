#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <limits>
#include <vector>
using namespace std;

// Short function start-->>
void printArray(int arr[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << arr[i] << " ";
    }
}
void printVector(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
}
void printVectorString(vector<string> &arr)
{
    for (auto it : arr)
    {
        cout << it << endl;
    }
}
void printVectorVector(vector<vector<int>> x)
{
    for (const auto &row : x)
    {
        cout << "[";
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "]";
        cout << std::endl;
    }
}
void printVectorVectorString(vector<vector<string>> x)
{
    for (const auto &row : x)
    {
        cout << "[";
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "]";
        cout << std::endl;
    }
}
void printString(string s, int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << s[i] << " ";
    }
}
void printStack(stack<string> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// Short function end-->>
/*

Li'll Interoduction----->>>
1️⃣ How to define its sliding window?
-->> Input given array or string and output related to subarray or substring along with can be attach largest,maximum or minimum and K that is window size.
If all this actions are there then it can be solve using sliding window.
2️⃣ Types of sliding window?
--->> 1) Fixed size window : You are given window size like K
 2) variable size window : you need to return window size subject to some condition
3️⃣  Fixed size window formet--->>
i=0,j=0;
while(j<size){
    1st step-->>
        calculation
    2nd step---->>
    if(j-i+1<k){
        j++;
    }
    3rd step---->>
    if(j-i+1==k){
        ans calculation.
        slide the window =remove the calculation and j++,i++
    }

}
    return ans;
4️⃣  Variable size window formet--->>
i=0,j=0;
while(j<size){
    1st step-->>
        calculation
    2nd step---->>
    condition is not given so think it
    if(condition<k){
        j++;
    }
    3rd step---->>
    if(condition==k){
        ans calculation.
        j++;
    }
    4th step----->>
    else if(condition>k){
        while(condition>k){
            remove calculation for i
            i++;
        }
        j++;
    }
}
    return ans;





*/
// ==============================ADITYA VERMA PLAYLIST=====================================>>
/*
1.  Maximum sum of subarray with size K
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC : O(n)
// SC :O(1)
int maximumSumSubarray(vector<int> &arr, int n, int k)
{
    int i = 0, j = 0, sum = 0, ans = INT_MIN;
    while (j < n)
    {
        sum += arr[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans = max(sum, ans);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    return ans;
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
2. First -ve Int in every window of size k
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
vector<int> FirstNegativeInteger(int A[], int N, int K)
{
    int start = 0, end = 0;
    deque<int> ans;
    vector<int> res;
    while (end < N)
    {
        if (A[end] < 0)
        {
            ans.push_back(A[end]);
        }
        if (end - start + 1 < K)
        {
            end++;
        }
        else if (end - start + 1 == K)
        {
            if (ans.size() == 0)
            {
                res.push_back(0);
            }
            else
            {
                res.push_back(ans.front());
                if (A[start] < 0)
                    ans.pop_front();
            }
            start++;
            end++;
        }
    }
    return res;
}

// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
3. Count the occurences of anagrams
ANS : Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.
Input : txt = forxxorfxdofr pat = for  || Output : 3
*/
// Bruteforce ----------->
// TC :
// SC :

int countAnagrams(string s, string p)
{
    unordered_map<char, int> mp;
    int ans = 0;

    // storing the occ. of string p in the map
    for (auto &x : p)
    {
        mp[x]++;
    }

    int count = mp.size();
    int k = p.size();
    int i = 0, j = 0;

    while (j < s.size())
    {
        // calculation part
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
            {
                count--;
            }
        }

        // window length not achived yet
        if (j - i + 1 < k)
        {
            j++;
        }

        // window length achived, find ans and slide the window
        else if (j - i + 1 == k)
        {
            // finding the ans
            if (count == 0)
            {
                ans++;
            }
            if (mp.find(s[i]) != mp.end())
            {
                mp[s[i]]++;
                if (mp[s[i]] == 1)
                {
                    count++;
                }
            }

            // slide the window
            i++;
            j++;
        }
    }
    return ans;
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
4. Maximum of all subarrays of size k
ANS : Given an array of integers A.  There is a sliding window of size B which is moving from the very left of the array to the very right.
You can only see the w numbers in the window. Each time the sliding window moves
rightwards by one position. You have to find the maximum for each window.
Input :  The array A is [1 ,3, -1, -3, 5, 3, 6, 7], and B is 3. || Output : [3, 3, 5, 5, 6, 7]
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// Time Complexity: O(n)
// Space Complexity: O(max(k, n - k + 1))
vector<int> maxSlidingWindow(vector<int> &arr, int k)
{
    int n = arr.size();
    int i = 0, j = 0;
    deque<int> q;
    vector<int> ans;
    if (k > n)
    {
        ans.push_back(*max_element(arr.begin(), arr.end()));
        return ans;
    }
    while (j < n)
    {
        // Calculation
        while (!q.empty() && q.back() < arr[j])
            q.pop_back();

        q.push_back(arr[j]);

        // If Window is fixed
        if (j - i + 1 == k)
        {
            // Ans from calculation
            ans.push_back(q.front());
            // Remnove calculation and slide the window
            if (q.front() == arr[i])
                q.pop_front();
            i++;
        }
        j++;
    }
    return ans;
}
// Optimal ---------->
// TC :
// SC :

/*
5. Length of Longest Subarray With at Most K Frequency
ANS : Given an array containing N positive integers and an integer K. Your task is to find the length of the longest Sub-Array with sum of the elements equal to the given value K.
Input :  nums = [4, 1 ,1, 1, 2, 3 ,5], k = 5 || Output : 4
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
int maxSubarrayLength(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0, j = 0;
    int ans = 0;
    long long sum = 0;

    while (j < n)
    {
        sum += nums[j];

        while (sum > k)
        {
            sum -= nums[i];
            i++;
        }

        if (sum == k)
        {
            ans = std::max(ans, j - i + 1);
        }

        j++;
    }

    return ans;
}
// Optimal ---------->
// TC :
// SC :

/*
6. Longest substring with k unique characters
ANS : Given a string you need to print the size of the longest possible substring that has exactly k unique characters.
Input : S = "aabacbebebe", K = 3 || Output :7
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
int longestKSubstr(string s, int k)
{
    int i = 0, j = 0;
    int n = s.size();
    int maxi = INT_MIN;
    map<char, int> mpp;
    while (j < n)
    {
        // 1st step-- >>
        // calculation
        mpp[s[j]]++;
        // 2nd step-- -- >>
        // condition is not given so think it if (condition < k)
        if (mpp.size() < k)
        {
            j++;
        }
        // 3rd step-- -- >>
        //     if (condition == k)
        else if (mpp.size() == k)
        {
            // ans calculation.
            maxi = max(maxi, j - i + 1);
            j++;
        }
        // 4th step-- --->>
        //     else if (condition > k)
        else if (mpp.size() > k)

        {
            while (mpp.size() > k)
            {
                // remove calculation for i
                mpp[s[i]]--;
                if (mpp[s[i]] == 0)
                    mpp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return maxi;
}
// Optimal ---------->
// TC :
// SC :

/*
7. Longest Substring Without Repeating Characters
ANS : Given a string s, find the length of the longest substring without repeating characters.
Input : s = "abcabcbb"  || Output :3
*/
// Bruteforce ----------->
// TC : O(n^2)
// SC :O(n)
int lengthOfLongestSubstringBruteforce(string str)
{

    if (str.size() == 0)
        return 0;
    int maxans = INT_MIN;
    for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
    {
        unordered_set<int> set;
        for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
        {
            if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
            {
                maxans = max(maxans, j - i);
                break;
            }
            set.insert(str[j]);
        }
    }
    return maxans;
}
// Better ----------->
// Time Complexity: O(N)
// Space Complexity: O(N)
int lengthofLongestSubstringBetter(string s)
{
    vector<int> mpp(256, -1);

    int left = 0, right = 0;
    int n = s.size();
    int len = 0;
    while (right < n)
    {
        if (mpp[s[right]] != -1)
            left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
    }
    return len;
}
// Optimal ---------->
// Time Complexity: O(N)
// Space Complexity: O(min(N, M))
int lengthOfLongestSubstringOptimal(string s)
{
    int i = 0, j = 0;
    int n = s.size();
    int maxi = INT_MIN;
    map<char, int> mpp;
    while (j < n)
    {
        // 1st step-- >>
        // calculation
        mpp[s[j]]++;
        // 2nd step-- -- >>
        // condition is not given so think it if (condition < k)
        if (mpp.size() > j - i + 1)
        {
            j++;
        }
        // 3rd step-- -- >>
        //     if (condition == k)
        else if (mpp.size() == j - i + 1)
        {
            // ans calculation.
            maxi = max(maxi, j - i + 1);
            j++;
        }
        // 4th step-- --->>
        //     else if (condition > k)
        else if (mpp.size() < j - i + 1)

        {
            while (mpp.size() < j - i + 1)
            {
                // remove calculation for i
                mpp[s[i]]--;
                if (mpp[s[i]] == 0)
                    mpp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return maxi;
}

/*
8. Pick toys
ANS : John is at a toy store help him pick maximum number of toys. He can only select in a continuous manner and he can select only two types of toys.
Input : s="abaccab"  || Output : 4
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
int toysPicked(string s)
{
    int i = 0, j = 0;
    int n = s.size();
    int k = 2; // we need 2 types toys so
    int maxi = INT_MIN;
    map<char, int> mpp;
    while (j < n)
    {
        // 1st step-- >>
        // calculation
        mpp[s[j]]++;
        // 2nd step-- -- >>
        // condition is not given so think it if (condition < k)
        if (mpp.size() < k)
        {
            j++;
        }
        // 3rd step-- -- >>
        //     if (condition == k)
        else if (mpp.size() == k)
        {
            // ans calculation.
            maxi = max(maxi, j - i + 1);
            j++;
        }
        // 4th step-- --->>
        //     else if (condition > k)
        else if (mpp.size() > k)

        {
            while (mpp.size() > k)
            {
                // remove calculation for i
                mpp[s[i]]--;
                if (mpp[s[i]] == 0)
                    mpp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return maxi;
}
// Optimal ---------->
// TC :
// SC :

/*
9. Minimum window substring
ANS : Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".
Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.
Input : s="ADOBECODEBANC",t="ABC"  || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :O(N)
// SC :O(T)
string minWindow(string s, string t)
{
    // Create a map to store the frequency of characters in string t
    unordered_map<char, int> mp;

    // Variables to track the minimum window length and its starting index
    int minlen = INT_MAX, start = 0;

    // Populate the map with the frequency of characters in string t
    for (auto ch : t)
    {
        mp[ch]++;
    }

    // Pointers i and j to traverse the string
    int i = 0, j = 0;

    // Count to keep track of characters from string t that are yet to be matched
    int count = mp.size();

    // Loop until the end of the string
    while (j < s.length())
    {
        // Check if the current character is part of string t
        if (mp.find(s[j]) != mp.end())
        {
            // Update the frequency of the character in the map
            mp[s[j]]--;

            // If the frequency becomes zero, decrement the count
            if (mp[s[j]] == 0)
            {
                count--;
            }
        }

        // If all characters from string t are matched
        if (count == 0)
        {
            // Move the left pointer (i) to find the minimum window
            while (count == 0)
            {
                if (mp.find(s[i]) != mp.end())
                {
                    // Restore the frequency of the character in the map
                    mp[s[i]]++;

                    // If the frequency becomes 1, increment the count
                    if (mp[s[i]] == 1)
                    {
                        count++;

                        // Update the minimum window information
                        if (j - i + 1 < minlen)
                        {
                            minlen = j - i + 1;
                            start = i;
                        }
                    }
                }
                i++;
            }
        }

        // Move the right pointer (j) to continue traversing the string
        j++;
    }

    // If no valid window is found, return an empty string
    if (minlen == INT_MAX)
        return "";

    // Return the minimum window substring
    return s.substr(start, minlen);
}

// Optimal ---------->
// TC :
// SC :

/*
10. Max Consecutive Ones III
ANS : Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
Input : nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2  || Output :6
*/
// Bruteforce ----------->
// TC : O(N^2)
// SC :
int longestOnesBruteforce(std::vector<int> &nums, int k)
{
    int maxOnes = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        int flipCount = 0;
        for (int j = i; j < nums.size(); ++j)
        {
            if (nums[j] == 0)
            {
                if (flipCount < k)
                {
                    flipCount++;
                }
                else
                {
                    break; // Cannot flip more 0's, exit the inner loop
                }
            }
            maxOnes = std::max(maxOnes, j - i + 1);
        }
    }
    return maxOnes;
}

// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N)
// SC :O(1)
int longestOnesOptimal(std::vector<int> &nums, int k)
{
    int left = 0, right = 0, zeroCount = 0, maxOnes = 0;

    while (right < nums.size())
    {
        if (nums[right] == 0)
        {
            zeroCount++;
        }

        while (zeroCount > k)
        {
            if (nums[left] == 0)
            {
                zeroCount--;
            }
            left++;
        }

        maxOnes = std::max(maxOnes, right - left + 1);
        right++;
    }

    return maxOnes;
}

/*
11. Longest Repeating Character Replacement
ANS : You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.
Input :  s = "ABAB", k = 2 || Output : 4
*/
// Bruteforce ----------->
// TC :O(N^3)
// SC :
int characterReplacementBruteforce(string s, int k)
{
    int maxLen = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        for (char c = 'A'; c <= 'Z'; ++c)
        {
            int changes = 0, len = 0;

            for (int j = i; j < s.size(); ++j)
            {
                if (s[j] != c)
                {
                    changes++;
                }

                if (changes > k)
                {
                    break;
                }

                len++;
            }

            maxLen = max(maxLen, len);
        }
    }

    return maxLen;
}

// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N)
// SC : O(26) or O(1)
int characterReplacementOptimal(string s, int k)
{
    unordered_map<char, int> alphabets;
    int ans = 0;
    int left = 0;
    int right = 0;
    int maxf = 0;

    for (right = 0; right < s.size(); right++)
    {
        alphabets[s[right]] = 1 + alphabets[s[right]];
        maxf = max(maxf, alphabets[s[right]]);

        if ((right - left + 1) - maxf > k)
        {
            alphabets[s[left]] -= 1;
            left++;
        }
        else
        {
            ans = max(ans, (right - left + 1));
        }
    }

    return ans;
}

/*
12. Binary subarray with sum
ANS : Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
Input :  nums = [1,0,1,0,1], goal = 2  || Output : 4
*/
// Bruteforce ----------->
// Time Complexity: O(n^2)
// Space Complexity: O(1)
int numSubarraysWithSumBruteforce(vector<int> &nums, int goal)
{
    // Bruteforce
    int count = 0;
    int n = nums.size();

    for (int start = 0; start < n; ++start)
    {
        int sum = 0;
        for (int end = start; end < n; ++end)
        {
            sum += nums[end];
            if (sum == goal)
            {
                ++count;
            }
        }
    }

    return count;
}
// Better ----------->
// Time Complexity: O(N)
// Space Complexity: O(N)
int numSubarraysWithSumBetter(vector<int> &nums, int goal)
{
    // Better
    int count = 0;
    int sum = 0;
    std::unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1;

    for (int num : nums)
    {
        sum += num;
        count += prefixSumCount[sum - goal];
        prefixSumCount[sum]++;
    }

    return count;
}
// Optimal ---------->
// Time Complexity : O(N)
// Space Complexity : O(1)
int atMost(vector<int> &A, int S)
{
    if (S < 0)
        return 0;
    int res = 0, i = 0, n = A.size();
    for (int j = 0; j < n; j++)
    {
        S -= A[j];
        while (S < 0)
            S += A[i++];
        res += j - i + 1;
    }
    return res;
}
int numSubarraysWithSumOptimal(vector<int> &nums, int goal)
{
    return atMost(nums, goal) - atMost(nums, goal - 1);
}

/*
13. Count Number of Nice Subarrays
ANS : Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.
Input : nums = [1,1,2,1,1], k = 3  || Output :2
*/
// Bruteforce ----------->
// TC : O(n^2)
// SC :
int numberOfSubarraysBruteforce(vector<int> &nums, int k)
{
    int count = 0;
    int n = nums.size();

    for (int start = 0; start < n; ++start)
    {
        int oddCount = 0;
        for (int end = start; end < n; ++end)
        {
            if (nums[end] % 2 == 1)
            {
                ++oddCount;
            }
            if (oddCount == k)
            {
                ++count;
            }
            if (oddCount > k)
            {
                break;
            }
        }
    }

    return count;
}
// Better ----------->
// TC :O(N)
// SC :
int numberOfSubarraysBetter(vector<int> &nums, int k)
{
    int count = 0;
    int n = nums.size();
    int oddCount = 0;
    int left = 0;
    int result = 0;

    for (int right = 0; right < n; ++right)
    {
        if (nums[right] % 2 == 1)
        {
            ++oddCount;
        }

        while (oddCount > k)
        {
            if (nums[left] % 2 == 1)
            {
                --oddCount;
            }
            ++left;
        }

        if (oddCount == k)
        {
            int leftTemp = left;
            while (leftTemp < right && nums[leftTemp] % 2 == 0)
            {
                ++leftTemp;
            }
            result += (leftTemp - left + 1);
        }
    }

    return result;
}
// Optimal ---------->
// TC :O(n)
// SC :
int numberOfSubarraysOptimal(vector<int> &nums, int k)
{
    int n = nums.size();
    std::unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1;
    int sum = 0;
    int result = 0;

    for (int i = 0; i < n; ++i)
    {
        sum += (nums[i] % 2 == 1 ? 1 : 0);

        if (prefixSumCount.find(sum - k) != prefixSumCount.end())
        {
            result += prefixSumCount[sum - k];
        }

        prefixSumCount[sum]++;
    }

    return result;
}

/*
14. Number of Substrings Containing All Three Characters
ANS : Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.
Input : s = "abcabc" || Output :10
*/
// Bruteforce ----------->
// TC : O(n^3)
// SC :
int numberOfSubstringsBruteforce(string s)
{
    int count = 0;
    int n = s.length();

    for (int start = 0; start < n; ++start)
    {
        for (int end = start; end < n; ++end)
        {
            bool hasA = false, hasB = false, hasC = false;

            for (int i = start; i <= end; ++i)
            {
                if (s[i] == 'a')
                {
                    hasA = true;
                }
                else if (s[i] == 'b')
                {
                    hasB = true;
                }
                else if (s[i] == 'c')
                {
                    hasC = true;
                }
            }

            if (hasA && hasB && hasC)
            {
                ++count;
            }
        }
    }

    return count;
}
// Better ----------->
// TC : O(n)
// SC :
int numberOfSubstringsBetter(string s)
{
    int count = 0;
    int aPointer = -1, bPointer = -1, cPointer = -1;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'a')
        {
            aPointer = i;
        }
        else if (s[i] == 'b')
        {
            bPointer = i;
        }
        else if (s[i] == 'c')
        {
            cPointer = i;
        }

        if (aPointer != -1 && bPointer != -1 && cPointer != -1)
        {
            count += (std::min({aPointer, bPointer, cPointer}) + 1);
        }
    }

    return count;
}
// Optimal ---------->
// TC : O(n)
// SC :
int numberOfSubstringsOptimal(string s)
{
    int count = 0;
    vector<int> lastIndex(3, -1); // 0: 'a', 1: 'b', 2: 'c'

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'a')
        {
            lastIndex[0] = i;
        }
        else if (s[i] == 'b')
        {
            lastIndex[1] = i;
        }
        else if (s[i] == 'c')
        {
            lastIndex[2] = i;
        }

        if (lastIndex[0] != -1 && lastIndex[1] != -1 &&
            lastIndex[2] != -1)
        {
            count +=
                (min({lastIndex[0], lastIndex[1], lastIndex[2]}) + 1);
        }
    }

    return count;
}

/*
15. Maximum Points You Can Obtain from Cards
ANS : There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
Input :  cardPoints = [1,2,3,4,5,6,1], k = 3 || Output : 12
*/
// Bruteforce ----------->
// TC : O(k*n)
// SC :
int maxScoreBruteforce(vector<int> &cardPoints, int k)
{
    int max_score = INT_MIN;
    int n = cardPoints.size();

    for (int x = 0; x <= k; ++x)
    {
        int score_from_start = 0;
        int score_from_end = 0;

        for (int i = 0; i < x; ++i)
        {
            score_from_start += cardPoints[i];
        }

        for (int i = n - (k - x); i < n; ++i)
        {
            score_from_end += cardPoints[i];
        }

        max_score = max(max_score, score_from_start + score_from_end);
    }

    return max_score;
}
// Better ----------->
// TC : O(n)
// SC :
int maxScoreBetter(vector<int> &cardPoints, int k)
{
    int total_sum = 0;
    int n = cardPoints.size();

    for (int i = 0; i < n; ++i)
    {
        total_sum += cardPoints[i];
    }

    int window_size = n - k;
    int current_sum = 0;
    int min_sum = INT_MAX;

    for (int i = 0; i < window_size; ++i)
    {
        current_sum += cardPoints[i];
    }

    min_sum = min(min_sum, current_sum);

    for (int i = window_size; i < n; ++i)
    {
        current_sum += cardPoints[i] - cardPoints[i - window_size];
        min_sum = min(min_sum, current_sum);
    }

    return total_sum - min_sum;
}
// Optimal ---------->
// TC :
// SC :

/*
16. Longest Substring with At Most K Distinct Characters
ANS : You are given a string 'str' and an integer ‘K’. Your task is to find the length of the largest substring with at most ‘K’ distinct characters.
Input : 'str’ = ‘abbbbbbc’ and ‘K’ = 2,  || Output :7
*/
// Bruteforce ----------->
// TC : O(n^3)
// SC :
int kDistinctCharsBruteforce(int k, string &s)
{

    int maxLength = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        for (int j = i + 1; j <= s.length(); ++j)
        {
            string substring = s.substr(i, j - i);
            unordered_set<char> distinctChars(substring.begin(), substring.end());
            if (distinctChars.size() <= k)
            {
                maxLength = max(maxLength, j - i);
            }
        }
    }
    return maxLength;
}
// Better ----------->
// TC :O(n)
// SC : O(min(n, k))
int kDistinctCharsBetter(int k, string &s)
{
    int maxLength = 0;
    int left = 0, right = 0;
    unordered_map<char, int> charCount;

    while (right < s.length())
    {
        charCount[s[right]]++;

        while (charCount.size() > k)
        {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0)
            {
                charCount.erase(s[left]);
            }
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
        right++;
    }

    return maxLength;
}

// Optimal ---------->
// TC :
// SC :

/*
17. Subarrays with K Different Integers
ANS : Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.
Input :  nums = [1,2,1,2,3], k = 2  || Output : 7
*/
// Bruteforce ----------->
// TC : O(n^3)
// SC :
int subarraysWithKDistinctBruteforce(vector<int> &nums, int k)
{
    int goodSubarrays = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i)
    {
        unordered_set<int> distinctIntegers;
        for (int j = i; j < n; ++j)
        {
            distinctIntegers.insert(nums[j]);
            if (distinctIntegers.size() == k)
            {
                goodSubarrays++;
            }
        }
    }

    return goodSubarrays;
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(n)
// SC :O(k)
int atMostKDistinct(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> frequency;
    int count = 0, left = 0;

    for (int right = 0; right < n; ++right)
    {
        if (frequency[nums[right]] == 0)
        {
            k--; // Decrement k only when encountering a new distinct element.
        }
        frequency[nums[right]]++;

        while (k < 0)
        {
            frequency[nums[left]]--;
            if (frequency[nums[left]] == 0)
            {
                k++; // Increment k only when removing the last occurrence of a distinct element.
            }
            left++;
        }

        count += right - left + 1;
    }

    return count;
}
int subarraysWithKDistincOptimal(vector<int> &nums, int k)
{
    return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
}

/*
18. Minimum Window Substring
ANS : Given two strings s and t of lengths m and n respectively, return the minimum window
substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
string minWindowBruteforce(const string &s, const string &t)
{
    int m = s.length();
    int n = t.length();

    if (m < n)
    {
        return "";
    }

    string result = "";
    int minLength = INT_MAX;

    for (int i = 0; i <= m - n; ++i)
    {
        for (int j = i + n - 1; j < m; ++j)
        {
            string window = s.substr(i, j - i + 1);

            unordered_map<char, int> charCount;
            for (char c : window)
            {
                charCount[c]++;
            }

            bool validWindow = true;
            for (char c : t)
            {
                if (charCount[c] == 0)
                {
                    validWindow = false;
                    break;
                }
                charCount[c]--;
            }

            if (validWindow && window.length() < minLength)
            {
                minLength = window.length();
                result = window;
            }
        }
    }

    return result;
}
// Better ----------->
// TC :
// SC :
string minWindowBetter(const string &s, const string &t)
{
    int m = s.length();
    int n = t.length();

    if (m < n)
    {
        return "";
    }

    unordered_map<char, int> targetCharCount;
    for (char c : t)
    {
        targetCharCount[c]++;
    }

    int left = 0;
    int right = 0;
    int minLength = INT_MAX;
    int requiredChars = t.length();

    string result = "";

    while (right < m)
    {
        if (targetCharCount[s[right]] > 0)
        {
            requiredChars--;
        }

        targetCharCount[s[right]]--;

        while (requiredChars == 0)
        {
            int currentLength = right - left + 1;

            if (currentLength < minLength)
            {
                minLength = currentLength;
                result = s.substr(left, currentLength);
            }

            targetCharCount[s[left]]++;

            if (targetCharCount[s[left]] > 0)
            {
                requiredChars++;
            }

            left++;
        }

        right++;
    }

    return result;
}
// Optimal ---------->
// TC :
// SC :
string minWindowOptimal(const string &s, const string &t)
{
    int m = s.length();
    int n = t.length();

    if (m < n)
    {
        return "";
    }

    unordered_map<char, int> targetCharCount;
    for (char c : t)
    {
        targetCharCount[c]++;
    }

    int left = 0;
    int right = 0;
    int minLength = INT_MAX;
    int requiredChars = t.length();

    int start = 0;

    while (right < m)
    {
        if (targetCharCount[s[right]] > 0)
        {
            requiredChars--;
        }

        targetCharCount[s[right]]--;

        while (requiredChars == 0)
        {
            int currentLength = right - left + 1;

            if (currentLength < minLength)
            {
                minLength = currentLength;
                start = left;
            }

            targetCharCount[s[left]]++;

            if (targetCharCount[s[left]] > 0)
            {
                requiredChars++;
            }

            left++;
        }

        right++;
    }

    return (minLength == INT_MAX) ? "" : s.substr(start, minLength);
}

/*
19.  Minimum Window Subsequence
ANS : You are given two strings ‘S’ and ‘T’. Your task is to find the minimum (Contiguous) substring ‘W’ of ‘S’, such that ‘T’ is a subsequence of ‘W’
A subsequence is a sequence that can be derived from another sequence by removing zero or more elements, without changing the order.
A substring is a contiguous part of a string.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// Time Complexity: O( N * N )
// Space Complexity: O( 1 )

string minWindow(string S, string T)
{
    // Initially our window is empty
    string window = "";
    int j = 0, min = S.length();

    for (int i = 0; i < S.length(); i++)
    {

        // If characters are same, then increment the j pointer
        if (S[i] == T[j])
        {
            j++;

            // If we finally reach the end of string T, we can start shrinking our window
            if (j == T.length())
            {
                int end = i;
                j--;

                // We are doing j-- in order to minimise our window size
                while (j >= 0)
                {
                    if (S[i] == T[j])
                    {
                        j--;
                    }
                    i--;
                }

                // Incrementing i and j for next iteration
                j++;
                i++;

                // Updating our window, if we found an element of minimum length
                if (end - i < min)
                {

                    // Updating minimum
                    min = end - i;

                    // Updating window
                    window = "";
                    for (int j = i; j <= end; ++j)
                    {
                        window += S[j];
                    }
                }
            }
        }
    }

    // Returning our final answer, which is stored in window
    return window;
}
/*
20.
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

// ================================MAIN START=================================>>
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("./i.txt", "r", stdin);
    //     freopen("./o.txt", "w", stdout);
    // #endif
    /*
        Some short function
           int maxi = *max_element(arr.begin(), arr.end());
            int sum = accumulate(arr.begin(), arr.end(), 0);
    */
    // vector<int> arr = {100, 200, 300, 400};
    // cout << maximumSumSubarray(arr, arr.size(), 2);
    // int arr[6] = {2, -3, 4, -1, 7, -1};
    // vector<int> ans = FirstNegativeInteger(arr, 6, 2);
    // printVector(ans);
    // string text = "forxxorfxdofr";
    // string word = "for";
    // cout << countAnagrams(text, word) << endl;
    // vector<int> arr = {4, 1, 1, 1, 2, 3, 5};
    // vector<int> ans = maxSlidingWindow(arr, 3);
    // printVector(ans);
    // cout << "Max is : " << maxSubarrayLength(arr, 5);
    // string S = "aabacbebebe";
    // cout << "Longest " << longestKSubstr(S, 3);
    // string s = "abcabcbb";
    // cout << lengthOfLongestSubstringBruteforce(s);
    // cout << lengthOfLongestSubstringOptimal(s);
    // cout<<toysPicked(s);
    // cout << minWindow("ADOBECODEBANC", "ABC");
    vector<int> arr = {1, 2, 1, 2, 3};
    cout << "Subarray is " << subarraysWithKDistinctBruteforce(arr, 2);
    cout << endl;
    cout << "Subarray is " << subarraysWithKDistincOptimal(arr, 2);

    // End code here-------->>

    return 0;
}
