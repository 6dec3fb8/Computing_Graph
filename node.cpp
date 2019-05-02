#include "node.h"

void Node::setvalue(float a)//����variable������������������� 
{
}

void Node::reset()
{
    calculated=0;
}

void OneParentNode::reset()
{
	p1->reset();//���ڵ�ҲҪ���� 
    calculated=0;
}
void TwoParentsNode::reset()
{
	p1->reset();
	p2->reset();
    calculated=0;
}
void ThreeParentsNode::reset()
{
	p1->reset();
	p2->reset();
	p3->reset();
    calculated=0;
}

float ZeroParentNode::geteval()
{
    return NAN;
}

float OneParentNode::geteval()
{
    if(calculated)return tempeval;//����Ѽ����ֱ�ӷ��ؼ�����ֵ 
    else
    {
        calculated=1;
        tempeval=func(p1->geteval());
        return tempeval;
    }
}

OneParentNode::OneParentNode(Node* parent1)
{
    p1=parent1;
}

float TwoParentsNode::geteval()
{
    if(calculated)return tempeval;
    else
    {
        calculated=1;
        tempeval=func(p1->geteval(),p2->geteval());
        return tempeval;
    }
}

TwoParentsNode::TwoParentsNode(Node* parent1,Node* parent2)
{
    p1=parent1;
    p2=parent2;
}

float ThreeParentsNode::geteval()
{
    if(calculated)return tempeval;
    else
    {
        calculated=1;
        tempeval=func(p1->geteval(),p2->geteval(),p3->geteval());
        return tempeval;
    }
}

ThreeParentsNode::ThreeParentsNode(Node* parent1,Node* parent2,Node* parent3)
{
    p1=parent1;
    p2=parent2;
    p3=parent3;
}
