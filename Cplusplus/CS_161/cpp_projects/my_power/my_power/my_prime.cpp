bool is_prime(int num)
{
	int j;
	bool prime = true;

	for (j = 2; j < num; j++)
	{
		if (num % j == 0)
		{
			prime = false;
			break;
		}
	}
	return prime;
}