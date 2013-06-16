using System;
namespace VariableDeclaration
{
	class Program
	{
		static void Main(string[] args)
		{
			short a = 10;
			int b = 20;
			double c = a + b;
			
			Console.WriteLine("a = {0}, b = {1}, c = {2}", a, b, c);
			Console.ReadLine();
		}
	}
}