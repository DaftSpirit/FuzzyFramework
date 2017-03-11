// ModeleFLou.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Lib.h"

void test_main()
{
	fuzzy::NotMinus<double> opNot;
	fuzzy::AndMin<double> opAnd;
	fuzzy::OrMax<double> opOr;
	fuzzy::ThenMin<double> opThen;
	fuzzy::CogDefuzz<double> opDefuzz(0, 30, 1);
	fuzzy::AggMax<double> opAgg;

	fuzzy::FuzzyFactory<double> f(&opAnd, &opOr, &opThen, &opAgg, &opDefuzz, &opNot);

	fuzzy::IsTriangle<double> poor(-5, 0, 5);
	fuzzy::IsTriangle<double> good(0, 5, 10);
	fuzzy::IsTriangle<double> excellent(5, 10, 15);

	fuzzy::IsTriangle<double> cheap(0, 5, 10);
	fuzzy::IsTriangle<double> average(10, 15, 20);
	fuzzy::IsTriangle<double> generous(20, 25, 30);

	core::ValueModel<double> service(0);
	core::ValueModel<double> food(0);
	core::ValueModel<double> tips(0);

	core::Expression<double>* r =
		f.newAgg(
		f.newAgg(
		f.newThen(
		f.newIs(&service, &poor),
		f.newIs(&tips, &cheap)
		),
		f.newThen(
		f.newIs(&service, &good),
		f.newIs(&tips, &average)
		)
		),
		f.newThen(
		f.newIs(&service, &excellent),
		f.newIs(&tips, &generous)
		)
		);

	core::Expression<double>* system = f.newDefuzz(&tips, r);

	double s;
	while (true)
	{
		std::cout << "service : "; std::cin >> s;
		service.setValue(s);
		std::cout << "tips  : " << system->evaluate() << std::endl;
	}
}

void chauffageMain()
{
	NotMinus opNot;
	AndMin opAnd;
	OrMax opOr;
	ThenMin opThen;
	CogDefuzz opDefuzz(0, 30, 1);
	AggMax opAgg;

	Factory f(&opAnd, &opOr, &opThen, &opAgg, &opDefuzz, &opNot);

	IsTriangle poor(-5, 0, 5);
	IsTriangle medium(0, 5, 10);
	IsTriangle high(5, 10, 15);

	IsTriangle weak(0, 5, 10);
	IsTriangle strong(5, 10, 15);

	IsTriangle cold(0, 5, 10);
	IsTriangle warm(10, 15, 20);
	IsTriangle hot(20, 25, 30);

	Value isolation(0);
	Value chauffage(0);
	Value chaleur(0);

	Expression* r =
		f.newAgg(f.newAgg(f.newAgg(f.newAgg(f.newAgg(
			f.newThen(f.newAnd(f.newIs(&isolation, &poor), f.newIs(&chauffage, &weak)), f.newIs(&chaleur, &cold)), 
			f.newThen(f.newAnd(f.newIs(&isolation, &poor), f.newIs(&chauffage, &strong)), f.newIs(&chaleur, &warm))),
			f.newThen(f.newAnd(f.newIs(&isolation, &medium), f.newIs(&chauffage, &weak)), f.newIs(&chaleur, &warm))),
			f.newThen(f.newAnd(f.newIs(&isolation, &medium), f.newIs(&chauffage, &strong)), f.newIs(&chaleur, &hot))),
			f.newThen(f.newAnd(f.newIs(&isolation, &high), f.newIs(&chauffage, &weak)), f.newIs(&chaleur, &hot))),
			f.newThen(f.newAnd(f.newIs(&isolation, &high), f.newIs(&chauffage, &strong)), f.newIs(&chaleur, &hot)));

	Expression* system = f.newDefuzz(&chaleur, r);

	double i, c;
	while (true)
	{
		std::cout << "Isolation : "; std::cin >> i;
		std::cout << "Chauffage : "; std::cin >> c;
		isolation.setValue(i);
		chauffage.setValue(c);
		std::cout << "Chaleur  : " << system->evaluate() << std::endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	chauffageMain();
	return 0;
}