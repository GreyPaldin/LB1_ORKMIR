/*
 * displae.c
 *
 *  Created on: 14 окт. 2023 г.
 *      Author: Dmitriy
 */
#include "display.h"
extern uint8_t test;
extern P;

uint16_t cadr_cloud = 1;
uint16_t move = 0;
uint16_t point = 0;
uint16_t old_car_x = 0;
uint16_t flag = 0;
uint16_t j = 0;
uint16_t pos = 1;

int displ[16][32] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1}
};

//Функция очистки матрицы
void Clear_matrix(void){
	for (uint8_t i = 0; 4 > i; i++ ){
		for (uint8_t n = 0; 16 > n; n++ ){
			Display_Write_1(0xFF, i);
		}
	}
}

//Алгоритм вывода информации
void Display_Write_1(uint8_t pData, uint8_t s) {


	     switch(s+1){
	     		 	 case 1:
	     			 	 HAL_GPIO_WritePin(GPIOD, A_Pin, 1);
	     			 	 HAL_GPIO_WritePin(GPIOD, B_Pin, 1);
	     			 	 break;
	     		 	 case 2:
	     		 		 HAL_GPIO_WritePin(GPIOD, A_Pin, 0);
	     		 		 HAL_GPIO_WritePin(GPIOD, B_Pin, 1);
	     		 		 break;
	     		 	case 3:
	     		 		 HAL_GPIO_WritePin(GPIOD, A_Pin, 1);
	     		 		 HAL_GPIO_WritePin(GPIOD, B_Pin, 0);
	     		 		 break;
	     		 	case 4:
	     		 		 HAL_GPIO_WritePin(GPIOD, A_Pin, 0);
	     		 		 HAL_GPIO_WritePin(GPIOD, B_Pin, 0);
	     		 		 break;
	     		 }

	     HAL_GPIO_WritePin(GPIOD, OE_Pin, GPIO_PIN_RESET);
	     HAL_GPIO_WritePin(GPIOD, SCLK_Pin, GPIO_PIN_RESET);
	     HAL_SPI_Transmit(&hspi5, (uint8_t*) &pData, 1, 10);
		 HAL_GPIO_WritePin(GPIOD, SCLK_Pin, GPIO_PIN_SET);
		 HAL_GPIO_WritePin(GPIOD, OE_Pin, GPIO_PIN_SET);
}

//Алгоритм движения разметки по дороге
void Way_Run(int displ[16][32]) {
	//Определяем текущий кадр, чтобы верно сдвинуть разметку
	switch(displ[7][15]+displ[8][15]){
		case 0:
			//Был кадр 2, значит
			//Вывод кадра 3
			displ[7][15] = 1;
			displ[8][15] = 0;
			displ[9][15] = 0;
			displ[10][15] = 1;
			displ[11][15] = 0;
			displ[12][15] = 0;
			displ[13][15] = 0;
			displ[14][15] = 1;
			displ[15][15] = 1;
			break;
		case 1:
			if (displ[7][15] == 1){
				//Был кадр 3, значит
				//Вывод кадра 1
				displ[7][15] = 0;
				displ[8][15] = 1;
				displ[9][15] = 0;
				displ[10][15] = 0;
				displ[11][15] = 1;
				displ[12][15] = 1;
				displ[13][15] = 0;
				displ[14][15] = 0;
				displ[15][15] = 0;

			}
			else {
				//Вывод кадра 2
				displ[7][15] = 0;
				displ[8][15] = 0;
				displ[9][15] = 1;
				displ[10][15] = 0;
				displ[11][15] = 0;
				displ[12][15] = 1;
				displ[13][15] = 1;
				displ[14][15] = 0;
				displ[15][15] = 0;
			}
			break;

	}
}

//Положение машины с реостатом
int Callyzi_Car(void) {
	uint8_t live = 1;
	//Проверяем, была ли машина до этого или это первая итерация
	if (old_car_x != 0) {
		 flag = 1;
	}
	//Затираем прошлое положение машины, если она была
	if (flag == 1) {
		for (int i = old_car_x-1; i < old_car_x + 2; i++) {
				displ[14][i] = 1;
		}
		for (int i = old_car_x-2; i < old_car_x + 3; i++) {
					displ[15][i] = 1;
		}
	}

	//Определяем новые координаты центра машины
	uint8_t x_car = 8+move; //предел - 23, то есть move - от 0 до 16
	old_car_x = x_car;
	//Определяем координаты всей машины для дальнейшем отрисовки и проверяем, все ли свободны (кроме столбца 15)
	for (int i = x_car-1; i < x_car + 2; i++) {
		if ((displ[14][i] == 0)&(i != 15)) {
			live = 0;
		}
		displ[14][i] = 0;
	}
	for (int i = x_car-2; i < x_car + 3; i++) {
			if ((displ[15][i] == 0)&(i != 15)) {
					live = 0;
				}
			displ[15][i] = 0;
	}
	flag = 0;
	return (live);
}



//Алгоритм генеации  препятствий
void Danger_spawn(uint16_t b) {
	uint16_t Danger[44] = {0,0,0,0,0,10,11,12,13,14,0,0,0,0,0,0,0,0,0,16,17,18,0,0,0,0,0,0,11,12,0,0,15,16,0,0,0,17,0,18,0,0,0,0}; //с 9 по 14 с 16 по 21.
	displ[7][Danger[b]] = 0;
}

//Алгоритм сдвига препятсвий по экрану (тут же условие проигрышка)
int Danger_offset(void) {
	uint8_t live = 1;
	//Проверка опасных зон, если будет смещение, то окажется ли что-то на координатах машины
	uint16_t x_car = 8+move;
	if (((displ[13][x_car] == 0) || (displ[13][x_car + 1] == 0)
			|| (displ[13][x_car - 1] == 0) || (displ[14][x_car - 2] == 0)
			|| (displ[14][x_car + 2] == 0))
			& !(((x_car == 15) || (x_car + 1 == 15) || (x_car + 2 == 15)
					|| (x_car - 1 == 15) || (x_car - 2 == 15)))) {
		live = 0;
		return (live);
	}
	//Алгоритм сдвига всех препядствий
	for (int i = 15; i >= 7; i--) {
			for (int j = 9; j < 22; j++) {
				if ((displ[i][j] == 0)&(j != 15)) {
					displ[i][j] = 1;
					if (i+1 < 16) {
						displ[i+1][j] = 0;
						point++;
					}
				}
			}
	}
	return(live);
}

//Отображение матрицы значений на дисплеии
void Show_matrix( int displ[16][32] ){
	//Очистка экрана
	Clear_matrix();
	//Матрица для байтов
	int bytesMatrix[16][4] = {
	        {0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}};



	//Алгоритм сборки байтовой матрицы
	for (int i = 0; i < 16; i++) {
	        for (int j = 0; j < 4; j++) {
	            uint8_t byte = 0;
	            for (int k = 0; k < 8; k++) {
	                // Собираем байт из битов, начиная с самого младшего
	            	byte |= (displ[i][j * 8 + k] << (7-k)); //лучший преобразователь
	            }
	            bytesMatrix[i][j] = byte;
	        }
	}


	//Алгоритм выгрузки байтов на экран.
	for (uint8_t n = 0; 4 > n; n++ ) {
		for (int x = 0; x < 4; x++){
			for (int y = 15-n; y > -1; y = y-(4)){
		        	Display_Write_1(bytesMatrix[y][x],n);

		        }
		     }
	HAL_Delay(1);
	Clear_matrix();
	}
}

//Проверка на касание машиной препядствия
void Game_Over() {
	for (int i = old_car_x-1; i < old_car_x + 2; i++) {
					displ[14][i] = 1;
			}
			for (int i = old_car_x-2; i < old_car_x + 3; i++) {
						displ[15][i] = 1;
			}
	int displ_over[16][32] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	uint16_t a = 1000;
	while (a > 2) {
		Show_matrix(displ_over);
		a--;
	}

}

//Функция смещения элементов окружения вдоль дороги
//(возможно будет однажды (смена кадров или реализовать смешение векторов))

//Функция движения облаков
void Cloud_2(int cadr_prov) {
	switch(cadr_prov){

	case(1):
		//Чистка прошлой области_2 с кадра 4
		j = 1;
		for (int i = 19; i < 30; i++) {
			displ[j][i] = 1;
		}
		for (int i = 18; i < 32; i++) {
			displ[j - 1][i] = 1;
		}
		//Отрисовка нового облака_2 кадра 1
		j = 6;
		for (int i = 22; i < 30; i++) {
			displ[j][i] = 0;
		}
		for (int i = 23; i < 28; i++) {
			displ[j-1][i] = 0;
		}
		//Затирание  облака_1 на кадре 2
		j = 4;
		for (int i = 3; i < 5; i++) {
			displ[j][i] = 1;
		}
		for (int i = 2; i < 6; i++) {
			displ[j - 1][i] = 1;
		}
		for (int i = 2; i < 8; i++) {
			displ[j - 2][i] = 1;
		}
		//Отрисовка облака_1 на кадре 3
		j = 3;
		for (int i = 0; i < 10; i++) {
			displ[j][i] = 0;
		}
		for (int i = 1; i < 8; i++) {
			displ[j - 1][i] = 0;
		}
		for (int i = 2; i < 6; i++) {
			displ[j - 2][i] = 0;
		}
		for (int i = 2; i < 5; i++) {
			displ[j - 3][i] = 0;
		}
		break;

	case(2):
		//Чистка прошлой области_2 с кадра 1
		j = 6;
		for (int i = 22; i < 30; i++) {
				displ[j][i] = 1;
		}
		for (int i = 23; i < 28; i++) {
				displ[j-1][i] = 1;
		}

		//Отрисовка нового облака_2 кадра 2
		j = 4;
		for (int i = 21; i < 31; i++) {
			displ[j][i] = 0;
		}
		for (int i = 22; i < 29; i++) {
			displ[j-1][i] = 0;
		}
		for (int i = 23; i < 28; i++) {
					displ[j-2][i] = 0;
		}
		//Чистка облака_1 с кадре 3
		j = 3;
		for (int i = 0; i < 10; i++) {
			displ[j][i] = 1;
		}
		for (int i = 1; i < 8; i++) {
			displ[j - 1][i] = 1;
		}
		for (int i = 2; i < 6; i++) {
			displ[j - 2][i] = 1;
		}
		for (int i = 2; i < 5; i++) {
			displ[j - 3][i] = 1;
		}
		//Отрисовка облака_1 с кадре 4
		j = 1;
		for (int i = 0; i < 12; i++) {
				displ[j][i] = 0;
		}
		for (int i = 0; i < 10; i++) {
			    displ[j-1][i] = 0;
		}
		break;

	case(3):
		//Чистка прошлой области_2 с кадра 2
		j = 4;
		for (int i = 21; i < 31; i++) {
			displ[j][i] = 1;
		}
		for (int i = 22; i < 29; i++) {
			displ[j-1][i] = 1;
		}
		for (int i = 23; i < 28; i++) {
			displ[j-2][i] = 1;
		}

		//Отрисовка нового облака_2 кадра 3
		j = 3;
		for (int i = 18; i < 32; i++) {
			displ[j][i] = 0;
		}
		for (int i = 19; i < 30; i++) {
			displ[j-1][i] = 0;
		}
		for (int i = 20; i < 28; i++) {
					displ[j-2][i] = 0;
				}
		for (int i = 22; i < 28; i++) {
					displ[j-3][i] = 0;
				}
		//Чистка прошлой области_1 с кадра 4
		j = 1;
		for (int i = 0; i < 12; i++) {
			displ[j][i] = 1;
		}
		for (int i = 0; i < 10; i++) {
			displ[j - 1][i] = 1;
		}
		//Орисовка нового облака_1 кадр 1
		j = 6;
		for (int i = 2; i < 7; i++) {
			displ[j][i] = 0;
		}
		for (int i = 3; i < 5; i++) {
			displ[j - 1][i] = 0;
		}
		break;

	case(4):
		//Затирание прошлого облака_2 кадр 3
		j = 3;
		for (int i = 18; i < 32; i++) {
			displ[j][i] = 1;
		}
		for (int i = 19; i < 30; i++) {
			displ[j - 1][i] = 1;
		}
		for (int i = 20; i < 28; i++) {
			displ[j - 2][i] = 1;
		}
		for (int i = 22; i < 28; i++) {
			displ[j - 3][i] = 1;
		}
		//Отрисовка облака_2 кадра 4
		j = 1;
		for (int i = 19; i < 30; i++) {
			displ[j][i] = 0;
		}
		for (int i = 18; i < 32; i++) {
			displ[j - 1][i] = 0;
		}
		//Затирание облака_1 с кадра 1
		j = 6;
		for (int i = 2; i < 7; i++) {
			displ[j][i] = 1;
		}
		for (int i = 3; i < 5; i++) {
			displ[j - 1][i] = 1;
		}

		//Отрисовка облака_1 на кадре 2
		j = 4;
		for (int i = 3; i < 5; i++) {
			displ[j][i] = 0;
		}
		for (int i = 2; i < 6; i++) {
			displ[j - 1][i] = 0;
		}
		for (int i = 2; i < 8; i++) {
			displ[j - 2][i] = 0;
		}
	}

}

void Display_Test(uint8_t a, uint8_t b) {
	Show_matrix(displ);
	if (a == 16) {
		Way_Run(displ);
		Cloud_2(cadr_cloud);
		//Счётчик кадров облаокв и задержка вывода ( смещение должно быть медленее, чем дви
		//жение дорожной разметки)
		if (pos == 4){
			pos = 0;
			if (cadr_cloud == 4) {
					cadr_cloud = 1;
			}
			else {
				cadr_cloud++;
			}
		}
		pos++;
		Danger_spawn(b);
		Callyzi_Car();
		if ((Danger_offset() == 0)||(Callyzi_Car() == 0)){
			Game_Over();
			displ[16][32] = {
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1}
			};
			move = 0;
			flag = 0;
			old_car_x = 0;
		}
	}
}