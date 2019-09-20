#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;

bool gcd_Euclid(long long int a,long long int b,stack<int> r = stack<int>()){
	stack<int> stack_r = r;
	if (a%b == 0) {
		std::cout << "gcd(a,b)=" << b;
		int s = 0, t = 1;
		int temp_stack_pop = 0, temp;
		while (stack_r.size() > 0) {
			temp_stack_pop = stack_r.top();
			stack_r.pop();
			temp = s;
			s = t;
			t = temp + temp_stack_pop * t;
		}
		std::cout << "\ns=" << s << ";\nt=" << -t << endl;
		return true;
	}
	else {
		stack_r.push(a / b);
		gcd_Euclid(b, a%b, stack_r);
	}
	return false;
}
int main() {
	long long int in_a, in_b;
	while (1)
	{
		std::cout << "请输入 a,b (正整数)\n";
		std::cin >> in_a >> in_b;
		if (in_a <= 0 || in_b <= 0 || in_a<in_b) {
			std::cout << "错误的数字 a 或 b 或 a<b！";
		}
		else {
			//找gcd(a,b)
			gcd_Euclid(in_a, in_b);
		}
	}
	return 0;
}