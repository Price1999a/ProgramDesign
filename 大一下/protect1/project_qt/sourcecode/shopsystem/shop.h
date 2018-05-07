#pragma once
#include "struct.h"

class CStock//�����
{
	friend class CShoppingCart;
protected:
	Commodity stocklist[100];//�����������100����¼
public:
	CStock() {
		memset(&stocklist[0], 0, 100 * sizeof(Commodity));//���ᱻ�̳�
		readstockfile();
	}
	void readstockfile();//��ȡ����ļ���ʼ��CStock��
	void printadminstocklist();//��ӡ����Ա����������ƷĿ¼����ʾΪ����Ϊ0����Ʒ��
	void printusersstocklist();//��ӡ�û�����������ƷĿ¼������ʾ����Ϊ0����Ʒ��//�ֱ����ﳵ��̳� ���ڲ鿴���ﳵ
	void addstocklist();//����Ʒ�б���������Ʒ
	void changeadminstocklist();//�޸���Ʒ��Ϣ���ر�ģ���ָ�޸���Ʒ��������
	void deletestocklist();//����Ʒ�б���ɾ��ĳһ��Ʒ����Ϊ��������Ϊ-1��//�����ﳵ��̳�  ����ɾ�����ﳵ����Ʒ
	void searchusersstocklist();//�û����ܣ����Բ�ѯ��Ʒ������
	void writeinstockfile();//��Ŀǰ�ڴ��ļ�����д���ļ�//�����̳У�����Ԥ�ƽ���Ƶ�����ã����������ͳһд���ڴ棬�޸Ľ�������ʵʱ�ģ�
};

class CShoppingCart: public CStock//���ﳵ��̳��Կ����
{
public:
	CShoppingCart() {
		memset(&stocklist, 0, 100 * sizeof(Commodity));
	}
	void readshoppingcartfile(User);//��ȡ��ǰ�û��Ĺ��ﳵ�ļ�д���ڴ棨�����ڵ�ǰ�û����ṩ���û�����
	void writeinshopplingcartfile(User);//��Ŀǰ���ﳵ�ļ�����д���ļ�
	bool checkshoppingcartrequest();//��鹺�ﳵ�Ƿ��ޣ����޸�ʱ��飬���糬�ޣ��ܾ�����
	void cleanusershoppingcart() {
		memset(&stocklist, 0, 100 * sizeof(Commodity));
	}//�����ﳵ�����ڹ����
	void writeinsoldlistfile(User a);//д�������嵥
	void modifystocklistfile();//�޸Ŀ���ļ�
	void addshoppingcart();
	void freshshoppingcart();
	bool sumprice();//�����ܼ�
};

class CSoldlist//�����嵥 ���ܣ���ӡ�����嵥 ע���������嵥��д��һ���ɹ��ﳵ�ฺ��ԭ�����������嵥�ļ�����׷�ӷ�ʽд��
{
private:
	Soldlist soldlist[2000];//����������2000����¼������ͬ�������Լ�С��
public:
	CSoldlist() {
		memset(&soldlist, 0, 2000 * sizeof(Soldlist));
	}
	void printsoldlist();//��ӡ�����嵥  ע���ȼ��id�Ƿ�Ϊ�գ����ǿգ�Ҫ���䲻����ʾ
	void readsoldlist();//��ȡ�Լ��ϲ�(ͬ�۸�ͬ��Ʒ)�����嵥  �������qsort����
	static int compare(const void *a, const void *b);//ע�⣡Ҫ������  �ٴ�ע�⣡��δ���Թ�����Ԥ�ϵ�strcmp�Կ��ַ�������Ϊ�ǽ�����Ϊ��С��
};
