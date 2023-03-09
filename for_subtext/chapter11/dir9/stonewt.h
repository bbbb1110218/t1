#ifndef __STONEWT__H__
#define __STONEWT__H__

#include <iostream>
using namespace std;

class Stonewt{

	public:
		enum TYPE{STONE,POUNDS,FLOATPOUNDS};

	private:
		enum {RATE=14};
		double pounds;
		int stone;
		double left_pounds;
		TYPE type_;
	public:
		Stonewt(){pounds=stone=left_pounds=0;};
		Stonewt(double p);
		Stonewt(int s,double lp);
		void set_type(TYPE tp);
		void set_type(int tp); // 那啥



		Stonewt operator+(const Stonewt&s)const{
			return Stonewt(pounds+s.pounds);
		}

		Stonewt operator-(const Stonewt&s)const{
			if(pounds - s.pounds <0){
				cout <<" negative pounds"<< endl;
				return Stonewt(0);
			}
			else
				return Stonewt(pounds - s.pounds);
		}

		Stonewt operator*(const double & multi) const{
			return Stonewt(pounds *multi);
		}

		bool operator>(const Stonewt&s) const{
			return pounds > s.pounds;
		}

		bool operator>=(const Stonewt&s) const{
			return pounds >= s.pounds;
		}

		bool operator<(const Stonewt&s) const{
			return pounds < s.pounds;
		}

		bool operator<=(const Stonewt&s) const{
			return pounds <= s.pounds;
		}

		bool operator==(const Stonewt&s) const{
			return pounds == s.pounds;
		}

		bool operator!=(const Stonewt&s) const{
			return pounds != s.pounds;
		}

		void set_stone(int n){
			stone=n;
			pounds=stone*RATE + left_pounds;
		}




		friend ostream& operator<<(ostream&os,const Stonewt &s);
		friend Stonewt operator*(const double &multi,const Stonewt&s){
			return s*multi;
		}

};

#endif

