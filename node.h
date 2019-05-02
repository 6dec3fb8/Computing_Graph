#pragma once
#include <iostream>
#include <string>
#include <cmath>
class Node//�ڵ㰴���ڵ�ĸ�����Ϊ4��:0��(constant,variable,placeholder),1��(print�͸��ֵ���������),2��(����������Ƚ�),3��(cond)
{
	protected:
		float tempeval;//��ʱ������ֵ(�����ظ�����) 
		bool calculated = 0;//�Ƿ��Ѽ��� (�����ظ�����)
	public:
		virtual float geteval() = 0;//��ȡ�ڵ���ֵ 
		virtual void setvalue(float a);//��variable��ֵ 
		virtual void reset();//��Ϊ"δ����"״̬ 
};

class ZeroParentNode:public Node//û�и��ڵ�Ľڵ�,constant,variable,placeholder
{
	public:
		float geteval();
};

class OneParentNode:public Node//1�����ڵ�Ľڵ�,print�͵��������� 
{
	public:
		Node *p1;//���ڵ�ָ�� 
		OneParentNode(Node* parent);
		virtual float func(float x) = 0;//����ڵ��Ӧ�ĺ��� 
		virtual void reset();	
		float geteval();
};

template<float f(float x)>//����������ģ��,�����ɵش��������������ڵ� 
class Opn:public OneParentNode
{
	using OneParentNode::OneParentNode;
	float func(float x){return f(x);}
};

class TwoParentsNode:public Node//2�����ڵ�Ľڵ�,����������Ƚ� 
{
	public:
		Node *p1,*p2;//parents
		virtual float func(float x,float y) = 0;//˫�������� 
		float geteval();
		virtual void reset();
		int getParentsNum();
		TwoParentsNode(Node* parent1,Node* parent2);
};

template<float f(float x,float y)>//˫��������ģ��,�����ɵش���˫���������ڵ� 
class Tpn:public TwoParentsNode
{
	using TwoParentsNode::TwoParentsNode;
	float func(float x,float y){return f(x,y);}
};

class ThreeParentsNode:public Node//3�����ڵ�Ľڵ�,ֻ��cond 
{
	public:
		Node *p1,*p2,*p3;//parents
		virtual float func(float x,float y,float z) = 0;//����������	
		float geteval();
		virtual void reset();
		int getParentsNum();
		ThreeParentsNode(Node* parent1,Node* parent2,Node* parent3);
};
