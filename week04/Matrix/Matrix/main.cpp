#include "kmatrix.cpp"
using namespace std;

int main()
{
    KMatrix<int> a(3, 3);
    a.setData(1, 1, 1);
    a.setData(1, 2, 1);
    a.setData(2, 3, 1);
    a.setData(3, 3, 1);
    cout << "a����(int��)��" << endl;
    a.print();
    cout << endl;

    cout << "a����(2, 2)����ֵ��" << endl << a.getData(2, 2) << endl;
    cout << "a����(1, 2)����ֵ��" << endl << a.getData(1, 2) << endl;
    cout << endl;

    cout << "a������������ֱ�Ϊ��" << a.getRows() << ", " << a.getCols() << endl << endl;

    KMatrix<int> b(a);
    cout << "b����(int��)��" << endl;
    b.print();
    cout << endl;
    
    cout << "b + a ��" << endl;
    KMatrix<int> add = b + a;
    add.print();
    cout << endl;

    cout << "b - a ��" << endl;
    KMatrix<int> sub = b - a;
    sub.print();
    cout << endl;

    cout << "a��ת�ã�" << endl;
    KMatrix<int> trans = a.transpose();
    trans.print();
    cout << endl;

    cout << "a * b ��" << endl;
    KMatrix<int> mul1 = a * b;
    mul1.print();
    cout << endl;

    KMatrix<double> c(4, 4);
    c.setData(1, 1, 0.1);
    c.setData(2, 2, 0.2);
    c.setData(3, 3, 0.3);
    c.setData(4, 4, 0.4);
    cout << "c����" << endl;
    c.print();

    c.eraseRow(2);
    cout << "ȥ���ڶ��е�c����" << endl;
    c.print();
    cout << endl;
    
    c.eraseCol(2);
    cout << "ȥ���ڶ��е�c����" << endl;
    c.print();
    cout << endl;
    
    cout << "�������c�������������Ԫ�����ݣ�" << endl;
    for (auto it = c.begin(); it != c.end(); it++) 
    {
        cout << "(" << get<0>(*it) << ", " << get<1>(*it) << ", " << get<2>(*it) << ")" << endl;
    }
    cout << endl;
}
