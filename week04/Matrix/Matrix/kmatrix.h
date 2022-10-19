#ifndef __K_MATRIX_H__
#define __K_MATRIX_H__

#include <iostream>
#include <vector>
#include <tuple>
#include <cassert>
#include "vld.h"
using namespace std;

template <typename T>
class KMatrix
{
public:
	KMatrix();													//Ĭ�Ϲ��캯��
	KMatrix(int row = 0, int column = 0);						//���������캯��
	KMatrix(const KMatrix<T>& matrix);							//���ƹ��캯��
	void init(int row, int column);								//��ʼ��������Ϣ
	int getRows() const;										//�������
	int getCols() const;										//�������
	void setData(int row, int col, T value);					//����ֵ
	T getData(int row, int col);								//�õ�ֵ
	void eraseRow(int row);										//ɾ����
	void eraseCol(int col);										//ɾ����

	auto begin() const;											//��ʼ������
	auto end() const;											//����������

	KMatrix<T> operator+(const KMatrix<T>& b);					//��
	KMatrix<T> operator-(const KMatrix<T>& b);					//��
	KMatrix<T> operator*(const KMatrix<T>& b);					//��
	KMatrix<T> transpose() const;								//ת��
	void print() const;											//��ӡ���

private:
	int m_rows;													//����								
	int m_columns;												//����
	vector <tuple<int, int, T>> m_matrix;						//��Ԫ�飨�кţ��кţ�ֵ��
	vector <int> m_rowIndex;									//��¼������ÿ�е�һ����0Ԫ����m_matrix�е�λ��
};

#endif 
