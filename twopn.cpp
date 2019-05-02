#include "twopn.h"
#include <cmath>
float sum::func(float x,float y)
{
	return x+y;
}
float subtraction::func(float x,float y)
{
	return x-y;
}
float multiply::func(float x,float y)
{
	return x*y;
}
float division::func(float x,float y)
{
	if(y==0)
	{
		if(!asserted)
		{
			std::cout<<"ERROR: Division by zero"<<std::endl;
			asserted=1;
		}
		return NAN;
	}
	else
		return x/y;
}
float EQU::func(float x,float y)
{
	if(isnan(x)||isnan(y))return NAN;
	return float(x==y);
}
float GTR::func(float x,float y)
{
	if(isnan(x)||isnan(y))return NAN;
	return float(x>y);
}
float GEQ::func(float x,float y)
{
	if(isnan(x)||isnan(y))return NAN;
	return float(x>=y);
}
float LSS::func(float x,float y)
{
	if(isnan(x)||isnan(y))return NAN;
	return float(x<y);
}
float LEQ::func(float x,float y)
{
	if(isnan(x)||isnan(y))return NAN;
	return float(x<=y);
}
/*
�����µ�˫���������ķ���:
��:����1:
class Pow:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func(float x,float y)
		{
			return std::pow(x,y);
		}
};
gra.push(�ڵ���,new Pow(gra[���ڵ���1],gra[���ڵ���2]));(graΪGraph���ʵ��) 

����2:
gra.push(�ڵ���,new Tpn<std::pow>(gra[���ڵ���1],gra[���ڵ���2]));
*/
