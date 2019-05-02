#include "graph.h"
#include<iostream>
#include <vector>
#include <string>
#include <map>
bool asserted=0;//ĳһ��eval�Ƿ��Ѿ�����error�������ظ����

Node* Graph::operator[](const std::string str)
{
    auto it = nodes.find(str);
    if (it==nodes.end())
        return nullptr;
    return it->second;
}

void Graph::push(std::string str,Node* newnode)
{
    nodes[str] = newnode;
}

void Graph::reset(string nodename)
{
    asserted=0;
    nodes[nodename]->reset();
}

float Graph::eval(string nodename, const map<string,float> &phMap)
{
    ++cnt;
    reset(nodename); 
    for(auto iter=phMap.begin(); iter != phMap.end(); iter++)//��placeholder��ֵ 
        nodes[iter->first]->setvalue(iter->second);
    outvalue[cnt] = nodes[nodename]->geteval();
    return outvalue[cnt];
}

void Graph::setvariable(string vname,float value) 
{
    ++cnt;
    nodes[vname]->setvalue(value);
}

float Graph::lookupanswer(int t)
{
    return outvalue[t];
}
