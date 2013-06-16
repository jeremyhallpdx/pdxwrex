using System;
namespace RectangleApplication
{
	class Rectangle
	{
		int length;
		int width;
		public void acceptDetails()
		{
			Console.WriteLine();
			Console.WriteLine("Please enter the Rectangles Length in INCHES: ");
			length = Convert.ToInt32(Console.ReadLine());
			Console.WriteLine("Please enter the Rectangle's Width in INCHES: ");
			width = Convert.ToInt32(Console.ReadLine());
		}
		public int getArea()
		{
			return length * width;
		}
		public void displayDetails()
		{
			Console.WriteLine ("The area of the rectangle is: ");
			Console.WriteLine ("Length: {0}", length);
			Console.WriteLine ("Width:  {0}", width);
			Console.WriteLine ("Area:  {0}", getArea());
		}
	}
	class executeRectangle
	{
		static void Main (string[] args)
		{
			Rectangle r = new Rectangle();
			r.acceptDetails();
			r.displayDetails();
			Console.ReadLine();
		}
	}
}	