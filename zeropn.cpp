#include <iostream>
#include <string>
#include "zeropn.h"
void Placeholder::setvalue(float a)
{
	value=a;
	calculated=1;//δ��ֵΪ0,�Ѹ�ֵΪ1 
}
float Placeholder::geteval()
{
	if(calculated)
		return value;//���Ѹ�ֵ�򷵻ض�Ӧ��ֵ 
	else//�������error������nan 
	{
		if(!asserted) 
		{
			std::cout<<"ERROR: Placeholder missing"<<std::endl;
			asserted=1;
		}
		return NAN;
	}
}
float Constant::geteval()
{
	return value;
}
void Constant::reset(){}//constant��calculated��Ϊ1,����reset����Ҫ�����κβ���

Constant::Constant(float b)
{
	value=b;
}
void Variable::setvalue(float a)//�޸�variable��ֵ 
{
	value=a;
}
float Variable::geteval()
{
	return value;
}
void Variable::reset() {}//variable��calculated��Ϊ1,����reset����Ҫ�����κβ���
Variable::Variable(float b)
{
	value=b;
}
