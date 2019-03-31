
#include  <iostream>

#define DEBUG 1;

using namespace std;

static unsigned get_number_at_position(unsigned position, unsigned const factors[]);
static bool can_be_factored(unsigned number, unsigned const factors[]);

int main()
{
	static constexpr unsigned POSITION = 18;
	static constexpr unsigned FACTORS[] = { 2, 3, 5 };

	auto const number = get_number_at_position(POSITION, FACTORS);
	cout << "The number at position " << POSITION << " is " << number << "\n";
	return 0;
}


unsigned get_number_at_position(unsigned const position, unsigned const factors[])
{
	unsigned number = 1;

	for (auto i = 1; i <= position; ++i)
	{
		// Check to see if the number can be factored
		if (can_be_factored(number, factors))
		{

#if DEBUG
			std::cout << "Position " << i << ": " << number << "\n";
#endif

			if (i == position)
			{
				break;
			}
		}
		else
		{
			// Else if 
			--i;
		}
		++number;
	}

	return number;
}


// Recursive function
bool can_be_factored(unsigned number, unsigned const factors[])
{
	// The end case of recursive function
	if (number == 1)
	{
		return true;
	}

	// Loop through each factor
	for (auto const factor : FACTORS)
	{
		// Check to see if the given number can be divided by the factor without remainder
		if (number % factor != 0)
		{
			// Use reverse logic here to reduce nested if statement(s)
			continue;
		}

		// If "factor" is really a factor of the number, call can_be_factored again with number divided by that factor
		return can_be_factored(number / factor, factors);
	}
	return false;
}
