using System;
namespace ForLoops
{
	class Program
	{
		static void Main(string[] args)
		{
			for (int a = 10; a < 20; a = a + 1)
			{
				Console.WriteLine("The Value of A: {0}", a);
			}
			Console.ReadLine();
		}
	}
}