#pragma once

// 30. 串联所有单词的子串 (困难)
namespace n30
{
//给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。
//
//s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。
//
//例如，如果 words = ["ab", "cd", "ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
//返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。
class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    if (s.empty() || words.empty())
    {
      return res;
    }
    int wordLen = static_cast<int>(words[0].size());
    int wordCount = static_cast<int>(words.size());
    unordered_map<string, int> wordMap;
    for (auto& word : words)
    {
      wordMap[word]++;
    }
    // 注意这里的遍历方式，因为每个单词的长度是一样的，所以只需要遍历一个单词的长度即可
    for (int i = 0; i < wordLen; ++i)
    {
      int left = i;
      int right = i;
      int count = 0;
      unordered_map<string, int> window;
      while (right + wordLen <= s.size())
      {
        string word = s.substr(right, wordLen);
        right += wordLen;
        if (wordMap.count(word))
        {
          window[word]++;
          count++;
          while (window[word] > wordMap[word])
          {
            string leftWord = s.substr(left, wordLen);
            left += wordLen;
            window[leftWord]--;
            count--;
          }
          if (count == wordCount)
          {
            res.push_back(left);
          }
        }
        else
        {
          left = right;
          count = 0;
          window.clear();
        }
      }
    }
    return res;
  }
};
}

// 58. 最后一个单词的长度 (简单)
namespace n58
{
//给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
//
//单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
class Solution {
public:
  int lengthOfLastWord(string s) {
    for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i)
    {
      if (s[i] != ' ')
      {
        int j = i;
        while (j >= 0 && s[j] != ' ')
        {
          j--;
        }
        return i - j;
      }
    }
    return 0;
  }
};
}

// 383. 赎金信 (简单)
namespace n383
{
//给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
//
//如果可以，返回 true ；否则返回 false 。
//
//magazine 中的每个字符只能在 ransomNote 中使用一次。
class Solution {
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> cnt(26, 0);
    for (int i = 0; i < magazine.size(); ++i)
    {
      cnt[magazine[i] - 'a']++;
    }
    for (int i = 0; i < ransomNote.size(); ++i)
    {
      cnt[ransomNote[i] - 'a']--;
      if (cnt[ransomNote[i] - 'a'] < 0)
      {
        return false;
      }
    }
    return true;
  }
};
}

// 2678. 老人的数目 (简单)
namespace n2678
{
//给你一个下标从 0 开始的字符串 details 。details 中每个元素都是一位乘客的信息，信息用长度为 15 的字符串表示，表示方式如下：
//
//前十个字符是乘客的手机号码。
//接下来的一个字符是乘客的性别。
//接下来两个字符是乘客的年龄。
//最后两个字符是乘客的座位号。
//请你返回乘客中年龄 严格大于 60 岁 的人数。
class Solution {
public:
  int countSeniors(vector<string>& details) {
    int res = 0;
    for (size_t i = 0; i < details.size(); ++i)
    {
      string age = details[i].substr(11, 2);
      if (stoi(age) > 60)
      {
        res++;
      }
    }
    return res;
  }
};
}

// 2696. 删除子串后的字符串最小长度 (简单)
namespace n2696
{
class Solution {
public:
  int minLength(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); ++i)
    {
      if (!st.empty() && s[i] == 'B' && st.top() == 'A')
      {
        st.pop();
      }
      else if (!st.empty() && s[i] == 'D' && st.top() == 'C')
      {
        st.pop();
      }
      else
      {
        st.push(s[i]);
      }
    }
    return static_cast<int>(st.size());
  }
};
}

// 2707. 字符串中的额外字符 (中等)
namespace n2707
{
//给你一个下标从 0 开始的字符串 s 和一个单词字典 dictionary 。你需要将 s 分割成若干个 互不重叠 的子字符串，每个子字符串都在 dictionary 中出现过。s 中可能会有一些 额外的字符 不在任何子字符串中。
//请你采取最优策略分割 s ，使剩下的字符 最少 。
class Solution {
public:
  int minExtraChar(string s, vector<string>& dictionary) {
    unordered_map<string, int> m;
    // 统计字典中每个单词出现的次数
    for (int i = 0; i < dictionary.size(); ++i)
    {
      m[dictionary[i]]++;
    }
    int n = static_cast<int>(s.size());
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
      dp[i] = dp[i - 1] + 1;
      for (int j = 0; j < i; ++j)
      {
        string tmp = s.substr(j, i - j);
        if (m.count(tmp))
        {
          dp[i] = min(dp[i], dp[j]);
        }
      }
    }
    return dp[n];
  }
};
}

// 2744. 最大字符串配对数目 (简单)
namespace n2744
{
//给你一个下标从 0 开始的数组 words ，数组中包含 互不相同 的字符串。
//
//如果字符串 words[i] 与字符串 words[j] 满足以下条件，我们称它们可以匹配：
//
//字符串 words[i] 等于 words[j] 的反转字符串。
//0 <= i < j < words.length
//请你返回数组 words 中的 最大 匹配数目。
//
//注意，每个字符串最多匹配一次。
class Solution {
public:
  int maximumNumberOfStringPairs(vector<string>& words) {
    int ans = 0;
    unordered_set<string> occ;
    for (auto& word : words)
    {
      string tmp = word;
      reverse(tmp.begin(), tmp.end());
      if (occ.count(tmp))
      {
        ans++;
      }
      occ.insert(word);
    }
    return ans;
  }
};
}

// 2788. 按分隔符拆分字符串 (简单)
namespace n2788
{
//给你一个字符串数组 words 和一个字符 separator ，请你按 separator 拆分 words 中的每个字符串。
//
//返回一个由拆分后的新字符串组成的字符串数组，不包括空字符串 。
//
//注意
//
//separator 用于决定拆分发生的位置，但它不包含在结果字符串中。
//拆分可能形成两个以上的字符串。
//结果字符串必须保持初始相同的先后顺序。
class Solution {
public:
  vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
    vector<string> res;
    for (auto word : words)
    {
      string tmp;
      for (auto c : word)
      {
        if (c == separator)
        {
          if (!tmp.empty())
          {
            res.push_back(tmp);
            tmp.clear();
          }
        }
        else
        {
          tmp.push_back(c);
        }
      }
      if (!tmp.empty())
      {
        res.push_back(tmp);
      }
    }
    return res;
  }
};
}

// 2810. 故障键盘 (简单)
namespace n2810
{
//你的笔记本键盘存在故障，每当你在上面输入字符 'i' 时，它会反转你所写的字符串。而输入其他字符则可以正常工作。
//
//给你一个下标从 0 开始的字符串 s ，请你用故障键盘依次输入每个字符。
//
//返回最终笔记本屏幕上输出的字符串。
class Solution {
public:
  string finalString(string s) {
    string res;
    for (auto c : s)
    {
      if (c == 'i')
      {
        reverse(res.begin(), res.end());
      }
      else
      {
        res.push_back(c);
      }
    }
    return res;
  }
};
}