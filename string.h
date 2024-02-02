#pragma once

// 383. �����
namespace N383
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

// 2678. ���˵���Ŀ
namespace N2678
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

// 2696. ɾ���Ӵ�����ַ�����С����
namespace N2696
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

// 2707. �ַ����еĶ����ַ�
namespace N2707
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

// 2744. ����ַ��������Ŀ
namespace N2744
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

// 2788. ���ָ�������ַ���
namespace N2788
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

// 2810. ���ϼ���
namespace N2810
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