#ifndef _SOBJECT_H_
#define _SOBJECT_H_
#include"Configer.h"
class SObject;
using SObjectList = std::vector<SObject*>;
class SObject
{
public:
	SObject(SObject*parent = nullptr);
	virtual ~SObject();
	//设置孩子自动释放
	void release();
	bool isRelease()const;
	//取消自动释放
	void detached();
	bool isDetached() const;

	void setObjectName(const std::string& objname);
	std::string objectName()const;

	virtual bool event(ExMessage* msg);
private:
	SObjectList m_children;	//孩子列表
	SObject* m_parent;					//父亲
	bool m_autoRelease;					//是否自动释放（通过这个对象树来管理）
	std::string m_objectName;			//对象名
};



#endif