#include "melodias.h" 

void Sound_play(uint32_t frec,uint32_t dura)
{
	uint32_t dela=500000/frec;//  la mitad de un mega
	uint32_t  repe=frec*dura/1000;// calcula cuantas veces se repite

		while(repe--)
	  {
	HAL_GPIO_WritePin(PAR_GPIO_Port, PAR_Pin,1);
	delay_us_dwt(dela);
	  HAL_GPIO_WritePin(PAR_GPIO_Port, PAR_Pin,0);
	  delay_us_dwt(dela);
      }

}

void tetris()
{
    // Frase 1
    Sound_play(659, 300);  // MI5
    Sound_play(494, 150);  // SI4
    Sound_play(523, 150);  // DO5
    Sound_play(587, 300);  // RE5
    Sound_play(523, 150);  // DO5
    Sound_play(494, 150);  // SI4

    Sound_play(440, 300);  // LA4
    Sound_play(440, 150);  // LA4
    Sound_play(523, 150);  // DO5
    Sound_play(659, 300);  // MI5
    Sound_play(587, 150);  // RE5
    Sound_play(523, 150);  // DO5

    Sound_play(494, 300);  // SI4
    Sound_play(523, 150);  // DO5
    Sound_play(587, 300);  // RE5
    Sound_play(659, 300);  // MI5

    Sound_play(523, 300);  // DO5
    Sound_play(440, 300);  // LA4
    Sound_play(440, 600);  // LA4

    // Frase 2
    Sound_play(587, 450);  // RE5 (con puntillo)
    Sound_play(698, 150);  // FA5
    Sound_play(880, 300);  // LA5
    Sound_play(784, 150);  // SOL5
    Sound_play(698, 150);  // FA5

    Sound_play(659, 450);  // MI5 (con puntillo)
    Sound_play(523, 150);  // DO5
    Sound_play(659, 300);  // MI5
    Sound_play(587, 150);  // RE5
    Sound_play(523, 150);  // DO5

    Sound_play(494, 300);  // SI4
    Sound_play(494, 150);  // SI4
    Sound_play(523, 150);  // DO5
    Sound_play(587, 300);  // RE5
    Sound_play(659, 300);  // MI5

    Sound_play(523, 300);  // DO5
    Sound_play(440, 300);  // LA4
    Sound_play(440, 600);  // LA4

    // Puente
    Sound_play(587, 600);  // RE5
    Sound_play(698, 300);  // FA5
    Sound_play(880, 600);  // LA5
    Sound_play(784, 300);  // SOL5
    Sound_play(698, 300);  // FA5

    Sound_play(659, 450);  // MI5
    Sound_play(523, 150);  // DO5
    Sound_play(659, 600);  // MI5
    Sound_play(587, 300);  // RE5

    Sound_play(523, 300);  // DO5
    Sound_play(494, 300);  // SI4

    Sound_play(523, 300);  // DO5
    Sound_play(587, 300);  // RE5
    Sound_play(659, 600);  // MI5

    Sound_play(523, 600);  // DO5
    Sound_play(440, 600);  // LA4
    Sound_play(440, 600);  // LA4
}

void cielitolindo()
{
    // De la Sierra Morena
    Sound_play(523, 350);   // DO5
    Sound_play(523, 250);   // DO5
    Sound_play(440, 250);   // LA4
    Sound_play(494, 250);   // SI4
    Sound_play(392, 400);   // SOL4


    // Cielito lindo vienen bajando
    Sound_play(523, 250);   // DO5
    Sound_play(523, 250);   // DO5
    Sound_play(440, 250);   // LA4
    Sound_play(494, 250);   // SI4
    Sound_play(392, 500);   // SOL4


    // Un par de ojitos negros
    Sound_play(523, 250);   // DO5
    Sound_play(523, 250);   // DO5
    Sound_play(440, 350);   // LA4
    Sound_play(494, 250);   // SI4
    Sound_play(392, 250);   // SOL4
    Sound_play(349, 250);   // FA4
    Sound_play(294, 500);   // RE4


    // Cielito lindo de contrabando
    Sound_play(494, 250);   // SI4
    Sound_play(494, 250);   // SI4
    Sound_play(494, 250);   // SI4
    Sound_play(494, 250);   // SI4
    Sound_play(440, 250);   // LA4
    Sound_play(349, 250);   // FA4
    Sound_play(294, 250);   // RE4
    Sound_play(294, 250);   // RE4
    Sound_play(330, 250);   // MI4

    Sound_play(349, 250);   // FA4
    Sound_play(392, 250);   // SOL4
    Sound_play(392, 250);   // SOL4
    Sound_play(392, 250);   // SOL4
    Sound_play(349, 250);   // FA4
    Sound_play(330, 250);   // MI4
    Sound_play(294, 250);   // RE4
    Sound_play(262, 600);   // DO4


    // ¡Ay, ay, ay, ay!
    Sound_play(659, 500);   // MI5
    Sound_play(587, 300);   // RE5
    Sound_play(523, 250);   // DO5
    Sound_play(440, 600);   // LA4


    // Canta y no llores
    Sound_play(587, 350);   // RE5
    Sound_play(587, 200);   // RE5
    Sound_play(523, 200);   // DO5
    Sound_play(659, 300);   // MI5
    Sound_play(523, 500);   // DO5


    // Porque cantando se alegran
    Sound_play(392, 250);   // SOL4
    Sound_play(440, 300);   // LA4
    Sound_play(392, 250);   // SOL4
    Sound_play(440, 250);   // LA4
    Sound_play(440, 250);   // LA4
    Sound_play(392, 250);   // SOL4
    Sound_play(698, 300);   // FA5
    Sound_play(698, 300);   // FA5


    // Cielito lindo, los corazones
    Sound_play(587, 350);   // RE5
    Sound_play(494, 250);   // SI4
    Sound_play(392, 250);   // SOL4
    Sound_play(440, 300);   // LA4
    Sound_play(440, 250);   // LA4
    Sound_play(392, 250);   // SOL4
    Sound_play(349, 250);   // FA4
    Sound_play(330, 250);   // MI4
    Sound_play(294, 250);   // RE4
    Sound_play(262, 600);   // DO4
}