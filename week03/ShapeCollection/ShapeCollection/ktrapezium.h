#ifndef __K_TRAPEZIUM_H__
#define __K_TRAPEZIUM_H__

#include "kshape.h"

class KTrapezium : public KShape
{
public:
	KTrapezium();
	KTrapezium(std::string name);
	KTrapezium(std::string name, double base1, double base2, double height, double bias);
	virtual std::string getType(void) override;
	virtual double getPerimeter(void) override;
	virtual double getArea(void) override;

protected:
	double m_upperBase;	//�ϵ�
	double m_bottomBase;//�µ�
	double m_height;	//��
	double m_bias;		//���µ����ĵ�ƫ����
	double m_leftLeg;	//����
	double m_rightLeg;	//����
};

#endif
