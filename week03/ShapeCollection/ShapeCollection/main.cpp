#include "kcompoundshapefactory.h"
#include "krectanglefactory.h"
#include "kroundfactory.h"
#include "ksquarefactory.h"
#include "ktrianglefactory.h"
#include "ktrapeziumfactory.h"

int main()
{
	KShapeFactory* refactory = new KRectangleFactory;
	KShapeFactory* rofactory = new KRoundFactory;
	KShapeFactory* sqfactory = new KSquareFactory;
	KShapeFactory* trafactory = new KTrapeziumFactory;
	KShapeFactory* trifactory = new KTriangleFactory;
	KShapeFactory * cfactory = new KCompoundShapeFactory;

	//���Ծ���
	KShape* rectangle = refactory->produceRectangle("01", 2.0, 3.0);
	std::cout << "���ƣ�" << rectangle->getType() << "\t�ܳ���" << rectangle->getPerimeter() << "\t�����" << rectangle->getArea() << std::endl;

	//����Բ
	KShape* round = rofactory->produceRound("01", 1.0);
	std::cout << "���ƣ�" << round->getType() << "\t�ܳ���" << round->getPerimeter() << "\t�����" << round->getArea() << std::endl;

	//����������
	KShape* square = sqfactory->produceSquare("01", 3.0);
	std::cout << "���ƣ�" << square->getType() << "\t�ܳ���" << square->getPerimeter() << "\t�����" << square->getArea() << std::endl;

	//��������
	KShape* trapezium = trafactory->produceTrapezium("01", 3.0, 4.0, 3.0, 0.5);
	std::cout << "���ƣ�" << trapezium->getType() << "\t�ܳ���" << trapezium->getPerimeter() << "\t�����" << trapezium->getArea() << std::endl;

	//����������
	KShape* triangle = trifactory->produceTriangle("01", 3.0, 4.0, 5.0);
	std::cout << "���ƣ�" << triangle->getType() << "\t�ܳ���" << triangle->getPerimeter() << "\t�����" << triangle->getArea() << std::endl;

	//���Ժϳ�ͼ��
	std::vector<KShape*> shapes;
	shapes.push_back(rectangle);
	shapes.push_back(square);
	shapes.push_back(round);
	KShape* compoundShape = cfactory->produceCompound("01", shapes);
	std::cout << "���ƣ�" << compoundShape->getType() << "\t�ܳ���" << compoundShape->getPerimeter() << "\t�����" << compoundShape->getArea() << "\t��ͼ��������" << ((KCompoundShape*)compoundShape)->showComponentNumber() << "\t��ͼ�Σ�";
	((KCompoundShape*)compoundShape)->showComponent();

	delete rectangle;
	delete round;
	delete square;
	delete trapezium;
	delete triangle;
	delete compoundShape;

	delete refactory;
	delete refactory;
	delete rofactory;
	delete sqfactory;
	delete trafactory;
	delete trifactory;
	delete cfactory;

	return 0;
}