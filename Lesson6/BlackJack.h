#pragma once
#include<vector>
#include<iostream>

using namespace std;

enum CardSuit
{
	club,
	spade,
	hearts,
	diamond
};

enum CardValue
{
	six = 6, seven, eight,
	nine, ten, ace, 
	jack = 2, queen, king
};

class Card
{
public:
	CardSuit suit;
	CardValue value;
	bool position;
	void Flip()
	{
		if (position)
			position = false;
		else
			position = true;
	}

	CardValue GetValue()
	{
		return value;
	}

	friend ostream& operator<< (ostream& out, const Card& card);
};

ostream& operator<< (ostream& out, const Card& card)
{
	if (card.position == false)
		out << "XX\n";
	else
	{
		switch (card.suit)
		{
		case(club):
			out << "clubs ";
			break;
		case(spade):
			out << "spades ";
			break;
		case(hearts):
			out << "hearts ";
			break;
		case(diamond):
			out << "diamonds ";
		}

		switch (card.value)
		{
		case(six):
			out << "6\n";
			break;
		case(seven):
			out << "7\n";
			break;
		case(eight):
			out << "8\n";
			break;
		case(nine):
			out << "9\n";
			break;
		case(ten):
			out << "10\n";
			break;
		case(jack):
			out << "J\n";
			break;
		case(queen):
			out << "Q\n";
			break;
		case(king):
			out << "K\n";
			break;
		case(ace):
			out << "A\n";
		}
	}
	return out;
}

class Hand
{
public:
	std::vector<Card*> card;

	void Add(Card* newCard)
	{
		card.push_back(newCard);
	}

	void Clear()
	{
		card.clear();
	}

	int GetValue()const
	{
		int sumCard{};
		for (int i{}; i < card.size(); i++)
		{
			sumCard += card[i]->GetValue();
		}
		return sumCard;
	}
};

class GenericPlayer : public Hand
{
public:
	std::string name;

	virtual bool isHitting() = 0;

	bool isBoosted()
	{
		if (this->GetValue() > 21)
			return true;
		
		return false;
	}

	void Busted()
	{
		std::cout << "Player " << name << " busted!\n";
	}

	friend ostream& operator<< (ostream& out, const GenericPlayer& gp);
	
};

ostream& operator<<(ostream& out,const GenericPlayer& gp)
	{
		out << gp.name << '\n';
		for (int i{}; i < gp.card.size(); ++i)
		{
			out << gp.card[i]<<' ';
		}
		cout << " sum of points: " << gp.GetValue() << '\n';

		return out;
	}

class Player : public GenericPlayer
{
public:
	virtual bool isHitting() const
	{
		std::cout << "Do you need a card? y/n:\n";
		char var;
		while(true)
		{
			cin.get(var);
			if (var != 'y' && var != 'Y' && var != 'n' && var != 'N')
			{
				std::cout << "Do you need a card? y/n:\n";
				continue;
			}
			else
				break;
		}
		
		if (var == 'y' || var == 'Y')
			return true;
		else
			return false;
	}

	void Win() const
	{
		std::cout << this->name << " you won!!!\n";
	}

	void Lose()const
	{
		std::cout << this->name << " you lost";
	}

	void Push()const
	{
		std::cout << this->name << " you played a draw";
	}
};

class House : public GenericPlayer
{
public:
	virtual bool isHitting() const
	{
		if (this->GetValue() < 16)
		{
			return true;
		}
		else
			return false;
	}

	void FlipFirstCard()
	{
		this->card[0]->Flip();
	}
};


