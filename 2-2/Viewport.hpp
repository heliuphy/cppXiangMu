//
// Viewport.hpp
// TinyCS
//

#ifndef Viewport_hpp
#define Viewport_hpp

#include "Viewport.hpp"
class Viewport
{
public:
	//���ָ���Ƿ���ʾ
	static bool grabbed;
	//�ӽǿ��
	static int width;
	//�ӽǸ߶�
	static int height;
	//�����ĳ�ʼ��
	static void init();
	//���ô��ڿɵ���
	static void reshape(int w,int h);
	//������ʾ
	static void display();
	//�������ָ���Ƿ���ʾ
	static void setGrabbed(bool value);

};
#endif /* Viewport_hpp */