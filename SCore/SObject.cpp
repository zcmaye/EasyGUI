#include "SObject.h"

SObject::SObject(SObject* parent)
	:m_parent(parent)  //如果由父亲,指向父对象
{
	if (parent)
	{					
		m_parent->m_children.push_back(this);	//把this添加到父对象的孩子列表
	}
	printf("Sobject create %s\n",objectName().c_str());
	release();
}

SObject::~SObject()
{
	printf("Sobject destory %s\n", objectName().c_str());
	//对象销毁的时候
	//1,把自己从父对象中移除掉
	if (m_parent)
	{
		auto& pchild = m_parent->m_children;
		auto it = std::find(pchild.begin(), pchild.end(),this);
		if (it != pchild.end())
			m_parent->m_children.erase(it);
	}
	//2,把自己和孩子都释放掉
	//2.1 先清空孩子列表(释放)
	for (auto obj : this->m_children)
	{
		if(obj->isRelease())
			delete obj;
	}
	m_children.clear();
	//2.2 释放自己
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
