#pragma once
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
//˫������
template <class T>
struct DNode
{
	T val;
	DNode* prior = nullptr;
	DNode* next = nullptr;

	DNode() : val(0), prior(nullptr), next(nullptr) {}
	DNode(T x) : val(x), prior(nullptr), next(nullptr) {}
	DNode(T x, DNode* prior, DNode* next) : val(x), prior(prior), next(next) {}
};
//�ַ���������
template <class T>
class KsoString
{
public:
	class iterator
	{
	public:
		iterator(){}
		iterator(DNode<T>* p) :it(p) {}
		//ǰ����������
		iterator& operator++()
		{
			it = it->next;
			return *this;
		}
		//������������
		iterator operator++(int)
		{
			iterator tmp = *this;
			++(*this);
			return tmp;
		}
		//ǰ���Լ�����
		iterator& operator--()
		{
			it = it->prior;
			return *this;
		}
		//�����Լ�����
		iterator operator--(int)
		{
			iterator tmp = *this;
			--(*this);
			return tmp;
		}
		//������
		bool operator!=(KsoString<T>::iterator p)
		{
			if (this->it == p.it)
				return false;
			else
				return true;
		}
		//�����ã�����ȡ������ָ���Ԫ��
		T& operator*()
		{
			return it->val;
		}
	private:
		DNode<T>* it;
	};

	KsoString();                                        //Ĭ�Ϲ��캯��
	KsoString(const T*);							    //�ַ������캯��
	KsoString(const KsoString<T>& str);				    //�������캯��
	KsoString(int n, T val);							//����n����ͬ�ַ��Ĺ��캯��
	~KsoString();									    //��������
	void insert(int pos, T val);					    //�����ַ�
	void erase(int pos);							    //ɾ���ַ�
	bool empty();									    //�ж��ַ����Ƿ�Ϊ��
	void push_front(T val);							    //�ײ�
	void push_back(T val);							    //β��
	T pop_front();									    //��ɾ
	T pop_back();									    //βɾ
	int size() const;								    //����ַ�����С
	void traverse() const;							    //�������
	T operator[](int index);							//����[]
	KsoString& operator=(const KsoString& str);			//����=

	KsoString<T>::iterator getHead()
	{
		KsoString<T>::iterator begin(m_head);
		return begin;
	}
	KsoString<T>::iterator getTail()
	{
		KsoString<T>::iterator end(m_tail);
		return end;
	}
private:
	DNode<T>* m_head = nullptr; //�ַ�����ͷ
	DNode<T>* m_tail = nullptr; //�ַ�����β
	int m_len = 0;				//�ַ����ĳ���
};

template <class T>
KsoString<T>::KsoString()
{
	if (typeid(T) != typeid(char) && typeid(T) != typeid(wchar_t))
		assert(false);
}
template <class T>
KsoString<T>::KsoString(const T* str)
{
	if (typeid(T) != typeid(char) && typeid(T) != typeid(wchar_t))
		assert(false);
	m_head = new DNode<T>(str[0]);
	DNode<T>* p = m_head;
	int i;
	for (i = 1; str[i] != 0; i++)
	{
		DNode<T>* newNode = new DNode<T>(str[i]);
		p->next = newNode;
		newNode->prior = p;
		p = p->next;
	}
	p->next = nullptr;
	m_tail = p;
	m_len = i;
}
template <class T>
KsoString<T>::KsoString(const KsoString<T>& str)
{
	if (typeid(T) != typeid(char) && typeid(T) != typeid(wchar_t))
		assert(false);
	if (str.m_len!=0) 
	{
		m_len = str.m_len;
		DNode<T>* p = str.m_head;
		m_head = new DNode<T>(p->val, nullptr, nullptr);
		m_tail = m_head;
		p = p->next;
		while (p!=nullptr)
		{
			m_tail->next = new DNode<T>(p->val, m_tail, nullptr);
			m_tail = m_tail->next;
			p = p->next;
		}
	}
}
template <class T>
KsoString<T>::KsoString(int n, T val)
{
	m_head = new DNode<T>(val);
	m_tail = m_head;
	for (int i = 1; i < n; i++)
	{
		DNode<T>* newNode = new DNode<T>(val, m_tail, nullptr);
		m_tail->next = newNode;
		m_tail = m_tail->next;
	}
	m_len = n;
}
template <class T>
KsoString<T>& KsoString<T>::operator=(const KsoString& str) 
{
	~KsoString();
	KsoString temp(str);
	this = &temp;
	return *this;
}
template <class T>
KsoString<T>::~KsoString()
{
	if (!empty())
	{
		DNode<T>* p = m_head;
		while (p->next != nullptr)
		{
			p = p->next;
			delete p->prior;
			p->prior = nullptr;
		}
		delete p;
		p = nullptr;
	}
	else
	{
		m_head = nullptr;
		m_tail = nullptr;
	}
	m_len = 0;
}
template <class T>
void KsoString<T>::insert(int pos, T val)
{

	DNode<T>* newNode = new DNode<T>(val);
	if (pos == 0)
	{
		push_front(val);
	}
	else if (pos > 0 && pos < m_len)
	{
		DNode<T>* p = m_head;
		for (int i = 1; i < pos; i++)
		{
			p = p->next;
		}
		newNode->prior = p;
		newNode->next = p->next;
		p->next->prior = newNode;
		p->next = newNode;
		m_len++;
	}
	else if (pos == m_len)
	{
		push_back(val);
	}
	else
	{
		cout << "Warning: �±곬���ַ�����Χ��";
	}
}

template <class T>
void KsoString<T>::erase(int pos) 
{
	if (empty()) 
	{
		cout << "Warning: �մ�����ɾ���ַ���";
	}
	else if (pos == 1)
	{
		pop_front();
	}
	else if (pos > 1 && pos < m_len)
	{
		DNode<T>* p = m_head;
		for (int i = 2; i < pos; i++)
		{
			p = p->next;
		}
		DNode<T>* q = p->next;
		q->next->prior = p;
		p->next = q->next;
		delete q;
		m_len--;
	}
	else if (pos == m_len)
	{
		pop_back();
	}
	else
	{
		cout << "Warning: �±곬���ַ�����Χ��";
	}
}
template <class T>
bool KsoString<T>::empty() 
{
	if (m_len == 0)
		return true;
	else
		return false;
}
template <class T>
void KsoString<T>::push_front(T val)
{
	if (empty())
	{
		m_head = m_tail = new DNode<T>(val);
	}
	else
	{
		m_head->prior = new DNode<T>(val, nullptr, m_head);
		m_head = m_head->prior;
	}
	m_len++;
}
template <class T>
void KsoString<T>::push_back(T val) 
{
	if (empty())
	{
		m_head = m_tail = new DNode<T>(val);
	}
	else
	{
		m_tail->next = new DNode<T>(val, m_tail, nullptr);
		m_tail = m_tail->next;
	}
	m_len++;
}
template <class T>
T KsoString<T>::pop_front()
{
	if (empty()) 
	{
		return 0;
	}
	else 
	{
		T val = m_head->val;
		DNode<T>* p = m_head;
		m_head = m_head->next;
		m_head->prior = nullptr;
		delete p;
		p = nullptr;
		m_len--;
		return val;
	}
}
template <class T>
T KsoString<T>::pop_back() 
{
	if (empty())
	{
		return 0;
	}
	else 
	{
		T val = m_tail->val;
		DNode<T>* p = m_tail;
		m_tail = m_tail->prior;
		m_tail->next = nullptr;
		delete p;
		p = nullptr;
		m_len--;
		return val;
	}
}
template <class T>
int KsoString<T>::size() const 
{
	return m_len;
}
template <class T>
T KsoString<T>::operator[](int index) 
{
	if (index < 0 && index >= m_len || empty())
		return 0;
	else
	{
		DNode<T>* p = m_head;
		for (int i = 0; i < index; i++) 
		{
			p = p->next;
		}
		return p->val;
	}
}
template <class T>
void KsoString<T>::traverse() const
{
	DNode<T>* p = m_head;
	if (typeid(T) == typeid(char))
	{
		while (p != nullptr) {
			cout << p->val;
			p = p->next;
		}
	}
	else 
	{
		wcout.imbue(locale("chs"));
		while (p != nullptr) {
			wcout << p->val;
			p = p->next;
		}
	}
	cout << endl;
}


