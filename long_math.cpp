#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Long_num
{
		vector<unsigned> num;
		int l;
		static unsigned base;
		Long_num(char* s)
		{	base = 1000000;
			for (int i = strlen(s); i > 0; i -= 6) 
			{
				s[i] = 0;
				num.push_back (atoi (i >= 6 ? s + i - 6 : s));
			}
		}
		void zero_del()
		{
			while (num.size() > 1 && num.back() == 0)
				{
					num.pop_back();
				}
		}
		&Long_num operator + (&Long_num b)
		{	Long_num t = new int[ max(num.size(),b.size())+1];
			int buf = 0;
			for (int i = 0; i <= max(num.size(),b.size()) || buf; ++i) 
			{
				if (i == num.size())
					{
						num.push_back (0);
					}
				num[i] += buff + (i < b.size() ? b[i] : 0);
				buf = a[i] >= base;
				if (buff)  
				{
				t.num[i] -= base;
				}
			}
			zero_del();
			return &t;
		}
		Long_num operator - (&Long_num b)
		{	
			Long_num t = new int[ max(num.size(),b.size())];
			int buf = 0;
			for (int i=0; i < b.size() || carry; ++i) 
			{
				t [i] -= buf + (i < b.size() ? b[i] : 0);
				buf = t[i] < 0;
				if (buf)
				  t[i] += base;
			}
			zero_del();
		}
		
		
};
