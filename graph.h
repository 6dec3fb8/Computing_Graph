#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "node.h"
#include "zeropn.h"
#include "onepn.h"
#include "twopn.h"
#include "threepn.h"
extern bool asserted;
class Graph
{
	std::map<std::string,Node*> nodes;//�ڵ�ָ���б�,������������������,���Բ�һ���������нڵ� 
	std::map<int,float> outvalue;//��������ʷ��¼ 
	int cnt=0;//eval�Ĵ��� 
	public:		
		Node* operator[] (const string str);//��֪�ڵ���,��ȡ�ڵ�ָ�� 
		void push(std::string str,Node* newnode);//�����½ڵ� 
		void reset(string nodename);//��ĳ��eval�Ľ������Ա������һ�μ��� 
		float eval(string nodename, const map<string,float> &phMap/*placeholder�б�*/);//����ĳ�ڵ���ֵ,���û��placeholder��phMapΪ�� 
		void setvariable(string vname,float value);//����ĳ��variable��ֵ 
		float lookupanswer(int t);//��ȡ��t��eval�Ľ�� 
};
