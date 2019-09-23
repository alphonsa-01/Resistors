#include<cstdlib>
#include<iomanip>

#include "resistor.h"

/*!
	\brief The standard nwacc namespace.
	The namespace used for all nwacc application code.
*/

namespace nwacc
{
	/*!
		/brief The divisor we use to get the tolerance value, which is (100.0) as tolerance is in percent.
	*/
	const double resistor:: k_tolerance_divisor = 100.0;
	/*!
		\brief The added we use to get the random resistance value in a range, which is (1).
	*/
	const int resistor::k_random_resistance_addend = 1;
	/*!
		\brief The Divisor used to get the first digit of nominal resistance, it equals to (10).
	*/
	const int resistor::k_first_digit_divisor = 10;
	/*!
		\brief The divisor used in the modulo operation used to get the first and second digits of nominal resistance. it is (10).
	*/
	const int resistor::k_mod_divisor = 10;
	
	/*!
	\brief The ten significant digits of resistance bands, these determine the first and second digits of nominal resistance. Which ranges from 0 to 9.
	*/
	 const int resistor:: k_resistor_digit_zero = 0;
	 const int resistor::k_resistor_digit_one = 1;
	 const int resistor::k_resistor_digit_two = 2;
	 const int resistor::k_resistor_digit_three = 3;
	 const int resistor::k_resistor_digit_four = 4;
	 const int resistor::k_resistor_digit_five = 5;
	 const int resistor::k_resistor_digit_six = 6;
	 const int resistor::k_resistor_digit_seven = 7;
	 const int resistor::k_resistor_digit_eight = 8;

	 /*!
		\brief The multiplier values, which range from 10^0 to 10^-2
	 */
	const double resistor::k_multiplier_zero = 0;
	const double resistor::k_multiplier_one = 10;
	const double resistor::k_multiplier_two = 100;
	const double resistor::k_multiplier_three = 1000;
	const double resistor::k_multiplier_four = 10000;
	const double resistor::k_multiplier_five = 100000;
	const double resistor::k_multiplier_six = 1000000;
	const double resistor::k_multiplier_seven = 10000000;
	const double resistor::k_multiplier_eight = 100000000;
	const double resistor::k_multiplier_nine = 1000000000;
	const double resistor::k_multiplier_neg_one = 0.1;
	
	/*!
		\brief The tolerance values, the values are +/-1%, +/-2%, +/-0.5%, +/-0.25%, +/-0.1%, +/-0.05%, +/-5%, +/-10%, +/-20%,
	*/
	const double resistor::k_tolerance_one = 1;
	const double resistor::k_tolerance_two = 2;
	const double resistor::k_tolerance_three = 0.5;
	const double resistor::k_tolerance_four = 0.25;
	const double resistor::k_tolerance_five = 0.1;
	const double resistor::k_tolerance_six = 0.05;
	const double resistor::k_tolerance_seven = 5.0;
	const double resistor::k_tolerance_eight = 10.0;
	
	/*!
		\brief Creates an instance of the resistor with specified nominal resistance, multiplier and tolerance values.
		\param nominal resistance -nominal resistance value  of the resistor
				multiplier- multiplier value of the resistor of this instancce.
				tolerance- tolerance value of this instance.
	*/
	resistor::resistor(const double nominal_resistance, const double multiplier, const double tolerance)
	{
		this->set_nominal_resistance(nominal_resistance);
		this->set_multiplier(multiplier);
		this->set_tolerance(tolerance);
	}
	
	/*!
		\brief prints output stream to the console
		\param functions to print to the console
			get_actual_resistance() ,get_description_first_band(),get_description_second_band(),get_description_multiplier(),get_description_tolerance()
		*/
	void resistor::print(std::ostream& out) const
	{
		out << std::fixed << std::showpoint<<std::setprecision(2);
		out << "Actual resistance"<<"- "<<this->get_actual_resistance() << " Ohm" << std::endl; 
		out << "First Band" <<"- " << this->get_description_first_band() << std::endl;
		out << "Second Band"<<"- "<<this->get_description_second_band() << std::endl;
		out << "Multiplier" << "- " << this->get_description_multiplier() << std::endl;
		out << "Tolerance" << "- " << this->get_description_tolerance() << std::endl;
	}

	/*!
		\brief Gets the nominal resistance of this instance.
		/return The nominal resistance of this instance
	*/
	double resistor::get_nominal_resistance() const
	{
		return this->nominal_resistance_;
	}

	/*!
		\brief Gets the tolerance of this instance
		\return The tolerancce of this instance
	*/
	double resistor::get_tolerance() const
	{
		return this->tolerance_;
	}

	/*!
		\brief Gets the actual resistance of this instance.
		calculates and returns the actual resistance of this instance, actual resitance can vary between +/- tolerance,
		here actual resistance is determined from a random value between the acceptable range
		\return returns the actual resistance of this instance.
	*/
	double resistor::get_actual_resistance() const
	{
		double tolerance_value = this->nominal_resistance_ * (this->tolerance_ /k_tolerance_divisor);
		double actual_resistance_min = this->nominal_resistance_ - tolerance_value;
		double actual_resistance_max = this->nominal_resistance_ + tolerance_value;
		double random_actual_resistance = actual_resistance_min + (rand() % static_cast<int>((actual_resistance_max - actual_resistance_min) + k_random_resistance_addend));
		return random_actual_resistance*this->multiplier_;
	}

	/*!
		\brief Gets the description of the first band of this instance.
			determines the color of the first band from the first digit of the nominal resistance.
		\return returns the colour of the first band of this instance.
	*/
	std::string resistor::get_description_first_band() const
	{
		int first_digit = static_cast<int>(this->nominal_resistance_/k_first_digit_divisor) % k_mod_divisor;

		if (first_digit == k_resistor_digit_zero)
		{
			return "Black";
		}
		else if(first_digit==k_resistor_digit_one)
		{
			return "Brown";
		}
		else if (first_digit == k_resistor_digit_two)
		{
			return "Red";
		}
		else if (first_digit == k_resistor_digit_three)
		{
			return "Orange";
		}
		else if (first_digit == k_resistor_digit_four)
		{
			return "Yellow";
		}
		else if (first_digit == k_resistor_digit_five)
		{
			return "Green";
		}
		else if (first_digit == k_resistor_digit_six)
		{
			return "Blue";
		}
		else if (first_digit == k_resistor_digit_seven)
		{
			return "Violet";
		}
		else if (first_digit == k_resistor_digit_eight)
		{
			return "Gray";
		}
		else
		{
			return "White";
		}
	}

	/*!
		\brief Gets the description of the second band of this instance.
			determines the color of the second band from the second digit of the nominal resistance.
		\return returns the color of the second band of this instance.
	*/
	std::string resistor::get_description_second_band() const
	{
		int second_digit = static_cast<int>(this->nominal_resistance_) % k_mod_divisor;

		if (second_digit == k_resistor_digit_zero)
		{
			return "Black";
		}
		else if (second_digit == k_resistor_digit_one)
		{
			return "Brown";
		}
		else if (second_digit == k_resistor_digit_two)
		{
			return "Red";
		}
		else if (second_digit== k_resistor_digit_three)
		{
			return "Orange";
		}
		else if (second_digit == k_resistor_digit_four)
		{
			return "Yellow";
		}
		else if (second_digit == k_resistor_digit_five)
		{
			return "Green";
		}
		else if (second_digit == k_resistor_digit_six)
		{
			return "Blue";
		}
		else if (second_digit == k_resistor_digit_seven)
		{
			return "Violet";
		}
		else if (second_digit == k_resistor_digit_eight)
		{
			return "Gray";
		}
		else
		{
			return "White";
		}

	}

	/*!
		\brief Gets the description of the multiplier band of this instance.
			Determine the color of third band from the value of the multiplier
		\return returns the color of the third band of this instance.
	*/
	std::string resistor::get_description_multiplier() const
	{
		if (this->multiplier_ == k_multiplier_zero)
		{
			return "Black";
		}
		else if (this->multiplier_ == k_multiplier_one)
		{
			return "Brown";
		}
		else if (this->multiplier_==k_multiplier_two)
		{
			return "Red";
		}
		else if (this->multiplier_ == k_multiplier_three)
		{
			return "Orange";
		}
		else if (this->multiplier_ == k_multiplier_four)
		{
			return "Yellow";
		}
		else if (this->multiplier_ == k_multiplier_five)
		{
			return "Green";
		}
		else if (this->multiplier_ == k_multiplier_six)
		{
			return "Blue";
		}
		else if (this->multiplier_ == k_multiplier_seven)
		{
			return "Violet";
		}
		else if (this->multiplier_ == k_multiplier_eight)
		{
			return "Gray";
		}
		else if(this->multiplier_==k_multiplier_nine)
		{
			return "White";
		}
		else if (this->multiplier_ == k_multiplier_neg_one)
		{
			return "Gold";
		}
		else
		{
			return "Silver";
		}
	}

	/*!
		\brief Gets the description of the tolerance band of this instance
			determines the color of the fourth band from the value of tolerance.
		\return returns the color of the fourth band of this instance.
	*/
	std::string resistor::get_description_tolerance() const
	{
		if (this->get_tolerance() == k_tolerance_one)
		{
			return "Brown";
		}
		else if (this->get_tolerance() == k_tolerance_two)
		{
			return "Red";
		}
		else if (this->get_tolerance() == k_tolerance_three)
		{
			return "Green";
		}
		else if (this->get_tolerance() == k_tolerance_four)
		{
			return "Blue";
		}
		else if (this->get_tolerance() == k_tolerance_five)
		{
			return "Violet";
		}
		else if (this->get_tolerance() == k_tolerance_six)
		{
			return "Gray";
		}
		else if (this->get_tolerance() == k_tolerance_seven)
		{
			return "Gold";
		}
		else if (this->get_tolerance() == k_tolerance_eight)
		{
			return "Silver";
		}
		else
		{
			return "None";
		}
	}

	/*!
		\brief sets the value of nominal resistance of this instance.
		\param nominal resistance of this instance.
	*/
	void resistor::set_nominal_resistance(const double nominal_resistance)
	{
		this->nominal_resistance_ = nominal_resistance;
	}

	/*!
		\brief sets the value of multiplier of this instance.
		\param multiplier of this instance.
	*/
	void resistor::set_multiplier(const double multiplier)
	{
		this->multiplier_ = multiplier;
	}

	/*!
		\brief sets the value of tolerance of this instance.
		\param tolerance of this instance.
	*/
	void resistor::set_tolerance(const double tolerance)
	{
		this->tolerance_ = tolerance;
	}

}