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
	//���ú����Զ��ͷ�
	void release();
	bool isRelease()const;
	//ȡ���Զ��ͷ�
	void detached();
	bool isDetached() const;

	void setObjectName(const std::string& objname);
	std::string objectName()const;

	virtual bool event(ExMessage* msg);
private:
	SObjectList m_children;	//�����б�
	SObject* m_parent;					//����
	bool m_autoRelease;					//�Ƿ��Զ��ͷţ�ͨ�����������������
	std::string m_objectName;			//������
};



#endif