//#include <iostream>
//
//double ar_counting(int quant_windows, int quant_doors, double x, double y)
//{
//	double windoow_ar = 2.15 * 1.5;
//	double door_ar = 0.9 * 2.05;
//	return (2.6 * x + 2.6 * y - windoow_ar * quant_windows - door_ar * quant_doors);
//}
//
//double tube_quant_counting(double area)
//{
//	return (area + (0.5 * 10 * 0.9)) / (0.5 * 10);
//}
//
//double all_tubs_cost(int quant_tube, double cost_tube)
//{
//	return quant_tube * cost_tube;
//}
//
//double all_cost_counting(double cost_wp, int quant_tube, double cost_tube)
//{
//	double kl_cost = 2.5;
//	int kl_res = 5;
//	return (((quant_tube + kl_res - 1) / kl_res) * kl_cost) + quant_tube * cost_tube;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//
//	double x = 0, y = 0;
//	int quant_windows = 0, quant_doors = 0;
//	double cost_tube = 0, area = 0, cost_allwp = 0, cost_wp = 0;
//	int quant_tube = 0;
//
//	
//	int in = 1;
//	area = ar_counting(quant_windows, quant_doors, x, y);
//	quant_tube = tube_quant_counting(area);
//	cost_allwp = all_tubs_cost(quant_tube, cost_wp);
//	while (in != 7)
//	{
//		switch (in)
//		{
//		case 1: 
//			printf_s("Enter room size: ");
//			scanf_s("%lf %lf", &x, &y);
//			break;
//		case 2:
//			printf_s("Enter quantity of doors and windows: ");
//			scanf_s("%d %d", &quant_doors, &quant_windows);
//			break;
//		case 3:
//			printf_s("Tube price");
//			scanf_s("%f", &cost_tube);
//			break;
//		case 4:
//			printf_s("Pasting area: ");
//			scanf_s("%f", &area);
//			break;
//		case 5:
//			printf_s("Pasting cost: ");
//			scanf_s("%f", &cost_tube);
//		}
//
//	}
//	printf("Quantety of tubes: %d", quant_tube);
//
//}
//
//
//
////1000-7zxc