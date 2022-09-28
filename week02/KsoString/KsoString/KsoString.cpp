#include "KsoString.hpp"

int main()
{
	const wchar_t STR1[] = L"���пƼ���ѧ";
	const char STR2[] = "HUSTSOCST";

	cout << "���캯�����ԡ��������ԡ�����'='����:" << endl;
	KsoString<wchar_t> test01(STR1);
	KsoString<char> test02 = STR2;
	KsoString<char> test03(test02);
	KsoString<wchar_t> test04(7, 'A');
	//KsoString<int> test05("123456");  //������ģ������װ��������������
	
	test01.traverse();
	test02.traverse();
	test03.traverse();
	test04.traverse();

	cout << "������������, �пղ���:" << endl;
	test02.~KsoString();
	if (test02.empty())
		cout << "test02Ϊ��" << endl;

	cout << "������ԣ�" << endl;
	test04.insert(4, 'B');
	test04.traverse();

	cout << "ɾ�����ԣ�" << endl;
	test04.erase(5);
	test04.traverse();
	
	cout << "��β��ɾ���ԣ�"<<endl;
	wcout << test01.pop_front() << endl;
	wcout << test01.pop_back() << endl;
	test01.traverse();

	test01.push_front(L'��');
	test01.push_back(L'ѧ');
	test01.traverse();
	
	cout << "������Ȳ��ԣ�" << endl;
	cout << "test01�ĳ���Ϊ��" << test01.size() << endl;

	cout << "����[]���ԣ�" << endl;
	for (int i = 0; i < test03.size(); i++) 
	{
		cout << test03[i] << ' ';
	}
	cout << endl;

	cout << "���������ԣ�" << endl;
	KsoString<char>::iterator it;
	for (it = test03.getHead(); it != test03.getTail(); it++)
	{
		cout << *it << ' ';
	}
	cout << *it << endl;
	return 0;
}