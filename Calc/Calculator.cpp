#include "Calculator.h"

Calculator::Calculator()
	: window(sf::VideoMode(328, 535), L"Калькулятор")
{
	if (!font.loadFromFile("resources/fonts/arial.ttf"))
	{

		std::cout << "font not found";
	}

	field = new Field(400, 100, "0");
	field->setPosition(0, 0);

	mc = new Button(54.6, 27, "mc");
	mc->setPosition(0, 100);
	mr = new Button(54.6, 27, "mr");
	mr->setPosition(54.6, 100);
	mplus = new Button(54.6, 27, "m+");
	mplus->setPosition(109.2, 100);
	mminus = new Button(54.6, 27, "m-");
	mminus->setPosition(163.8, 100);
	ms = new Button(54.6, 27, "ms");
	ms->setPosition(218.4, 100);
	m = new Button(54.6, 27, "m");
	m->setPosition(273, 100);

	percent = new Button(82, 68, "%");
	percent->setPosition(0, 127);
	bce = new Button(82, 68, "ce");
	bce->setPosition(82, 127);
	bc = new Button(82, 68, " c");
	bc->setPosition(164, 127);
	back = new Button(82, 68, "<-");
	back->setPosition(246, 127);

	divone = new Button(82, 68, "1/x");
	divone->setPosition(0, 195);
	deg = new Button(82, 68, "x2");
	deg->setPosition(82, 195);
	sqroot = new Button(82, 68, "sqrt");
	sqroot->setPosition(164, 195);
	bdiv = new Button(82, 68, " /");
	bdiv->setPosition(246, 195);

	b7 = new Button(82, 68, "7");
	b7->setPosition(0, 263);
	b8 = new Button(82, 68, "8");
	b8->setPosition(82, 263);
	b9 = new Button(82, 68, "9");
	b9->setPosition(164, 263);
	bmult = new Button(82, 68, "X");
	bmult->setPosition(246, 263);

	b4 = new Button(82, 68, "4");
	b4->setPosition(0, 331);
	b5 = new Button(82, 68, "5");
	b5->setPosition(82, 331);
	b6 = new Button(82, 68, "6");
	b6->setPosition(164, 331);
	bdif = new Button(82, 68, "-");
	bdif->setPosition(246, 331);

	b1 = new Button(82, 68, "1");
	b1->setPosition(0, 399);
	b2 = new Button(82, 68, "2");
	b2->setPosition(82, 399);
	b3 = new Button(82, 68, "3");
	b3->setPosition(164, 399);
	bsum = new Button(82, 68, "+");
	bsum->setPosition(246, 399);
	
	plusminus = new Button(82, 68, "+/-");
	plusminus->setPosition(0, 467);
	b0 = new Button(82, 68, "0");
	b0->setPosition(82, 467);
	point = new Button(82, 68, ".");
	point->setPosition(164, 467);
	beq = new Button(82, 68, "=");
	beq->setPosition(246, 467);

	panel = new Button * [30]{ mc, mr, mplus, mminus, ms, m, percent, bce, bc, back, divone, deg, sqroot, bdiv, b7, b8, b9, bmult, b4, b5, b6, bdif, b1, b2, b3, bsum, plusminus, b0, point, beq };
}

void Calculator::run()
{
	while (window.isOpen())
	{
		eventState();
		update();
		render();
	}
}

void Calculator::eventState()
{
	sf::Event event;
	sf::Vector2i localPosition;
	while (window.pollEvent(event))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			localPosition = sf::Mouse::getPosition(window);
			//std::cout << localPosition.x << " " << localPosition.y << std::endl;
			while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
			}
			for (int i = 0; i < 30; i++)
			{
				if (i >= 6)
				{
					if (localPosition.x >= panel[i]->getPosition().x &&
						localPosition.x <= panel[i]->getPosition().x + 81 &&
						localPosition.y >= panel[i]->getPosition().y &&
						localPosition.y <= panel[i]->getPosition().y + 67)
					{
						panel[i]->push(field);
					}
				}
				else
				{
					if (localPosition.x >= panel[i]->getPosition().x &&
						localPosition.x <= panel[i]->getPosition().x + 54 &&
						localPosition.y >= panel[i]->getPosition().y &&
						localPosition.y <= panel[i]->getPosition().y + 26)
					{
						panel[i]->push(field);
					}
				}
			}


		}
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				std::cout << "Window was closed. Was pressed esc.";
				window.close();
			}
		}
		if (event.type == sf::Event::Closed) window.close();
	}
}

void Calculator::update()
{

	text.setString(L"Калькулятор2");
}

void Calculator::render()
{
	window.clear(sf::Color::White);

	window.draw(mc->getButton());
	window.draw(mc->getText2());
	window.draw(mr->getButton());
	window.draw(mr->getText2());
	window.draw(mplus->getButton());
	window.draw(mplus->getText2());
	window.draw(mminus->getButton());
	window.draw(mminus->getText2());
	window.draw(ms->getButton());
	window.draw(ms->getText2());
	window.draw(m->getButton());
	window.draw(m->getText2());

	window.draw(percent->getButton());
	window.draw(percent->getText());
	window.draw(bce->getButton());
	window.draw(bce->getText());
	window.draw(bc->getButton());
	window.draw(bc->getText());
	window.draw(back->getButton());
	window.draw(back->getText());

	window.draw(divone->getButton());
	window.draw(divone->getText());
	window.draw(deg->getButton());
	window.draw(deg->getText());
	window.draw(sqroot->getButton());
	window.draw(sqroot->getText());
	window.draw(bdiv->getButton());
	window.draw(bdiv->getText());


	window.draw(b7->getButton());
	window.draw(b7->getText());
	window.draw(b8->getButton());
	window.draw(b8->getText());
	window.draw(b9->getButton());
	window.draw(b9->getText());
	window.draw(bmult->getButton());
	window.draw(bmult->getText());



	window.draw(b4->getButton());
	window.draw(b4->getText());
	window.draw(b5->getButton());
	window.draw(b5->getText());
	window.draw(b6->getButton());
	window.draw(b6->getText());
	window.draw(bdif->getButton());
	window.draw(bdif->getText());


	window.draw(b1->getButton());
	window.draw(b1->getText());
	window.draw(b2->getButton());
	window.draw(b2->getText());
	window.draw(b3->getButton());
	window.draw(b3->getText());
	window.draw(bsum->getButton());
	window.draw(bsum->getText());

	window.draw(plusminus->getButton());
	window.draw(plusminus->getText());
	window.draw(b0->getButton());
	window.draw(b0->getText());
	window.draw(point->getButton());
	window.draw(point->getText());
	window.draw(beq->getButton());
	window.draw(beq->getText());

	window.draw(field->getField());
	window.draw(field->getText());

	window.draw(text);
	window.display();
}

