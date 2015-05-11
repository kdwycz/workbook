///============================================================================
/// Name        : bign.cpp
/// 支持+-*/%^运算，无需指定最大精度，使用了c++流操作，速度不能保证
/// Author      : shu_mj
///============================================================================

#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;
struct bign;
bign operator + (const bign & ,const bign &);
bign operator - (const bign & ,const bign &);
bign operator * (const bign & ,const bign &);
bign operator / (const bign & ,const bign &);
bign operator % (const bign & ,const bign &);

struct bign {
  list<int> data;
  bign() {}
  template<typename T>
  bign(const T & t)
  {
    stringstream str;
    str<<t;
    *this = str.str();
  }
  bign(const string & s) {
    int t, i;
    for (i=int(s.size())-8; i>0; i-=8) {
      istringstream(s.substr(i, 8)) >> t;
      data.push_back(t);
    }
    istringstream(s.substr(0, i+8)) >> t;
    data.push_back(t);
  }

  int do_try(const bign&);//辅助函数
  void do_trim();//辅助函数，去掉前缀0
  string str() const ;//转化成string
  bign operator += (const bign & b) {return *this = *this + b;}
  bign operator -= (const bign & b) {return *this = *this - b;}
  bign operator *= (const bign & b) {return *this = *this * b;}
  bign operator /= (const bign & b) {return *this = *this / b;}
  bign operator %= (const bign & b) {return *this = *this % b;}

};

inline int do_comp(const bign& a, const bign& b) {
  if (a.data.size()<b.data.size()) return -1;
  if (a.data.size()>b.data.size()) return 1;
  list<int>::const_reverse_iterator i;
  list<int>::const_reverse_iterator j;
  for (i=a.data.rbegin(),j=b.data.rbegin(); j!=b.data.rend(); i++,j++) {
    if (*i<*j) return -1;
    if (*i>*j) return 1;
  }
  return 0;
}
bool operator < (const bign & a,const bign & b) {return do_comp(a,b) < 0;}
bool operator > (const bign & a,const bign & b) {return do_comp(a,b) > 0;}
bool operator ==(const bign & a,const bign & b) {return do_comp(a,b) ==0;}
bool operator !=(const bign & a,const bign & b) {return do_comp(a,b) !=0;}
bool operator <=(const bign & a,const bign & b) {return do_comp(a,b) <=0;}
bool operator >=(const bign & a,const bign & b) {return do_comp(a,b) >=0;}


void bign::do_trim() {
  while (data.size()>1&&data.back()==0) data.pop_back();
}

bign operator +(const bign& a, const bign& b) {
  list<int>::const_iterator i, j;
  bign c;
  int t = 0;
  for (i=a.data.begin(),j=b.data.begin(); i!=a.data.end()&&j!=b.data.end(); i++,j++) {
    c.data.push_back(t+*i+*j);
    t=c.data.back()/100000000;
    c.data.back()%=100000000;
  }
  while (i!=a.data.end()) {
    c.data.push_back(t+*i);
    t=c.data.back()/100000000;
    c.data.back()%=100000000;
    i++;
  }
  while (j!=b.data.end()) {
    c.data.push_back(t+*j);
    t=c.data.back()/100000000;
    c.data.back()%=100000000;
    j++;
  }
  if (t!=0) c.data.push_back(t);
  return c;
}

bign operator -(const bign& a, const bign& b) {
  list<int>::const_iterator i, j;
  bign c;
  int t = 0;
  for (i=a.data.begin(),j=b.data.begin(); j!=b.data.end(); i++,j++) {
    t = *i - t;
    if (t>=*j) c.data.push_back(t-*j), t=0;
    else c.data.push_back(t+100000000-*j), t=1;
  }
  while (i!=a.data.end()) {
    t=*i-t;
    if (t>=0) c.data.push_back(t), t=0;
    else c.data.push_back(t+100000000), t=1;
    i++;
  }
  c.do_trim();
  return c;
}

bign operator *(const bign& a, const bign& b) {
  list<int>::const_iterator i, j;
  list<int>::iterator k, kk;
  bign c;
  long long t = 0;

  for (int i=0; i<a.data.size()+b.data.size(); i++) c.data.push_back(0);
  for (i=a.data.begin(),k=c.data.begin(); i!=a.data.end(); i++,k++) {
    for (j=b.data.begin(),kk=k; j!=b.data.end(); j++,kk++) {
      t+=(long long)(*i)*(*j)+(*kk);
      *kk=int(t%100000000);
      t/=100000000;
    }
    *kk+=t;
    t=0;
  }
  c.do_trim();
  return c;
}

int bign::do_try(const bign& a) {
  int l = 1, r = 99999999, m, t;
  while (l+2<r) {
    m = (l + r) / 2;
    t = do_comp(*this, a*bign(m));
    if (t==0) return m;
    if (t<0) r = m - 1;
    else l = m;
  }
  while (do_comp(*this, a*bign(r))<0) r--;
  return r;
}

void divide(const bign& a, const bign& b, bign& d, bign& r) {
  list<int>::const_reverse_iterator i = a.data.rbegin();
  int t;
  d = bign(0);
  r = bign(0);
  do {
    while (r<b&&i!=a.data.rend()) {
      d.data.push_front(0);
      r.data.push_front(*i);
      r.do_trim();
      i++;
    }
    if (r>=b) {
      t = r.do_try(b);
      d.data.front() = t;
      r-=(b*bign(t));
    }
  } while (i!=a.data.rend());
  d.do_trim();
}

bign operator /(const bign& a, const bign& b) {
  bign d, r;
  divide(a, b, d, r);
  return d;
}

bign operator %(const bign& a, const bign& b) {
  bign d, r;
  divide(a, b, d, r);
  return r;
}

bign pow(bign a,int b) {
  bign c(1);
  while (b!=0) {
    if (b&1) c *= a;
    a = a * a;
    b >>= 1;
  }
  return c;
}
inline bign pow(int a,int b)
{
  return pow(bign(a),b);
}
string bign::str() const
{
  string ret;
  if(data.empty()) return ret;
  stringstream s;
  s<<data.back();
  list<int>::const_reverse_iterator i = data.rbegin();
  for(++i;i!=data.rend();++i) {
    s<<setfill('0')<<setw(8)<<*i;
  }
  s>>ret;
  return ret;
}

istream& operator >>(istream & in,bign & b)
{
  string str;
  in>>str;
  b = str;
  return in;
}
ostream& operator <<(ostream & out,const bign & b)
{
  return out<<b.str();
}
int main() {
  bign a = 2,b = 1234;
//  cin>>a>>b;
//  cout<<a<<" + "<<b<<" = "<<a+b<<endl;
//  cout<<a<<"^2 = "<<pow(a,2)<<endl;
//  cout<<pow(11111111,2)<<endl;
  char _a[100],_b[100];
  scanf("%s%s",_a,_b);
  a = _a;b = _b;
  printf("%s + %s = %s\n",a.str().c_str(),b.str().c_str(),(a+b).str().c_str());
  printf("%s^2 = %s\n",a.str().c_str(),pow(a,2).str().c_str());
  printf("%s\n",pow(11111111,2).str().c_str());
  return 0;
}
