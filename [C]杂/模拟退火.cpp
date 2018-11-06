void Simulate_Annealing()
{
	data p = getRandomData();
	double val = getval(p);
	for (int T = 19260817; T > 1e-6; T = T * 0.998244353)
	{
		data newp = turbulent(p);
		double newval = getval(newp);
		if (newval > val || get01withp(exp(-val / T))
			p = newp;
	}
}
