/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:38:46 by samartin          #+#    #+#             */
/*   Updated: 2023/02/08 13:27:10 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * It returns the result of raising a base to a positive integer power
 * 
 * @param base the base number
 * @param exp The exponent to raise the base to.
 * 
 * @return The result of the base to the power of exp.
 */
int	ft_int_pos_pow(int base, int exp)
{
	int	result;

	result = 1;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		base *= base;
		exp >>= 1;
	}
	return (result);
}

/**
 * It uses binary search to find the square root of a positive integer
 * 
 * @param n the number to find the square root of
 * 
 * @return The square root of the number.
 */
int	ft_int_sqrt(unsigned int n)
{
	unsigned int	sqrtn;
	unsigned int	low_ap;
	unsigned int	high_ap;

	if (n <= 0)
		return (0);
	else if (n == 1)
		return (1);
	else
	{
		low_ap = 1;
		high_ap = n / 2;
		while (low_ap <= high_ap)
		{
			sqrtn = (low_ap + high_ap) / 2;
			if (sqrtn * sqrtn <= n && (sqrtn + 1) * (sqrtn + 1) > n)
				return (sqrtn);
			else if (sqrtn * sqrtn < n)
				low_ap = sqrtn + 1;
			else
				high_ap = sqrtn - 1;
		}
	}
	return (-1);
}

/**
 * It checks if a number is prime by checking if it's divisible by any odd
 * number between 3 and the square root of the number. Division by 2 is
 * priorly checked to skip all evens. Numbers greater than the square root
 * of the given one are never an exclusive divisor of a divisible number.
 * 
 * @param n the number to check if it's prime
 * 
 * @return 1 if the number is prime, 0 if it is not.
 */
int	ft_is_prime(int n)
{
	unsigned int	i;
	unsigned int	sq_n;

	if (n <= 1)
		return (0);
	if (n % 2 == 0 && n > 2)
		return (0);
	i = 3;
	sq_n = (unsigned int)ft_int_sqrt(n);
	while (i <= sq_n)
	{
		if ((n % i) == 0)
			return (0);
		i += 2;
	}
	return (1);
}

/**
 * ft_abs() returns the absolute value of n.
 * 
 * @param n The number to be converted.
 * 
 * @return The absolute value of the number.
 */
unsigned int	ft_abs(long n)
{
	if (n < 0)
		return ((unsigned int)(n * -1));
	else
		return ((unsigned int)n);
}
