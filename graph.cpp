#include "graph.h"
#include<iostream>
#include <vector>
#include <string>
#include <map>
bool asserted=0;//ĳһ�������Ƿ��Ѿ�����error�������ظ����
Graph::Graph()
{
    cnt = 0;
}

Node* Graph::operator[](const string& str)
{
    auto it = nodes.find(str);
    if (it==nodes.end())
        return nullptr;
    return it->second;
}

void Graph::pushNode(std::string str,Node* newnode)
{
    if(nodes[str]!=nullptr)
    {
        nodes[str+"_old"] = nodes[str];
        // nodes[str] = 
        // return ;
    }
    nodes[str] = newnode;
}

void Graph::reset(string nodename)
{
  //  for(auto it=nodes.begin(); it != nodes.end(); it++)
    //    it->second->reset();
    asserted=0;
    nodes[nodename]->reset();
    
}

float Graph::eval(string nodename, const map<string,float> &phMap)
{
    ++cnt;
    reset(nodename);
    for(auto iter=phMap.begin(); iter != phMap.end(); iter++)
        nodes[iter->first]->setvalue(iter->second);
    outvalue[cnt] = nodes[nodename]->geteval();
    return nodes[nodename]->geteval();
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
