#include "SObject.h"

SObject::SObject(SObject* parent)
	:m_parent(parent)  //����ɸ���,ָ�򸸶���
{
	if (parent)
	{					
		m_parent->m_children.push_back(this);	//��this��ӵ�������ĺ����б�
	}
	printf("Sobject create %s\n",objectName().c_str());
	release();
}

SObject::~SObject()
{
	printf("Sobject destory %s\n", objectName().c_str());
	//�������ٵ�ʱ��
	//1,���Լ��Ӹ��������Ƴ���
	if (m_parent)
	{
		auto& pchild = m_parent->m_children;
		auto it = std::find(pchild.begin(), pchild.end(),this);
		if (it != pchild.end())
			m_parent->m_children.erase(it);
	}
	//2,���Լ��ͺ��Ӷ��ͷŵ�
	//2.1 ����պ����б�(�ͷ�)
	for (auto obj : this->m_children)
	{
		if(obj->isRelease())
			delete obj;
	}
	m_children.clear();
	//2.2 �ͷ��Լ�
	//delete this;
}

void SObject::release()
{
	m_autoRelease = true;
}

bool SObject::isRelease() const
{
	return m_autoRelease;
}

void SObject::detached()
{
	m_autoRelease = false;
}

bool SObject::isDetached() const
{
	return !m_autoRelease;
}

void SObject::setObjectName(const std::string& objname)
{
	m_objectName = objname;
}

std::string SObject::objectName() const
{
	return m_objectName;
}

bool SObject::event(ExMessage* msg)
{
	return false;
}
