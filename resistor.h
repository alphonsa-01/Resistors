#ifndef RESISTOR_H_
#define RESISTOR_H_

#include<iostream>

/*!
	\brief The standard nwacc namespace.
	The namespace used for all nwacc application code.
*/

namespace nwacc
{
	/*!
	\brief Represents resistor with nominal resistance,multiplier and tolerance and methods to determine the state of resistor.

	Represents resistors in real world. Resistance is determined based on the color bands on them. Resistor has a nominal resistance which is determined from the 
	first and second digits and multiplied by multiplier value. The resistor has a tolerance percent which indicates the acceptable variation in the resistance.
	This class contains methods to determine the actual resitance and also the display of colour bands.
	*/
	class resistor
	{
	public:
		/*!
			/brief The divisor we use to get the tolerance value, which is (100.0) as tolerance is in percent. 
		*/
		static const double k_tolerance_divisor;
		/*!
			\brief The added we use to get the random resistance value in a range, which is (1).
		*/
		static const int k_random_resistance_addend;
		/*!
			\brief The Divisor used to get the first digit of nominal resistance, it equals to (10).
		*/
		static const int k_first_digit_divisor;
		/*!
			\brief The divisor used in the modulo operation used to get the first and second digits of nominal resistance. it is (10).
		*/
		static const int k_mod_divisor;
		
		/*!
		\brief The ten significant digits of resistance bands, these determine the first and second digits of nominal resistance. Which ranges from 0 to 9.
		*/
		static const int k_resistor_digit_zero;
		static const int k_resistor_digit_one;
		static const int k_resistor_digit_two;
		static const int k_resistor_digit_three;
		static const int k_resistor_digit_four;
		static const int k_resistor_digit_five;
		static const int k_resistor_digit_six;
		static const int k_resistor_digit_seven;
		static const int k_resistor_digit_eight;

		/*!
			\brief The multiplier values, which range from 10^0 to 10^-2
		*/
		static const double k_multiplier_zero;
		static const double k_multiplier_one;
		static const double k_multiplier_two;
		static const double k_multiplier_three;
		static const double k_multiplier_four;
		static const double k_multiplier_five;
		static const double k_multiplier_six;
		static const double k_multiplier_seven;
		static const double k_multiplier_eight;
		static const double k_multiplier_nine;
		static const double k_multiplier_neg_one;

		/*!
			\brief The tolerance values, the values are +/-1%, +/-2%, +/-0.5%, +/-0.25%, +/-0.1%, +/-0.05%, +/-5%, +/-10%, +/-20%,
		*/
		static const double k_tolerance_one;
		static const double k_tolerance_two;
		static const double k_tolerance_three;
		static const double k_tolerance_four;
		static const double k_tolerance_five;
		static const double k_tolerance_six;
		static const double k_tolerance_seven;
		static const double k_tolerance_eight;

		/*!
		\brief Creates an instance of the resistor with specified nominal resistance, multiplier and tolerance values.
		\param nominal resistance -nominal resistance value  of the resistor
				multiplier- multiplier value of the resistor of this instancce.
				tolerance- tolerance value of this instance.
		*/
		resistor(const double nominal_resistance = 0.0, const double multiplier = 0.0, const double tolerance = 0.0);

		/*!
		\brief prints output stream to the console
		\param functions to print to the console 
			get_actual_resistance() ,get_description_first_band(),get_description_second_band(),get_description_multiplier(),get_description_tolerance()
		*/
		void print(std::ostream& out = std::cout) const;

		/*!
		\brief Gets the nominal resistance of this instance.
		/return The nominal resistance of this instance
		*/
		double get_nominal_resistance() const;

		/*!
			\brief Gets the tolerance of this instance
			\return The tolerancce of this instance
		*/
		double get_tolerance() const;

		/*!
			\brief Gets the actual resistance of this instance.
			calculates and returns the actual resistance of this instance, actual resitance can vary between +/- tolerance,
			here actual resistance is determined from a random value between the acceptable range
			\return returns the actual resistance of this instance.
		*/
		double get_actual_resistance() const;

		/*!
			\brief Gets the description of the first band of this instance.
				determines the color of the first band from the first digit of the nominal resistance.
			\return returns the colour of the first band of this instance.
		*/
		std::string get_description_first_band() const;

		/*!
			\brief Gets the description of the second band of this instance.
				determines the color of the second band from the second digit of the nominal resistance.
			\return returns the color of the second band of this instance.
		*/
		std::string get_description_second_band() const;

		/*!
		\brief Gets the description of the multiplier band of this instance.
			Determine the color of third band from the value of the multiplier
		\return returns the color of the third band of this instance.
		*/
		std::string get_description_multiplier() const;

		/*!
		\brief Gets the description of the tolerance band of this instance
			determines the color of the fourth band from the value of tolerance.
		\return returns the color of the fourth band of this instance.
		*/
		std::string get_description_tolerance() const;

	private:

		/*!
		\brief sets the value of nominal resistance of this instance.
		\param nominal resistance of this instance.
		*/
		void set_nominal_resistance(const double nominal_resistance);

		/*!
		\brief sets the value of multiplier of this instance.
		\param multiplier of this instance.
		*/
		void set_multiplier(const double multiplier);

		/*!
		\brief sets the value of tolerance of this instance.
		\param tolerance of this instance.
		*/
		void set_tolerance(const double tolerance);

		/*!
		\brief The nominal resistance of this instance
			nominal resistance is the resistance value determined from the first two significant digits.
		*/
		double nominal_resistance_;
		/*!
		\brief The multiplier of this instance
			multiplier is defined as the value multiplied to the first two significant digits to determine the resistance
		*/
		double multiplier_;
		/*!
		\brief The tolerance of this instance
			Tolerance indicates the acceptable variation in the resistance.
		*/
		double tolerance_;
	};

}

#endif
