using System;
namespace RelationalOperators
{
	class Program
	{
		static void Main(string[] args)
		{
			int a = 21;
			int b = 10;
			
			if(a == b)
			{
				Console.WriteLine("Line 1 - A is equal to B");
			}
			else
			{
				Console.WriteLine("Line 1 - A is not equal to B");
			}
			if(a < b)
			{
				Console.WriteLine("Line 2 - A is less than B");
			}
			else
			{
				Console.WriteLine("Line 2 - A is not less than B");
			}
			if(a > b)
			{
				Console.WriteLine("Line 3 - A is greater than B");
			}
			else
			{
				Console.WriteLine("Line 3 - A is not greater than B");
			}
			a = 25;
			b = 20;
			
			if(a <= b)
			{
				Console.WriteLine("Line 4 - A is less than or equal to B");
			}
			else
			{
				Console.WriteLine("Line 4 - A is greather than or equal to B");
			}
		}
	}
}