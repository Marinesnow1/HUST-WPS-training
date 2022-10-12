#include "ktrapezium.h"

KTrapezium::KTrapezium() :
	KShape("Trapezium")
{
}
KTrapezium::KTrapezium(std::string name):
	KShape("Trapezium")
{
	m_name.append(name);
}
KTrapezium::KTrapezium(std::string name, double base1, double base2, double height, double bias):
	KShape("Trapezium")
{
	m_name.append(name);
	if (base1 > 0 && base2 > 0 && height > 0)
	{
		//ʹ����4�����������Σ���֤Ψһ�Ժ��걸��
		m_upperBase = std::min(base1, base2);
		m_bottomBase = std::max(base1, base2);
		m_height = height;
		m_bias = bias;
		//Ȼ��������������
		m_leftLeg = std::sqrt(std::pow(0.5 * (m_bottomBase - m_upperBase) - bias, 2) + std::pow(height, 2));
		m_rightLeg = std::sqrt(std::pow(0.5 * (m_bottomBase - m_upperBase) + bias, 2) + std::pow(height, 2));
	}
	else
	{
		m_upperBase = m_bottomBase = m_height = m_bias = m_leftLeg = m_rightLeg = 0;
	}
}
std::string KTrapezium::getType()
{
	return m_name;
}
double KTrapezium::getArea(void)
{
	return  0.5 * (m_bottomBase + m_upperBase) * m_height;
}
double KTrapezium::getPerimeter(void)
{
	return m_leftLeg + m_rightLeg + m_upperBase + m_bottomBase;
}