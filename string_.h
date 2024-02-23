#pragma once

// 30. �������е��ʵ��Ӵ� (����)
namespace n30
{
//����һ���ַ��� s ��һ���ַ������� words�� words �������ַ��� ������ͬ��
//
//s �е� �����Ӵ� ��ָһ������  words �������ַ���������˳�����������������Ӵ���
//
//���磬��� words = ["ab", "cd", "ef"]�� ��ô "abcdef"�� "abefcd"��"cdabef"�� "cdefab"��"efabcd"�� �� "efcdab" ���Ǵ����Ӵ��� "acdbef" ���Ǵ����Ӵ�����Ϊ�������κ� words ���е����ӡ�
//�������д����Ӵ��� s �еĿ�ʼ������������� ����˳�� ���ش𰸡�
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
    // ע������ı�����ʽ����Ϊÿ�����ʵĳ�����һ���ģ�����ֻ��Ҫ����һ�����ʵĳ��ȼ���
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

// 38. ������� (�е�)
namespace n38
{
//����һ�������� n �����������еĵ� n �
//
//��������С���һ���������У������� 1 ��ʼ�������е�ÿһ��Ƕ�ǰһ���������
//
//����Խ����������ɵݹ鹫ʽ����������ַ������У�
//
//countAndSay(1) = "1"
//countAndSay(n) �Ƕ� countAndSay(n - 1) ��������Ȼ��ת������һ�������ַ�����
//ǰ�������£�
//
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//��һ�������� 1
//����ǰһ�������� 1 �� �� һ �� 1 �������� "11"
//����ǰһ�������� 11 �� �� �� �� 1 �� ������ "21"
//����ǰһ�������� 21 �� �� һ �� 2 + һ �� 1 �� ������ "1211"
//����ǰһ�������� 1211 �� �� һ �� 1 + һ �� 2 + �� �� 1 �� ������ "111221"
//Ҫ ���� һ�������ַ���������Ҫ���ַ����ָ�Ϊ ��С �������飬ÿ���鶼����������� ��ͬ�ַ� ��ɡ�Ȼ�����ÿ���飬�������ַ���������Ȼ�������ַ����γ�һ�������顣Ҫ������ת��Ϊ�����ַ������Ƚ�ÿ���е��ַ������������滻���ٽ���������������������
class Solution {
public:
  string countAndSay(int n) {
    string num = "1";
    for (int i = 1; i < n; i++)
    {
      string tmpNum = num;
      num.clear();
      char cur = tmpNum[0];
      int cnt = 1;
      for (int j = 1; j < static_cast<int>(tmpNum.size()); ++j)
      {
        if (tmpNum[j] == cur)
        {
          cnt++;
        }
        else
        {
          num.push_back(static_cast<char>(cnt + '0'));
          num.push_back(cur);
          cur = tmpNum[j];
          cnt = 1;
        }
      }
      num.push_back(static_cast<char>(cnt + '0'));
      num.push_back(cur);
    }
    return num;
  }
};
}

// 58. ���һ�����ʵĳ��� (��)
namespace n58
{
//����һ���ַ��� s�������ɵ�����ɣ�����ǰ����һЩ�ո��ַ������������ַ����� ���һ�� ���ʵĳ��ȡ�
//
//���� ��ָ������ĸ��ɡ��������κοո��ַ���������ַ�����
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

// 76. ��С�����Ӵ� (����)
namespace n76
{
//����һ���ַ��� s ��һ���ַ��� t ������ s �к��� t �����ַ�����С�Ӵ������ s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� "" ��
class Solution {
public:
  string minWindow(string s, string t) {

  }
};
}

// 383. ����� (��)
namespace n383
{
//���������ַ�����ransomNote �� magazine ���ж� ransomNote �ܲ����� magazine ������ַ����ɡ�
//
//������ԣ����� true �����򷵻� false ��
//
//magazine �е�ÿ���ַ�ֻ���� ransomNote ��ʹ��һ�Ρ�
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

// 2678. ���˵���Ŀ (��)
namespace n2678
{
//����һ���±�� 0 ��ʼ���ַ��� details ��details ��ÿ��Ԫ�ض���һλ�˿͵���Ϣ����Ϣ�ó���Ϊ 15 ���ַ�����ʾ����ʾ��ʽ���£�
//
//ǰʮ���ַ��ǳ˿͵��ֻ����롣
//��������һ���ַ��ǳ˿͵��Ա�
//�����������ַ��ǳ˿͵����䡣
//��������ַ��ǳ˿͵���λ�š�
//���㷵�س˿������� �ϸ���� 60 �� ��������
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

// 2696. ɾ���Ӵ�����ַ�����С���� (��)
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

// 2707. �ַ����еĶ����ַ� (�е�)
namespace n2707
{
//����һ���±�� 0 ��ʼ���ַ��� s ��һ�������ֵ� dictionary ������Ҫ�� s �ָ�����ɸ� �����ص� �����ַ�����ÿ�����ַ������� dictionary �г��ֹ���s �п��ܻ���һЩ ������ַ� �����κ����ַ����С�
//�����ȡ���Ų��Էָ� s ��ʹʣ�µ��ַ� ���� ��
class Solution {
public:
  int minExtraChar(string s, vector<string>& dictionary) {
    unordered_map<string, int> m;
    // ͳ���ֵ���ÿ�����ʳ��ֵĴ���
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

// 2744. ����ַ��������Ŀ (��)
namespace n2744
{
//����һ���±�� 0 ��ʼ������ words �������а��� ������ͬ ���ַ�����
//
//����ַ��� words[i] ���ַ��� words[j] �����������������ǳ����ǿ���ƥ�䣺
//
//�ַ��� words[i] ���� words[j] �ķ�ת�ַ�����
//0 <= i < j < words.length
//���㷵������ words �е� ��� ƥ����Ŀ��
//
//ע�⣬ÿ���ַ������ƥ��һ�Ρ�
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

// 2788. ���ָ�������ַ��� (��)
namespace n2788
{
//����һ���ַ������� words ��һ���ַ� separator �����㰴 separator ��� words �е�ÿ���ַ�����
//
//����һ���ɲ�ֺ�����ַ�����ɵ��ַ������飬���������ַ��� ��
//
//ע��
//
//separator ���ھ�����ַ�����λ�ã������������ڽ���ַ����С�
//��ֿ����γ��������ϵ��ַ�����
//����ַ������뱣�ֳ�ʼ��ͬ���Ⱥ�˳��
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

// 2810. ���ϼ��� (��)
namespace n2810
{
//��ıʼǱ����̴��ڹ��ϣ�ÿ���������������ַ� 'i' ʱ�����ᷴת����д���ַ����������������ַ����������������
//
//����һ���±�� 0 ��ʼ���ַ��� s �������ù��ϼ�����������ÿ���ַ���
//
//�������ձʼǱ���Ļ��������ַ�����
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