#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"
#include "Field.h"

class Calculator
{
private:
	friend class Button;
	sf::RenderWindow window;
	sf::Font font;
	sf::Text text;
	Button* mc;
	Button* mr;
	Button* mplus;
	Button* mminus;
	Button* ms;
	Button* m;

	Button* percent;// �������
	Button* bce;//�������� ���
	Button* bc;//�������
	Button* back;//�������� ��������� ���������

	Button* divone;// ������� �������
	Button* deg;// �������
	Button* sqroot;// ������
	Button* bdiv;// �������

	Button* b0;
	Button* b1;
	Button* b2;
	Button* b3;
	Button* b4;
	Button* b5;
	Button* b6;
	Button* b7;
	Button* b8;
	Button* b9;

	Button* beq;//=
	Button* bmult;//*
	Button* bdif;//-
	Button* bsum;//+
	Button* plusminus;
	Button* point;

	Field* field;

	Button** panel;

public:
	Calculator();
	void run();

private:
	void eventState();
	void update();
	void render();

};

